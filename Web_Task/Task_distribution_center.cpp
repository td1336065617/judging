//
// Created by fspst on 23-10-25.
//
#include "Web_Task.h"
namespace Epoll_server {
    int Web_Task::Task_distribution_center(Epoll_server::HTTP_request_data httpRequestData,
                                           HTTP_response_data &httpResponseData) {
        if(httpRequestData.url=="/judging_problem.jk")
        {
            httpResponseData.file_or_data = 1;
            httpResponseData.HTTP_Status_Code = "HTTP/1.1 200 ok";
            judging_problem(httpRequestData, httpResponseData);
        }
        return 0;
    }
}