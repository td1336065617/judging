//
// Created by fspst on 23-10-25.
//
#include "../HTTP_DATA/HTTP_request_data.h"
#include "../HTTP_DATA/HTTP_response_data.h"
#include "../mysql/mysql_pool.h"
#include "Data_cache_pool/Data_cache_pool.h"
#include "../Epoll_request/Epoll_request.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/ptrace.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#ifndef DATASTRUCTPLAYGROUND_SERVER_WEB_TASK_H
#define DATASTRUCTPLAYGROUND_SERVER_WEB_TASK_H
#define AC 1
#define PE 2
#define TLE 3
#define MLE 4
#define WA 5
#define RE 6
#define OLE 7
#define CE 8
#define SE 9
#define PAC 10
namespace Epoll_server {

    class Web_Task {
    public:
        struct result {
            int status;
            int timeUsed;
            int memoryUsed;
        };
        Web_Task();

        virtual ~Web_Task();

        void Initialize_data();
        int
        Task_distribution_center(Epoll_server::HTTP_request_data httpRequestData, HTTP_response_data &httpResponseData);
        void setmysql(string host, int post, string username, string password, string database_name, int mysql_min,
                      int mysql_max);
        int judging_problem(HTTP_request_data httpRequestData, HTTP_response_data &httpResponseData);
        string Compile_instruction(Question_Test_Information questionTestInformation,::string url,string file_type);
        inline bool file_stat (const std::string& name) {
            struct stat buffer;
            return (stat (name.c_str(), &buffer) == 0);
        }
        void Set_process_limits(long Time_limit_for_each_test, long Memory_limit_per_test);
        void Process_running_run(char *args[],long Time_limit_for_each_test, long Memory_limit_per_test, const char *in_file,const char *out_file);
        struct result Process_running(string Executable_file,string in_file,string out_file,examination_questions examinationQuestions);
        struct result  Process_running_monitor(int pid,long Time_limit_for_each_test, long Memory_limit_per_test);
    private:
        string GMT_time_data_format = "%a, %d %b %Y %H:%M:%S %Z";          // GMT时间转换的模板
        string The_default_directory = "";
        Data_cache_pool dataCachePool;
        unordered_map<string, int> Secret_level;
        mutex Access_weight_mtx,UseLanguage_file_type_mtx;
        map<string, int> Access_weight;
        map<int,string>UseLanguage_file_type;
        Epoll_request epollRequest;
        string webserverurl;
        int judging_id;
    public:
        int getJudgingId() const;

        void setJudgingId(int judgingId);

    public:
        const string &getWebserverurl() const;

        void setWebserverurl(const string &webserverurl);
    };
} // Web_Task

#endif //DATASTRUCTPLAYGROUND_SERVER_WEB_TASK_H
