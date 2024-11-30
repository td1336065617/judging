//
// Created by fspst on 23-10-29.
//

#include "Question_Test_Information.h"

namespace Epoll_server {
    int Question_Test_Information::getTestId() const {
        return Test_id;
    }

    void Question_Test_Information::setTestId(int testId) {
        Test_id = testId;
    }

    int Question_Test_Information::getAccountId() const {
        return Account_id;
    }

    void Question_Test_Information::setAccountId(int accountId) {
        Account_id = accountId;
    }

    int Question_Test_Information::getQuestionId() const {
        return Question_id;
    }

    void Question_Test_Information::setQuestionId(int questionId) {
        Question_id = questionId;
    }

    int Question_Test_Information::getTestStatus() const {
        return Test_status;
    }

    void Question_Test_Information::setTestStatus(int testStatus) {
        Test_status = testStatus;
    }

    const std::string &Question_Test_Information::getTestingTheCode(){
        while (Testing_the_code.find("@danyin")!=Testing_the_code.npos)
        {
            Testing_the_code=Testing_the_code.replace(Testing_the_code.find("@danyin"),7,"'");
        }
        return Testing_the_code;
    }

    void Question_Test_Information::setTestingTheCode(const std::string &testingTheCode) {
        Testing_the_code = testingTheCode;
        while (Testing_the_code.find("'")!=Testing_the_code.npos)
        {
            Testing_the_code=Testing_the_code.replace(Testing_the_code.find("'"),1,"@danyin");
        }
    }

    int Question_Test_Information::getRunningTime() const {
        return Running_time;
    }

    void Question_Test_Information::setRunningTime(int runningTime) {
        Running_time = runningTime;
    }

    int Question_Test_Information::getMemoryFootprint() const {
        return Memory_footprint;
    }

    void Question_Test_Information::setMemoryFootprint(int memoryFootprint) {
        Memory_footprint = memoryFootprint;
    }

    int Question_Test_Information::getCodeLength() const {
        return Code_length;
    }

    void Question_Test_Information::setCodeLength(int codeLength) {
        Code_length = codeLength;
    }

    int Question_Test_Information::getUseLanguage() const {
        return Use_language;
    }

    void Question_Test_Information::setUseLanguage(int useLanguage) {
        Use_language = useLanguage;
    }

    const std::string &Question_Test_Information::getCommitTime() const {
        return Commit_time;
    }

    void Question_Test_Information::setCommitTime(const std::string &commitTime) {
        Commit_time = commitTime;
    }

    int Question_Test_Information::getTestResults() const {
        return Test_results;
    }

    void Question_Test_Information::setTestResults(int testResults) {
        Test_results = testResults;
    }

    std::string Question_Test_Information::sql_increase() {
        std::string sql="INSERT INTO `Question_Test_Information` (`Account_id`, `Question_id`, `Question_Sheet_id`, `Testing_the_code`,`Code_length`, `Use_language`, `Commit_time`,`Response_time`,`Accuracy`) VALUES ";
        std::string dan_yin="\'";
        std::string dou_hao=",";
        sql+="(";
        sql+=std::to_string(Account_id)+dou_hao;
        sql+=std::to_string(Question_id)+dou_hao;
        sql+=std::to_string(Question_Sheet_id)+dou_hao;
        sql+=(dan_yin+Testing_the_code+dan_yin)+dou_hao;
        sql+=std::to_string(Code_length)+dou_hao;
        sql+=std::to_string(Use_language)+dou_hao;
        sql+=(dan_yin+Commit_time+dan_yin)+dou_hao;
        sql+=std::to_string(Response_time)+dou_hao;
        sql+=std::to_string(Accuracy).substr(0,std::to_string(Accuracy).find(".")+3);
        sql+=");";
        
        return sql;
    }

    std::string Question_Test_Information::sql_Delete() {
        return std::string();
    }

    std::string Question_Test_Information::sql_Update() {
        std::string sql="UPDATE `Question_Test_Information` SET ";
        std::string dan_yin="\'";
        std::string dou_hao=",";
        sql+="Test_status = "+ std::to_string(Test_status) +dou_hao;
        sql+="Running_time = "+ std::to_string(Running_time) +dou_hao;
        sql+="Memory_footprint = "+ std::to_string(Memory_footprint) +dou_hao;
        sql+="Accuracy = "+ std::to_string(Accuracy).substr(0,std::to_string(Accuracy).find(".")+3) +dou_hao;
        sql+="Test_results = "+ std::to_string(Test_results) ;
        sql+=" WHERE Test_id ="+std::to_string(Test_id)+";";
        return sql;
    }
    std::string Question_Test_Information::sql_id_select() {
        std::string sql="SELECT * FROM Question_Test_Information WHERE Test_id=";
        sql+= std::to_string(Test_id);
        sql+=";";
        return sql;
    }

    std::string Question_Test_Information::sql_Lookup() {
        return std::string();
    }

    int Question_Test_Information::getQuestionSheetId() const {
        return Question_Sheet_id;
    }

    void Question_Test_Information::setQuestionSheetId(int questionSheetId) {
        Question_Sheet_id = questionSheetId;
    }

    std::string Question_Test_Information::sql_select_all() {
        std::string sql="SELECT * FROM Question_Test_Information;";
        return sql;
    }

    int Question_Test_Information::getResponseTime() const {
        return Response_time;
    }

    void Question_Test_Information::setResponseTime(int responseTime) {
        Response_time = responseTime;
    }

    double Question_Test_Information::getAccuracy() const {
        return Accuracy;
    }

    void Question_Test_Information::setAccuracy(double accuracy) {
        Accuracy = accuracy;
    }
} // Epoll_server