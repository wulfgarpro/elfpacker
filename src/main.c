#include "ep_cli.h"

int main(int argc, char* argv[])
{
    struct ep_cli_args cli_args = { 0 };
    parse_cli_args(argc, argv, &cli_args);
    return 0;
}
