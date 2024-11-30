//
// Created by fspst on 23-11-5.
//
#include "Data_cache_pool.h"

namespace Epoll_server {
    examination_questions Data_cache_pool::get_examination_questions(int Question_id) {
        examination_questions examinationQuestions;
        try {
            examinationQuestions.setQuestionId(-1);
                examination_questions examinationQuestions1;
                examinationQuestions1.setQuestionId(Question_id);
                mysql_value mysqlValue = mysqlPool.get_mysql();
                string sql = examinationQuestions1.sql_select_id();
                MYSQL_RES* mysqlRes = mysqlPool.mysql_db_select(mysqlValue.mysql_con, sql);
                int num = mysql_num_rows(mysqlRes);
                if(num>0)
                {
                    MYSQL_ROW r = mysql_fetch_row(mysqlRes);
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
        return examinationQuestions;
    }
}