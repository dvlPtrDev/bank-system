#include <stdio.h>
#include <strlib.h>
#include <stdlib.h>
#include <stdarg.h>


void print(str type, str msg, ...) 
{
    va_list args;
    va_start(args, msg);

    String formatted = vformat(msg, args);

    va_end(args);
    if (string_compare("debug", type)) {
        printf("\x1b[033m[DEBUG] %s\x1b[0m\n", formatted.data);
    }
    else if (string_compare("error", type)) {
        printf("\x1b[031m[ERROR] %s\x1b[0m\n", formatted.data);
    }
    else if (string_compare("fatal", type)) {
        printf("\x1b[031m[FATAL] %s\x1b[0m\n", formatted.data);
        exit(1);
    }
    else {
        printf("[INFO] %s\n", formatted.data);
    }
}

void print_fatal(str msg, size_t status) 
{
    printf("\x1b[031m[FATAL] %s\n[STATUS] %zu\n", msg, status);
    exit(status);
}