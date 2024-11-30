//
// Created by fspst on 23-5-7.
//

#include "mysql_pool.h"
int mysql_pool::set_mysql_pool(std::string host, int post, std::string username, std::string password,
                               std::string database_name, int mysql_min, int mysql_max) {
    this->host = host;
    this->post = post;
    this->username = username;
    this->password = password;
    this->database_name = database_name;
    this->mysql_min = mysql_min;
    this->mysql_max = mysql_max;

    for (int i = 0; i < mysql_min; i++)
    {
        if (add_mysql() == -1)
        {
            cout << "你是不是把数据库min与max写反了" << endl;
            break;
        }
    }
    cout<<"数据库连接池初始化完毕"<<endl;
    return 0;
}