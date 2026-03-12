#include <input.h>
#include <sqlite3.h>
#include <users.h>
#include <db_handler.h>
#include <stdio.h>

void main_flow(int choice, sqlite3 *db);

int main(void) {
    sqlite3 *conn = create_db("databases/bank.db", "databases/schema.sql");
    int user_choice;
    do {
        puts("[1] Criar conta");
        puts("[2] Fazer login");
        puts("[3] listar saldo");
        puts("[4] sair");
        printf("> ");
        get_number(&user_choice, true);
    } while (user_choice < 1 || user_choice > 4);
    main_flow(user_choice, conn);
}

void main_flow(int choice, sqlite3 *db) 
{
    switch (choice) {
    case 1:
        create_user(db);
    break;
    default:
        break;
    }
}