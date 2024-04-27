#ifndef EP_CLI_H
#define EP_CLI_H

struct ep_cli_args {
    const char* src_file;
};

void parse_cli_args(int argc, char* argv[], struct ep_cli_args* cli_args);

#endif // EP_CLI_H
