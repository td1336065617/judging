//
// Created by fspst on 23-11-6.
//
#include "Data_cache_pool.h"
namespace Epoll_server{
    int
    Data_cache_pool::Update_Question_Test_Information(Epoll_server::Question_Test_Information questionTestInformation) {
        int status = 0;
        try {
            mysql_value mysqlValue = mysqlPool.get_mysql();
            string sql = questionTestInformation.sql_Update();
            status = mysqlPool.mysql_db_update(mysqlValue.mysql_con, sql);
            mysqlPool.store_mysql(mysqlValue);
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << '\n';
        }
        return status;
    }
}
