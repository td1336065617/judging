//
// Created by fspst on 23-11-6.
//
#include "Web_Task.h"

namespace Epoll_server{
    Web_Task::result Web_Task::Process_running_monitor(int pid, long Time_limit_for_each_test, long Memory_limit_per_test) {
        result r;
        int status;
        struct rusage ru;
        if (wait4(pid, &status, 0, &ru) == -1)
            printf("wait4 failure");
        r.timeUsed = ru.ru_utime.tv_sec * 1000
                         + ru.ru_utime.tv_usec / 1000
                         + ru.ru_stime.tv_sec * 1000
                         + ru.ru_stime.tv_usec / 1000;
        r.memoryUsed = ru.ru_maxrss;
        if (WIFSIGNALED(status)) {
            switch (WTERMSIG(status)) {
                case SIGSEGV:
                    if (r.memoryUsed > Memory_limit_per_test*1024*1024)
                        r.status = MLE;
                    else
                        r.status = RE;
                    break;
                case SIGALRM:
                case SIGXCPU: {
                    if (r.timeUsed > Time_limit_for_each_test)
                        r.status = TLE;
                    else
                        r.status= AC;
                }break;
                default:
                    r.status = RE;
                    break;
            }
        } else {
            if (r.timeUsed > Time_limit_for_each_test)
                r.status = TLE;
            else if (r.memoryUsed > Memory_limit_per_test*1024*1024)
                r.status = MLE;
            else
                r.status = AC;
        }
        return r;
    }
}

