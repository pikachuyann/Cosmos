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


add_library(grml src/libgrml/expatmodelparser.cc
		 src/libgrml/modelwriter.cc)


add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/Eval/Eval-parser.cc ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/Eval/Eval-scanner.cc
COMMAND ${FLEX_EXECUTABLE} -o Eval-scanner.cc --prefix=eval Eval-scanner.ll
COMMAND ${BISON_EXECUTABLE} -o Eval-parser.cc -y -p eval Eval-parser.yy
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/Eval")

add_custom_command( OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/GspnParser/Gspn-scanner.cc ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/GspnParser/Gspn-parser.cc
COMMAND ${FLEX_EXECUTABLE} -o Gspn-scanner.cc --prefix=gspn Gspn-scanner.ll
COMMAND ${BISON_EXECUTABLE} -o Gspn-parser.cc -y -p gspn Gspn-parser.yy
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/GspnParser")

add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/LhaParser/Lha-scanner.cc ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/LhaParser/Lha-parser.cc
COMMAND ${FLEX_EXECUTABLE} -o Lha-scanner.cc --prefix=lha Lha-scanner.ll
COMMAND ${BISON_EXECUTABLE} -o Lha-parser.cc -y -p lha Lha-parser.yy
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/LhaParser")

file(GLOB_RECURSE Cosmos_SOURCES "src/ModelGenerator/*.cpp" "src/ModelGenerator/*.cc" "src/libgrml/*.cc" "src/Simulator/BatchR.cpp" )

SET_SOURCE_FILES_PROPERTIES("src/ModelGenerator/GspnParser/Gspn-Reader.cpp" PROPERTIES OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/GspnParser/Gspn-parser.cc)
SET_SOURCE_FILES_PROPERTIES("src/ModelGenerator/Eval/Eval.cpp" PROPERTIES OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/Eval/Eval-parser.cc)
SET_SOURCE_FILES_PROPERTIES("src/ModelGenerator/LhaParser/Lha-Reader.cpp" PROPERTIES OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/ModelGenerator/LhaParser/Lha-parser.cc)

include_directories ("src/libgrml" ${EXPAT_INCLUDE_DIR})
add_executable(Cosmos
	src/Simulator/BatchR.cpp

	src/ModelGenerator/Eval/Eval-parser.cc
        src/ModelGenerator/GspnParser/Gspn-parser.cc
	src/ModelGenerator/LhaParser/Lha-parser.cc	
	src/ModelGenerator/Eval/Eval-scanner.cc
	src/ModelGenerator/GspnParser/Gspn-scanner.cc
	src/ModelGenerator/LhaParser/Lha-scanner.cc

	src/ModelGenerator/Eval/Eval.cpp

	src/ModelGenerator/GspnParser/Gspn-Grml-Output.cpp
	src/ModelGenerator/GspnParser/Gspn-Writer-Color.cpp
	src/ModelGenerator/GspnParser/Gspn-model.cpp
        src/ModelGenerator/GspnParser/unfolder.cpp
	src/ModelGenerator/GspnParser/Gspn-Reader.cpp
	src/ModelGenerator/GspnParser/Gspn-Writer.cpp
	src/ModelGenerator/GspnParser/Gspn_gmlparser.cpp

	src/ModelGenerator/LhaParser/Lha-Reader.cpp
	src/ModelGenerator/LhaParser/Lha_gmlparser.cpp

	src/ModelGenerator/Cosmos.cpp 
	src/ModelGenerator/HaslFormula.cpp
        src/ModelGenerator/expressionStruct.cpp
	src/ModelGenerator/result.cpp
	src/ModelGenerator/Generator.cpp
	src/ModelGenerator/casesWriter.cpp
	src/ModelGenerator/parameters.cpp
	src/ModelGenerator/server.cpp)

target_link_libraries (Cosmos grml ${EXPAT_LIBRARY})

add_library(ClientSim
	src/Simulator/BatchR.cpp
        src/Simulator/NLHA.cpp
        src/Simulator/SimulatorRE.cpp
        src/Simulator/numSolverSH.cpp
        src/Simulator/stateSpace.cpp	
	src/Simulator/Event.cpp
        src/Simulator/Simulator.cpp
        src/Simulator/clientsim.cpp
        src/Simulator/numericalSolver.cpp
        src/Simulator/timeGen.cpp
	src/Simulator/EventsQueue.cpp
        src/Simulator/SimulatorBoundedRE.cpp
        src/Simulator/foxglynn.cpp
	src/Simulator/LHA_orig.cpp
        src/Simulator/SimulatorContinuousBounded.cpp
	src/Simulator/numSolverBB.cpp
        src/Simulator/spn_orig.cpp
)

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

enable_testing()

add_test(NAME benchTest 
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Examples/
            COMMAND ocaml bench.ml)
set_tests_properties (benchTest 
  PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")
