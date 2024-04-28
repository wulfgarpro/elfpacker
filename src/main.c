#include "ep_cli.h"
#include "ep_io.h"
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    bool err = false;

    struct ep_cli_args cli_args = { 0 };
    parse_cli_args(argc, argv, &cli_args);

    struct ep_io_data* io_data = NULL;
    err = open_elf_file(cli_args.src_file, &io_data);

    if (io_data->file_handle != NULL) {
        (void)fclose(io_data->file_handle);
    }
    free(io_data);

    return err ? EXIT_FAILURE : EXIT_SUCCESS;
}
