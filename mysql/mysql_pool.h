//
// Created by fspst on 23-5-7.
//

#ifndef CESHI1_MYSQL_POOL_H
#define CESHI1_MYSQL_POOL_H

#include <mysql/mysql.h>
#include <string>
#include <queue>
#include <iostream>
#include <mutex>
#include "../Thread_Pool_sem/Thread_Pool_sem.h"
using std::endl;
using std::mutex;
using std::cout;
using std::queue;
using std::string;
struct mysql_value{
    MYSQL *mysql_con;
    bool mysql_con_state;//是否成功创建成功
};
class mysql_pool
{
private:
    string host;
    int post;
    string username;
    string password;
    string database_name;
    int mysql_min,mysql_max;
    int existing_mysql=0;                  //现有的连接
    int wait_mysql=0;                      //没活可干的连接
    Thread_Pool_sem mysql_sem;
    queue<mysql_value> mysql_queue;
    mutex wait_mysql_mtx,existing_mysql_mtx,mysql_queue_mtx;
    int add_mysql();   //增加线程池的库存,如果连接数到达mysql_max后不在增加
public:
    const string &getDatabaseName() const {
        return database_name;
    }
    mysql_value get_mysql();  //获取一个数据库连接
    void store_mysql(mysql_value mysql_con); //用完了放回去
    void close_mysql(); //负载下降 减少数据库连接池到mysql_min
    void destruction_mysql();//服务器要关闭了 销毁连接池
    int mysql_db_insert(MYSQL *mysql_p, string sql);
    MYSQL_RES *mysql_db_select(MYSQL *mysql_p, string sql);
    int mysql_db_update(MYSQL *mysql_p, string sql);
    int mysql_db_delete(MYSQL *mysql_p, string sql);
    int set_mysql_pool(string host,int post,string username,string password,string database_name,int mysql_min,int mysql_max); //初始化数据库连接池
    mysql_pool();
    ~mysql_pool();
};
#endif //CESHI1_MYSQL_POOL_H
