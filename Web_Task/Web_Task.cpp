//
// Created by fspst on 23-10-25.
//

#include "Web_Task.h"

namespace Epoll_server {
    Web_Task::~Web_Task() {

    }

    Web_Task::Web_Task() {
        The_default_directory = "../web_code/oj";
        ifstream insrc;
        insrc.open("../src/Access_weight", ios_base::binary);
        string s1, s2;

        while ((getline(insrc, s1)) && (getline(insrc, s2))) {
            Access_weight_mtx.lock();
            Access_weight[s1] = std::atoi(s2.c_str());
            Access_weight_mtx.unlock();
        }
        insrc.close();
        UseLanguage_file_type[1]=".cpp";
        UseLanguage_file_type[2]=".cpp";
        UseLanguage_file_type[3]=".java";
    }

    void
    Web_Task::setmysql(string host, int post, string username, string password, string database_name, int mysql_min,
                       int mysql_max) {
        dataCachePool.setmysql(host, post, username, password, database_name, mysql_min, mysql_max);
    }
    string Compile_instruction(Question_Test_Information questionTestInformation);
    void Web_Task::Initialize_data() {;
    }

    const string &Web_Task::getWebserverurl() const {
        return webserverurl;
    }

    void Web_Task::setWebserverurl(const string &webserverurl) {
        Web_Task::webserverurl = webserverurl;
    }

    int Web_Task::getJudgingId() const {
        return judging_id;
    }

    void Web_Task::setJudgingId(int judgingId) {
        judging_id = judgingId;
    }


}
