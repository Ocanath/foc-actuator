#include "args.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void print_help(const char * prog)
{
    printf(
        "Usage: %s <addr> [--port <port>] [--baud <rate>] <command> [arg]\n"
        "\n"
        "  addr                DARTT device address (0-255)\n"
        "\n"
        "Comms options:\n"
        "  --port <port>       Serial port (e.g. /dev/ttyUSB0, COM3); autoconnects if omitted\n"
        "  --baud <rate>       Baud rate (default 921600)\n"
        "\n"
        "Motor commands:\n"
        "  --recalibrate       Run motor autocalibration routine\n"
        "  --restart           Restart motor firmware\n"
        "  --bootload          Enter bootloader mode\n"
        "  --rezero            Set current position as zero\n"
        "  --set-mode <n>      Set control mode (0=FOC, 1=SIN, 2=PCTL_IQ, 3=PCTL_VQ, 4=OL, 5=PHASE, 6=NONE)\n"
        "  --read-angle        Print rotor angle\n"
        "  --read-current      Print phase current\n"
        "  --set-cmd <n>       Write command word\n"
        "\n"
        "  -h, --help          Print this help and exit\n",
        prog
    );
}

static void die(const char * msg)
{
    fprintf(stderr, "error: %s\n", msg);
    exit(1);
}

static unsigned long parse_ulong(const char * s, const char * name)
{
    char * end;
    unsigned long v = strtoul(s, &end, 0);
    if (*end != '\0')
    {
        fprintf(stderr, "error: invalid value for %s: '%s'\n", name, s);
        exit(1);
    }
    return v;
}

static long parse_long(const char * s, const char * name)
{
    char * end;
    long v = strtol(s, &end, 0);
    if (*end != '\0')
    {
        fprintf(stderr, "error: invalid value for %s: '%s'\n", name, s);
        exit(1);
    }
    return v;
}

void parse_args(int argc, char ** argv, cli_args_t & args)
{
    if (argc < 2)
    {
        print_help(argv[0]);
        exit(1);
    }

    memset(&args, 0, sizeof(args));
    args.baud = 921600;

    bool has_addr = false;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            print_help(argv[0]);
            exit(0);
        }
        else if (strcmp(argv[i], "--port") == 0)
        {
            if (i + 1 >= argc) die("'--port' requires a port argument");
            args.port = argv[++i];
        }
        else if (strcmp(argv[i], "--baud") == 0)
        {
            if (i + 1 >= argc) die("'--baud' requires a value argument");
            args.baud = parse_ulong(argv[++i], "--baud");
        }
        else if (strcmp(argv[i], "--recalibrate") == 0) { args.recalibrate  = true; }
        else if (strcmp(argv[i], "--restart")     == 0) { args.restart      = true; }
        else if (strcmp(argv[i], "--bootload")    == 0) { args.bootload     = true; }
        else if (strcmp(argv[i], "--rezero")      == 0) { args.rezero       = true; }
        else if (strcmp(argv[i], "--read-angle")  == 0) { args.read_angle   = true; }
        else if (strcmp(argv[i], "--read-current")== 0) { args.read_current = true; }
        else if (strcmp(argv[i], "--set-mode") == 0)
        {
            if (i + 1 >= argc) die("'--set-mode' requires a mode argument");
            unsigned long v = parse_ulong(argv[++i], "--set-mode");
            if (v > 255) { fprintf(stderr, "error: mode '%s' out of range\n", argv[i]); exit(1); }
            args.mode = (uint8_t)v;
            args.set_mode = true;
        }
        else if (strcmp(argv[i], "--set-cmd") == 0)
        {
            if (i + 1 >= argc) die("'--set-cmd' requires a value argument");
            args.cmd = (int32_t)parse_long(argv[++i], "--set-cmd");
            args.set_cmd = true;
        }
        else if (argv[i][0] == '-')
        {
            fprintf(stderr, "error: unknown option '%s'\n", argv[i]);
            exit(1);
        }
        else if (!has_addr)
        {
            unsigned long v = parse_ulong(argv[i], "addr");
            if (v > 255)
            {
                fprintf(stderr, "error: address '%s' out of range (0-255)\n", argv[i]);
                exit(1);
            }
            args.addr = (unsigned char)v;
            has_addr = true;
        }
        else
        {
            fprintf(stderr, "error: unexpected argument '%s'\n", argv[i]);
            exit(1);
        }
    }

    if (!has_addr) die("address is required as the first argument");
}
