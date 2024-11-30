//
// Created by fspst on 23-5-7.
//
#include "mysql_pool.h"
int mysql_pool::add_mysql()
{
    if (wait_mysql >= mysql_max)
    {
        return -1;
    }

    MYSQL *mysql_con;
    mysql_con = mysql_init(NULL);

    if ( mysql_con == NULL)
    {
        cout << mysql_error(mysql_con) << endl;
    }
    static int s_optVal = 1;
    mysql_options(mysql_con,MYSQL_OPT_READ_TIMEOUT,(const char*)&s_optVal);
    if (!mysql_real_connect(mysql_con, host.c_str(), username.c_str(), password.c_str(), database_name.c_str(), post, NULL, 0))
    {
        cout << mysql_error(mysql_con) << endl;
    }

    mysql_value mysql_con_value;
    mysql_con_value.mysql_con = mysql_con;
    mysql_con_value.mysql_con_state = 1;
    mysql_queue_mtx.lock();
    mysql_queue.push(mysql_con_value);
    mysql_queue_mtx.unlock();
    mysql_sem.addsem();
    wait_mysql_mtx.lock();
    wait_mysql++;
    wait_mysql_mtx.unlock();                 
    existing_mysql_mtx.lock();
    existing_mysql++;
    existing_mysql_mtx.unlock();
    return 1;
}
