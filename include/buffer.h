#ifndef BUFFER_H
#define BUFFER_H

#include <stdio.h>
#include <fcntl.h>
#include <io.h>

#define MIN_SIZE        64

typedef struct {
    char *buffer;
    unsigned int mem_cap;
    unsigned int size;
}   FileBuffer;

extern FileBuffer file_reader;

int get_line(int fd);
int start_buffer(void);
void free_buffer(void);

#endif