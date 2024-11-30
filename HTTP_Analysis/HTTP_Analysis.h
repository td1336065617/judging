//
// Created by fspst on 23-6-13.
//
#include "../xt_heard/xt_heard.h"
#include "../HTTP_DATA/HTTP_request_data.h"

#ifndef BOOT_CPP_HTTP_ANALYSIS_H
#define BOOT_CPP_HTTP_ANALYSIS_H

namespace Epoll_server {

    using namespace std;

    class HTTP_Analysis {
    public:
        HTTP_Analysis();

        ~HTTP_Analysis();

        HTTP_request_data HTTP_message_parsing(int acceptbj, string mess);
    private:
        void Data_spliti(string datastr, HTTP_request_data *http_request_value);

        void HTTP_Cookie_value_spliti(HTTP_request_data *http_request_value);

        void server_urlencode(string *str_value);

        struct urlencode                                                                             // urlencode编码的对照类
        {
            string s1, s2;
        };
        vector<urlencode> urlencode_str;                                  // urlencode编码的对照类数组
    };
} // Epoll_server

#endif //BOOT_CPP_HTTP_ANALYSIS_H
