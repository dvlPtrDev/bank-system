#include <input.h>
#include <users.h>
#include <strlib.h>
#include <sqlite_utility.h>
#include <display.h>
#include <stdio.h>
#include <stdlib.h>

static void flush_stdin(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void get_string(String *string)
{
    if (!fgets(string->data, string->capacity, stdin))
        return;

    replace_char(string->data, '\n', '\0');
    string->string_from(string, string->data);
}

void get_number(void *field, bool is_integer)
{
    if (is_integer) {
        scanf("%i", (int *)field);
    } else {
        scanf("%f", (float *)field);
    }

    flush_stdin();
}

void fill_struct(User *user)
{
    printf("Digite seu nome de usuário: ");
    get_string(&user->username);

    printf("Digite sua senha: ");
    get_string(&user->password);

    printf("Quanto saldo você tem na conta? ");
    get_number(&user->balance, false);
}

static int insert_user(sqlite3 *conn, User *user)
{
    const char *query =
        "INSERT INTO users (username, password, balance) VALUES (?, ?, ?)";

    sqlite3_stmt *stmt = stmt_prepare(conn, query);
    if (!stmt)
        return sqlite3_errcode(conn);

    if (
        !bind_text(stmt, 1, user->username.data) ||
        !bind_text(stmt, 2, user->password.data) ||
        !bind_double(stmt, 3, user->balance)
    ) {
        sqlite3_finalize(stmt);
        return sqlite3_errcode(conn);
    }
    if (!step(stmt, true)) {
        return sqlite3_errcode(conn);
    }
    return SQLITE_DONE; 
}

void create_user(sqlite3 *conn)
{
    User user;

    user.username = new_string(31);
    user.password = new_string(51);

    fill_struct(&user);
    int rc = insert_user(conn, &user);
    if (rc != SQLITE_DONE) {
        if (rc == SQLITE_CONSTRAINT) {
            print(
                "error",
                "Erro ao inserir usuário, lógica de banco violada!\n%s",
                sqlite3_errmsg(conn)
            );
        } else {
            print(
                "error",
                "Não reconhecemos esse erro!\n%s",
                sqlite3_errmsg(conn)
            );
        }
    }
    
    drop_string(&user.username);
    drop_string(&user.password);
}