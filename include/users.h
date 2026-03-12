#ifndef USERS_H
#define USERS_H

#include <strlib.h>
#include <sqlite3.h>

typedef struct {
    int user_id;
    String username;
    String password;
    float balance;

} User;

void create_user(sqlite3 *conn);

#endif