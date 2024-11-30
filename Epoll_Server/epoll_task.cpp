//
// Created by fspst on 23-6-13.
//
#include <nlohmann/json.hpp>
#include "Epoll_server.h"
#include "../Web_Task/Web_Task.h"

namespace Epoll_server {
    void  Epoll_server::epoll_task() {

        //首先数据读取
        int fd;
        recv_fd_mtx.lock();
        if (recv_fd.empty()) {
            recv_fd_mtx.unlock();
            return ;
        }
        fd = recv_fd.front();
        recv_fd.pop();
        recv_fd_mtx.unlock();
        string mess;
        epoll_recv(fd, mess);//读取数据
        //cout<<mess<<endl;
        HTTP_Analysis httpAnalysis;
        HTTP_request_data httpRequestData = httpAnalysis.HTTP_message_parsing(fd, mess);
        //数据返回
       // cout<<httpRequestData.http_value["Host"]<<endl;
        HTTP_response_data httpResponseData;
        HTTP_syn_response(httpRequestData,httpResponseData);
        //cout<<httpResponseData<<endl;
        nlohmann::json pdjg;
        Remaining_task_mtx.lock();
        Remaining_task++;
        pdjg["status"] = 1;
        pdjg["Remaining_task"]=Remaining_task;
        httpResponseData.HTTP_Status_Code = "HTTP/1.1 200 ok";
        Remaining_task_mtx.unlock();
        httpResponseData.file_or_data = 1;
        httpResponseData.http_response_data_value = pdjg.dump();
        string re_mess;
        //处理完成 返回运行结果。
        epoll_response(fd,httpResponseData);
        //任务完成 套接字关闭
        epoll_del(fd);
        /*  if(httpResponseData.code)
            re_mess=epollRequest.post_url(BOOT_server_url,httpResponseData.Endpoints,httpResponseData.POST_Json_Data());
        */
        webTask.Task_distribution_center(httpRequestData,httpResponseData);//任务处理。
        Remaining_task_mtx.lock();
        Remaining_task--;
        Remaining_task_mtx.unlock();
        // cout<<re_mess;
    }
}