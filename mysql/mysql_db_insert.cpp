#include "mysql_pool.h"
int mysql_pool::mysql_db_insert(MYSQL *mysql_p, string sql)
{
    if (mysql_p == NULL)
    {
        return -1;
    }

    if (mysql_real_query(mysql_p, sql.c_str(), sql.length()))
    {
        return -2;
    }

    return 1;
}
