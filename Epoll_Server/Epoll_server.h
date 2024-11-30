//
// Created by fspst on 23-6-12.
//
#include "../xt_heard/xt_heard.h"
#include "../HTTP_Analysis/HTTP_Analysis.h"
#include "../HTTP_DATA/HTTP_request_data.h"
#include "../Web_Task/Web_Task.h"
#include "../Thread_Pool/Thread_Pool_http_server.h"
#include "../Epoll_request/Epoll_request.h"
#include "../HTTP_DATA/HTTP_request_data.h"
#include "../HTTP_DATA/HTTP_response_data.h"
#ifndef BOOT_CPP_EPOLL_SERVER_H
#define BOOT_CPP_EPOLL_SERVER_H

namespace Epoll_server {
    using namespace std;
    class Epoll_server {
    public:
        Epoll_server();
        ~Epoll_server();
        void set_Thread_Poll(int maxcount, int mincount, int waittime){thread_poll.set_Thread_Pool_http_server(maxcount,mincount,waittime);};
        void set_server(string ip, int post,string webserverurl,int judging_id);//请先设置服务器参数  函数体在server.cpp
        void start_server(); // 函数体在server.cpp
        void setBootServerUrl(const string &bootServerUrl);
        void setmysql(string host,int post,string username,string password,string database_name,int mysql_min,int mysql_max);
    private:
        unordered_map<string, string> HTTP_Content_type_dictionary;         //这个哈希表记录了文件与其对于的响应头Content_type
        string The_default_directory;                                      // web目录
        string GMT_time_data_format = "%a, %d %b %Y %H:%M:%S %Z";          // GMT时间转换的模板
        int HTTP_syn_response(HTTP_request_data &httpRequestData,HTTP_response_data &httpResponseData);
        void HTTP_data_response(int clientbj,HTTP_response_data http_response1);
        void HTTP_file_response(int clientbj,HTTP_response_data http_response1);
        int serverbj;
        int bindbj;
        int listenbj;
        int epollbj;
        string BOOT_server_url;
        epoll_event listen_serverbj;
        epoll_event es[2048];
        mutex recv_fd_mtx;
        queue<int> recv_fd;
        Web_Task webTask;//业务代码任务
        void epoll_del(int fd);
        mutex Remaining_task_mtx;
        int Remaining_task=0;
        Thread_Pool_http_server thread_poll;
        Epoll_request epollRequest;
        void SIGPIPE_go_west(int go_west);//处理相关异常 函数体在server.cpp
        int epoll_recv(int fd, string &rq);//读取传输的数据 函数体在server.cpp
        int epoll_accept();  //接入入链接请求 函数体在server.cpp
        void epoll_task();//接入请求后数据读取处理返回等执行任务的中控函数
        void epoll_task_Bread();
        //返回机制需要更改
        int epoll_response(int clientbj,HTTP_response_data httpResponseData);//根据请求数据进行响应。实际上是对go-cqhttp http发出请求
    };

} // Epoll_server

#endif //BOOT_CPP_EPOLL_SERVER_H
