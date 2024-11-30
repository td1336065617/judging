//
// Created by fspst on 23-5-7.
//
#include "mysql_pool.h"
mysql_value mysql_pool::get_mysql()
{
    if (wait_mysql == 0)
    {
        add_mysql();
    }

    mysql_sem.waitsem();
    mysql_value mysql_con;
    mysql_queue_mtx.lock();
    mysql_con = mysql_queue.front();
    mysql_queue.pop();
    mysql_queue_mtx.unlock();
    wait_mysql_mtx.lock();
    wait_mysql--;
    wait_mysql_mtx.unlock();
    while (mysql_ping(mysql_con.mysql_con))
    {
        mysql_close(mysql_con.mysql_con);
        add_mysql();
        mysql_con=get_mysql();
    }
    return mysql_con;
}
