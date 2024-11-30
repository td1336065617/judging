#include "mysql_pool.h"
void mysql_pool::destruction_mysql()
{
    while (1)
    {
        if (wait_mysql == existing_mysql)
        {
            while (!mysql_queue.empty())
            {
                mysql_queue_mtx.lock();
                mysql_close(mysql_queue.front().mysql_con);
                mysql_queue.pop();
                mysql_queue_mtx.unlock();
                mysql_sem.reducesem();
                existing_mysql_mtx.lock();
                existing_mysql--;
                existing_mysql_mtx.unlock();
                wait_mysql_mtx.lock();
                wait_mysql--;
                wait_mysql_mtx.unlock();
            }
        }
        else
        {
            cout << "稍等 还有连接在干活:" << existing_mysql - wait_mysql << endl;
        }
    }
}
