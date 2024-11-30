//
// Created by fspst on 23-11-5.
//
#include "Data_cache_pool.h"
namespace Epoll_server{
    Question_Test_Information Data_cache_pool::get_Question_Test_Information(int Test_id) {
        Question_Test_Information questionTestInformation;
        try {
            Question_Test_Information questionTestInformation1;
            questionTestInformation1.setTestId(Test_id);
            mysql_value mysqlValue = mysqlPool.get_mysql();
            string sql = questionTestInformation1.sql_id_select();
            MYSQL_RES* mysqlRes = mysqlPool.mysql_db_select(mysqlValue.mysql_con, sql);
            int num = mysql_num_rows(mysqlRes);
            if (0 < num) {
                MYSQL_ROW r = mysql_fetch_row(mysqlRes);
                questionTestInformation.setTestId(atoi(r[0]));
                questionTestInformation.setAccountId(atoi(r[1]));
                questionTestInformation.setQuestionId(atoi(r[2]));
                questionTestInformation.setQuestionSheetId(atoi(r[3]));
                questionTestInformation.setTestStatus(atoi(r[4]));
                questionTestInformation.setTestingTheCode(r[5]);
                questionTestInformation.setRunningTime(atoi(r[6]));
                questionTestInformation.setMemoryFootprint(atoi(r[7]));
                questionTestInformation.setCodeLength(atoi(r[8]));
                questionTestInformation.setUseLanguage(atoi(r[9]));
                questionTestInformation.setCommitTime(r[10]);
                questionTestInformation.setTestResults(atoi(r[11]));
                questionTestInformation.setResponseTime(atoi(r[12]));
                questionTestInformation.setAccuracy(atof(r[13]));
            }
            mysql_free_result(mysqlRes);
            mysqlPool.store_mysql(mysqlValue);
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << '\n';
        }
        return questionTestInformation;
    }
}
