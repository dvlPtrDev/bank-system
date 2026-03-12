#ifndef FILE_H
#define FILE_H

#include <stdbool.h>
#include <stdio.h>

FILE *open_file(str filename, str modes);
mut_str read_file(FILE *fp, size_t bytes_to_alloc);
bool close_file(FILE *fp);

#endif