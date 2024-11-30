//
// Created by fspst on 23-11-6.
//
#include "Web_Task.h"
namespace Epoll_server{
    Web_Task::result Web_Task::Process_running(string Executable_file, string in_file, string out_file,examination_questions examinationQuestions) {
        result r;
        rusage rusage1;
        char argv_str[300];
        sprintf(argv_str, Executable_file.c_str()); // string -> char*
        char *args[] = {argv_str,"",NULL};
        pid_t pid;
        if ((pid = vfork()) < 0) {
            printf("forkerror!\n");
            exit(1);
        }
        if (pid == 0) {
            Process_running_run(args,examinationQuestions.getTimeLimitForEachTest(),examinationQuestions.getMemoryLimitPerTest(),in_file.c_str(),out_file.c_str());
        }else if (pid > 0){
            r= Process_running_monitor(pid,examinationQuestions.getTimeLimitForEachTest(),examinationQuestions.getMemoryLimitPerTest());
        }
        return r;
    }
}
