#include <iostream>
#include <string>
#include "args.h"
#include "motor.h"
#include "serial.h"

int main(int argc, char ** argv)
{
    cli_args_t a;
    parse_args(argc, argv, a);

    Serial ser;
    if (a.port) ser.connect(a.port, a.baud);
    else        ser.autoconnect(a.baud);

    Motor mot(a.addr, &ser);

    if (a.recalibrate)
    {
        printf("Placeholder: recalibrate\n");
    }
    if (a.restart)
    {
        printf("Placeholder: restart\n");
    }
    if (a.bootload)
    {
        printf("Placeholder: bootload\n");
    }
    if (a.rezero)
    {
        printf("Placeholder: rezero\n");
    }
    if (a.set_mode)
    {
        printf("Placeholder: set-mode %d\n", a.mode);
    }
    if (a.read_angle)
    {
        printf("Placeholder: read-angle\n");
    }
    if (a.read_current)
    {
        printf("Placeholder: read-current\n");
    }
    if (a.set_cmd)
    {
        printf("Placeholder: set-cmd %d\n", a.cmd);
    }
    return 0;
}
