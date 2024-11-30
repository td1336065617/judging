//
// Created by fspst on 23-10-29.
//

#include "../../mysql/mysql_pool.h"
#include "../Data_Template/examination_questions/examination_questions.h"
#include "../Data_Template/Question_Test_Information/Question_Test_Information.h"

#ifndef DATASTRUCTPLAYGROUND_SERVER_DATA_CACHE_POOL_H
#define DATASTRUCTPLAYGROUND_SERVER_DATA_CACHE_POOL_H

namespace Epoll_server {

    class Data_cache_pool {
    public:
        Data_cache_pool();
        examination_questions get_examination_questions(int Question_id);
        void setmysql(string host, int post, string username, string password, string database_name, int mysql_min,
                      int mysql_max);
        int Initialization_examination_questions();
        Question_Test_Information get_Question_Test_Information(int Test_id);

        int Update_Question_Test_Information(Question_Test_Information questionTestInformation);
    private:
        mysql_pool mysqlPool;
        mutex user_poll_mtx, userid_username_mtx;
        mutex examination_questions_vector_mtx, examination_questions_poll_mtx;
        mutex Question_Sheet_poll_mtx, Question_Sheet_vector_Privately_mtx;
        mutex Question_Sheet_vector_Privately_Users_mtx,Question_Sheet_type_mtx;
        mutex user_id_auto_mtx,examination_questions_id_auto_mtx,Question_Sheet_id_auto_mtx,Application_Information_id_auto_mtx;
        mutex Application_Information_poll_mtx,Application_Information_poll_receive_mtx,Application_Information_poll_Application_mtx;
        mutex Question_Test_Information_poll_mtx,Question_Test_Information_id_auto_mtx;
        //题目信息
        int examination_questions_id_auto;
        std::vector<int> examination_questions_vector;//方便按题号先后顺序取题的映射表
        std::map<int, examination_questions> examination_questions_poll;
        //
    };

} // Epoll_server

#endif //DATASTRUCTPLAYGROUND_SERVER_DATA_CACHE_POOL_H
