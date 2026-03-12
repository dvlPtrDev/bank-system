#ifndef INPUT_H
#define INPUT_H

#include <strlib.h>
#include <stdio.h>
#include <users.h>

void ask_input(User *user);
void get_string(String *string);
void get_number(void *field, bool is_integer);

#endif