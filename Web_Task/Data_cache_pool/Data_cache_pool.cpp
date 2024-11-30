//
// Created by fspst on 23-10-29.
//

#include "Data_cache_pool.h"

namespace Epoll_server {

    void Data_cache_pool::setmysql(string host, int post, string username, string password, string database_name,
                                   int mysql_min, int mysql_max) {
        mysqlPool.set_mysql_pool(host, post, username, password, database_name, mysql_min, mysql_max);
        //Initialization_examination_questions();
    }

    Data_cache_pool::Data_cache_pool() {

    }

} // Epoll_server