#include <stdio.h>
#include <strlib.h>
#include <memory.h>
#include <display.h>
#include <file.h>


FILE *open_file(str filename, str modes) 
{
    FILE *fp = fopen(filename, modes);
    isPointerNull(fp, true);
    return fp;
}

mut_str read_file(FILE *fp, size_t bytes_to_alloc) 
{
    mut_str buffer = allocate(NULL, bytes_to_alloc);
    int c;
    size_t i = 0; 
    while ((c = fgetc(fp)) != EOF && i < bytes_to_alloc - 1) {
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    return buffer;  
}
bool close_file(FILE *fp) 
{
    if (isPointerNull(fp, false)) {
        print("info", "Error closing file: Stream isn't open!");
        return false;
    }
    return true;
}