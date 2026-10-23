#ifndef MOTOR_CLI_ARGS_H
#define MOTOR_CLI_ARGS_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    /* required positional */
    unsigned char addr;

    /* comms options */
    const char *  port;         /* --port, NULL = autoconnect */
    unsigned long baud;         /* --baud, default 921600 */

    /* motor commands */
    bool recalibrate;
    bool restart;
    bool bootload;
    bool rezero;
    bool set_mode;
    uint8_t mode;               /* --set-mode <n> */
    bool read_angle;
    bool read_current;
    bool set_cmd;
    int32_t cmd;                /* --set-cmd <n> */
} cli_args_t;

void parse_args(int argc, char ** argv, cli_args_t & args);

#endif
