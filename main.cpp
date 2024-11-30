#include <iostream>
#include "Epoll_Server/Epoll_server.h"
int main() {
    int post;
    std::cout << "请输入端口:" << std::endl;
    std::cin>>post;
    
    Epoll_server::Epoll_server epoll;
    epoll.setmysql("bj-cynosdbmysql-grp-61at4tsi.sql.tencentcdb.com", 29978, "DataStructPlayground_user", "15046163209@qq", "DataStructPlayground_Data", 5, 300);
    //epoll.set_Thread_Poll(100,5,10);
    epoll.set_server("127.0.0.1",post,"127.0.0.1:9999/Feedback_of_the_judgment.jk",1);
    //epoll.setBootServerUrl("127.0.0.1:5700");         57
    epoll.start_server();
    return 0;
}
