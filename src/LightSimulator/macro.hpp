#include <string>

#define NB_EVENT 200

#define ARDUINO_SP_NAME "arduino"
#define PORT_NUMBER "27778"

#define SERIAL_BUF_SIZE 64
#define MAX_DEVICES		5
#define WAIT_TIME_INF_LOOP      4000 // In microseconds
#define TR_PL_ID unsigned char
#define REAL_TYPE float
#define NO_STRING_SIM_FALSE
#define FAST_SIM
#define CLIENT_SIM

#define uint8 uint8_t
#define uint16 uint16_t
#define uint32 uint32_t

enum SimCommands {
    SIM_NONE = 0x0, SIM_START = 0xF0, SIM_STOP = 0xF1, SIM_END = 0xF2
};