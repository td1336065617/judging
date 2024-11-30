//
// Created by fspst on 23-10-31.
//
#include "Data_cache_pool.h"

namespace Epoll_server {
    int Data_cache_pool::Initialization_examination_questions() {

        try {
            string auto_sql="SELECT (auto_increment-1) FROM information_schema.tables WHERE table_name='examination_questions' AND TABLE_SCHEMA='DataStructPlayground_Data';";
            mysql_value mysqlValue = mysqlPool.get_mysql();
            MYSQL_RES *mysqlRes = mysqlPool.mysql_db_select(mysqlValue.mysql_con, auto_sql);
            int num = mysql_num_rows(mysqlRes);
            MYSQL_ROW r = mysql_fetch_row(mysqlRes);
            examination_questions_id_auto= atoi(r[0]);
            mysql_free_result(mysqlRes);
            mysqlPool.store_mysql(mysqlValue);

            examination_questions examinationQuestions1;
            mysqlValue = mysqlPool.get_mysql();
            string sql = examinationQuestions1.sql_select_all();
            mysqlRes = mysqlPool.mysql_db_select(mysqlValue.mysql_con, sql);
            num = mysql_num_rows(mysqlRes);
            for (int i = 0; i < num; i++) {
                r = mysql_fetch_row(mysqlRes);
                examination_questions examinationQuestions;
                examinationQuestions.setQuestionId(atoi(r[0]));
                examinationQuestions.setTitleTitle(r[1]);
                examinationQuestions.setQuestionDifficulty(r[2]);
                examinationQuestions.setTheTopicKnowledgePointLabel(r[3]);
                examinationQuestions.setBackgroundOfTopic(r[4]);
                examinationQuestions.setDescriptionOfProblem(r[5]);
                examinationQuestions.setInputDescription(r[6]);
                examinationQuestions.setOutputDescription(r[7]);
                examinationQuestions.setSampleInput(r[8]);
                examinationQuestions.setSampleOutput(r[9]);
                examinationQuestions.setTimeLimitForEachTest(atoi(r[10]));
                examinationQuestions.setMemoryLimitPerTest(atoi(r[11]));
                examinationQuestions.setCreatorId(atoi(r[12]));
                examinationQuestions.setInputData(r[13]);
                examinationQuestions.setOutputData(r[14]);
                
                examination_questions_vector_mtx.lock();
                examination_questions_vector.push_back(examinationQuestions.getQuestionId());
                examination_questions_vector_mtx.unlock();

                examination_questions_poll_mtx.lock();
                examination_questions_poll[examinationQuestions.getQuestionId()] = examinationQuestions;
                examination_questions_poll_mtx.unlock();
            }
            mysql_free_result(mysqlRes);
            mysqlPool.store_mysql(mysqlValue);
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << '\n';
        }
        return 0;
    }
}