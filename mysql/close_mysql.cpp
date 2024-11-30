//
// Created by fspst on 23-5-7.
//
#include "mysql_pool.h"
void mysql_pool::close_mysql()
{
    if (existing_mysql > mysql_min && wait_mysql > (existing_mysql - mysql_min))
    {
        for (int i = 0; i < (existing_mysql - mysql_min); i++)
        {
            mysql_queue_mtx.lock();
            mysql_close(mysql_queue.front().mysql_con);
            mysql_queue.pop();
            mysql_queue_mtx.unlock();
            mysql_sem.reducesem();
            wait_mysql_mtx.lock();
            wait_mysql--;
            wait_mysql_mtx.unlock();
            existing_mysql_mtx.lock();
            existing_mysql--;
            existing_mysql_mtx.unlock();
        }
    }
}
