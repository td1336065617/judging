//
// Created by fspst on 23-5-7.
//
#include "mysql_pool.h"
void mysql_pool::store_mysql(mysql_value mysql_con)
{
    mysql_queue_mtx.lock();
    mysql_queue.push(mysql_con);
    mysql_queue_mtx.unlock();
    wait_mysql_mtx.lock();
    wait_mysql++;
    wait_mysql_mtx.unlock();
    mysql_sem.addsem();

    if (wait_mysql > (existing_mysql - mysql_min))
    {
        close_mysql();
    }
}
