#ifndef EP_IO_H
#define EP_IO_H

#include "ep_errors.h"
#include <stdio.h>

struct ep_io_data {
    const char* filename;
    FILE* file_handle;
    const char* file_data;
};

enum ep_error open_elf_file(const char* filename, struct ep_io_data** io_data);

#endif // EP_IO_H
