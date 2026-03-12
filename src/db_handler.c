#include <stdio.h>
#include <strlib.h>
#include <sqlite_utility.h>
#include <users.h>
#include <display.h>
#include <db_handler.h>


sqlite3 *create_db(str db_name, str schema_path) 
{
    sqlite3 *conn = get_conn(db_name, DEFAULT_FLAGS);
    if (conn == NULL) {
        print("fatal", "Não foi possível criar o banco de dados! O caminho para o arquivo está certo?");
    }
    if (exec_schema(schema_path, conn) != SQLITE_OK) {
        print("fatal", "Não foi possível executar o esquema do banco, o caminho para o script está certo?");
    }
    return conn;
}



