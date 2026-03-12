#ifndef DB_HANDLER
#define DB_HANDLER
#include <stdio.h>
#include <strlib.h>

sqlite3 *create_db(str db_name, str schema_path);

#endif