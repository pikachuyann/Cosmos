project(Cosmos)

cmake_minimum_required (VERSION 3.3.1)

find_package(BISON)
find_package(FLEX)
find_package(EXPAT)
find_package(GIT)
find_package(BOOST)

set (CMAKE_CXX_STANDARD 11)

EXECUTE_PROCESS(
COMMAND ${GIT_EXECUTABLE} describe --abbrev=6 --dirty --always --tags
OUTPUT_VARIABLE GIT_REVISION
OUTPUT_STRIP_TRAILING_WHITESPACE
)

ADD_DEFINITIONS(
    -O3
    -DGIT_REVISION=\"${GIT_REVISION}\"
)


file(GLOB_RECURSE grml_SOURCES "src/libgrml/*.cc")
add_library(grml ${grml_SOURCES})


add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/Eval/Eval-parser.cc ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/Eval/Eval-scanner.cc
COMMAND ${FLEX_EXECUTABLE} -o Eval-scanner.cc --prefix=eval Eval-scanner.ll
COMMAND ${BISON_EXECUTABLE} -o Eval-parser.cc -y -p eval Eval-parser.yy
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/Eval")

add_custom_command( OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/GspnParser/Gspn-scanner.hh ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/GspnParser/Gspn-parser.hh
COMMAND ${FLEX_EXECUTABLE} -o Gspn-scanner.cc --prefix=gspn Gspn-scanner.ll
COMMAND ${BISON_EXECUTABLE} -o Gspn-parser.cc -y -p gspn Gspn-parser.yy
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/GspnParser")

add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/LhaParser/Lha-scanner.cc ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/LhaParser/Lha-parser.cc
COMMAND ${FLEX_EXECUTABLE} -o Lha-scanner.cc --prefix=lha Lha-scanner.ll
COMMAND ${BISON_EXECUTABLE} -o Lha-parser.cc -y -p lha Lha-parser.yy
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/LhaParser")

file(GLOB_RECURSE Cosmos_SOURCES "src/ModelGenerator/*.cpp" "src/ModelGenerator/*.cc" "src/libgrml/*.cc" "src/Simulator/BatchR.cpp" )
include_directories ("src/libgrml" ${EXPAT_INCLUDE_DIR})
add_executable(Cosmos ${Cosmos_SOURCES})
target_link_libraries (Cosmos grml ${EXPAT_LIBRARY})

file(GLOB SIM_SOURCES "src/Simulator/*.cpp")
add_library(ClientSim ${SIM_SOURCES})

install(TARGETS Cosmos DESTINATION bin)
install(TARGETS ClientSim DESTINATION lib)
install(FILES "src/Simulator/spn.hpp" "src/Simulator/LHA.hpp" "src/Simulator/Marking.hpp" DESTINATION include)

add_custom_command( OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/tmp/spn.cpp ${CMAKE_CURRENT_BINARY_DIR}/tmp/LHA.cpp
DEPENDS Cosmos
#TARGET GenerateFile POST_BUILD
COMMAND Cosmos ${CMAKE_SOURCE_DIR}/Examples/Hospital/Hospital.grml --loop 100000 --tmp-status only-gen
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)


file(GLOB_RECURSE ml_SOURCES "prism2SPT/*.ml*")

add_custom_target(modelConvert ALL
${CMAKE_SOURCE_DIR}/prism2SPT/build.sh
#OUTPUT modelConvert
BYPRODUCTS ${CMAKE_SOURCE_DIR}/prism2SPT/modelConvert.native
#DEPENDS Cosmos
#TARGET modelConvert
WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/prism2SPT/
SOURCES  ${ml_SOURCES}
)


add_executable(testClientSim ${CMAKE_CURRENT_BINARY_DIR}/tmp/spn.cpp ${CMAKE_CURRENT_BINARY_DIR}/tmp/LHA.cpp)
include_directories("src/Simulator")
add_dependencies(testClientSim Cosmos)
target_link_libraries (testClientSim ClientSim)
