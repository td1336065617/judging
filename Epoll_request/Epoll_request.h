//
// Created by fspst on 23-6-16.
//

#ifndef BOOT_CPP_EPOLL_REQUEST_H
#define BOOT_CPP_EPOLL_REQUEST_H
#include "string"
namespace Epoll_server {
    class Epoll_request {
    public:
        std::string post_url(std::string url,std::string post_str) ;
        std::string get_url(std::string url);
    private:
        static size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp);
    };
}


#endif //BOOT_CPP_EPOLL_REQUEST_H
