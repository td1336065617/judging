//
// Created by fspst on 23-10-29.
//
#include "../../../xt_heard/xt_heard.h"
#ifndef DATASTRUCTPLAYGROUND_SERVER_EXAMINATION_QUESTIONS_H
#define DATASTRUCTPLAYGROUND_SERVER_EXAMINATION_QUESTIONS_H

namespace Epoll_server {

    class Question_Test_Information {
    public:
        int getTestId() const;

        void setTestId(int testId);

        int getAccountId() const;

        void setAccountId(int accountId);

        int getQuestionId() const;

        void setQuestionId(int questionId);

        int getTestStatus() const;

        void setTestStatus(int testStatus);

        const std::string &getTestingTheCode();

        void setTestingTheCode(const std::string &testingTheCode);

        int getRunningTime() const;

        void setRunningTime(int runningTime);

        int getMemoryFootprint() const;

        void setMemoryFootprint(int memoryFootprint);

        int getCodeLength() const;

        void setCodeLength(int codeLength);

        int getUseLanguage() const;

        void setUseLanguage(int useLanguage);

        const std::string &getCommitTime() const;

        void setCommitTime(const std::string &commitTime);

        int getTestResults() const;

        void setTestResults(int testResults);

        int getQuestionSheetId() const;

        void setQuestionSheetId(int questionSheetId);

        std::string sql_increase();
        std::string sql_Delete();
        std::string sql_Update();
        std::string sql_Lookup();
        std::string sql_select_all();
        std::string sql_id_select();
    private:
        int Test_id=-1;//测试编号
        int Account_id=0;//提交帐号的id
        int Question_id=0;//测试的题目的id
        int Question_Sheet_id=0;//所属题单 id
        int Test_status=0;//测试状态
        std::string Testing_the_code="";//测试代码
        int Running_time=0;//运行时间（秒）
        int Memory_footprint=0;//占用内存
        int Code_length=0;//代码长度
        int Use_language=0;//使用语言
        double Accuracy=0;//正确率
    public:
        double getAccuracy() const;

        void setAccuracy(double accuracy);

    public:
        int getResponseTime() const;

        void setResponseTime(int responseTime);

    private:
        std::string Commit_time;//提交时间
        int Test_results;//测试结果
        int Response_time;//从打开题目到提交题目的做答用时
    };

} // Epoll_server

#endif //DATASTRUCTPLAYGROUND_SERVER_EXAMINATION_QUESTIONS_H
