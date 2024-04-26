#ifndef EP_H
#define EP_H

struct cli_args {
    char* src_file;
};

void parse_cli_args(int argc, char* argv[], struct cli_args* cli_args);

#endif // EP_H
