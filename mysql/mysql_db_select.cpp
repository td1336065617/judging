#include "mysql_pool.h"
MYSQL_RES * mysql_pool::mysql_db_select(MYSQL *mysql_p, string sql)
{
    MYSQL_RES *res;
    if (mysql_p == NULL)
    {
        return NULL;
    }

    if (mysql_real_query(mysql_p, sql.c_str(), sql.length()))
    {
        return NULL;
    }

    res = mysql_store_result(mysql_p);

    if (res == NULL)
    {
        return NULL;
    }

    return res;
}
