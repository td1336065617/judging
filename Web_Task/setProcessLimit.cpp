//
// Created by fspst on 23-11-6.
//
#include "Web_Task.h"
namespace Epoll_server{
    void Web_Task::Set_process_limits(long Time_limit_for_each_test, long Memory_limit_per_test) {
        {
            struct rlimit rlimit1;
            /* set the time_limit (second)*/
            rlimit1.rlim_cur = Time_limit_for_each_test / 1000;
            rlimit1.rlim_max = rlimit1.rlim_cur + 1;
            setrlimit(RLIMIT_CPU, &rlimit1);

            /* set the memory_limit (b)*/
            rlimit1.rlim_cur = Memory_limit_per_test * 1024*1024;
            rlimit1.rlim_max = rlimit1.rlim_cur + 1024;
            setrlimit(RLIMIT_DATA, &rlimit1);
        }
    }
}

