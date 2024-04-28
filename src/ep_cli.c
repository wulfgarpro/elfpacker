#include "ep_cli.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

static const char* program_name = "elfpacker";
static struct option options[] = { { "src-file", required_argument, 0, 0 },
                                   { "help", optional_argument, 0, 0 },
                                   { 0, 0, 0, 0 } };

static void usage(FILE* stream)
{
    (void)fprintf(stream, "Usage: %s <options(s)> -s src-file\n", program_name);
    //(void)fprintf(stream, (" Options:\n"));
    //(void)fprintf(stream, ("  -X --XXX     XXX\n"));

    exit(stream == stdout ? 0 : 1);
}

void parse_cli_args(int argc, char* argv[], struct ep_cli_args* cli_args)
{
    int opt = 0;

    if (argc < 1) {
        usage(stderr);
    }

    while ((opt = getopt_long(argc, argv, "s:h", options, NULL)) != -1) {
        switch (opt) {
        case 's': {
            cli_args->src_file = optarg;
            break;
        }
        default: {
            usage(stderr);
        }
        }
    }

    if (!cli_args->src_file) {
        usage(stderr);
    }
}
