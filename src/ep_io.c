#include "ep_io.h"
#include "ep_errors.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
// #include <sys/mman.h>
#include <string.h>

enum ep_error open_elf_file(const char* filename, struct ep_io_data** io_data)
{
    assert(filename != NULL);
    assert(io_data != NULL);

    *io_data = malloc(sizeof(struct ep_io_data));
    if (*io_data == NULL) {
        return EP_ERROR_MALLOC_FAILED;
    }

    struct stat statbuf;
    if (stat(filename, &statbuf) == -1) {
        return EP_ERROR_STAT_FAILED;
    }

    if (!(S_ISREG(statbuf.st_mode))) {
        return EP_ERROR_NOT_IS_REG;
    }

    (*io_data)->file_handle = fopen(filename, "rb");
    if ((*io_data)->file_handle == NULL) {
        return EP_ERROR_FOPEN_FAILED;
    }

    // (*io_data)->file_data = mmap(NULL, statbuf.st_size, PROT_READ | PROT_WRITE,
    //                              MAP_PRIVATE, fileno((*io_data)->file_handle),
    //                              0);

    (*io_data)->filename = filename;

    return EP_ERROR_SUCCESS;
}
