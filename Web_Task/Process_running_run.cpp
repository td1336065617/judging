//
// Created by fspst on 23-11-6.
//
#include "Web_Task.h"
namespace Epoll_server{
    void Web_Task::Process_running_run(char *args[],long Time_limit_for_each_test, long Memory_limit_per_test, const char *in_file,const char *out_file) {
        int newstdin = open(in_file,O_RDWR|O_CREAT,0644);
        int newstdout=open(out_file,O_RDWR|O_CREAT,0644);
        if (newstdout != -1 && newstdin != -1) {
           /* if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) != -1) {
                printf("====== ok =====\n");
            } */
            printf("Child process PID:%d.\n", getpid());
            dup2(newstdout,fileno(stdout));
            dup2(newstdin,fileno(stdin));
            Set_process_limits(Time_limit_for_each_test, Memory_limit_per_test);
            if (execvp(*args, args) == -1) {
                perror("execvp");
                printf("No suchfile!");
                exit(0);
            }
        }else{
            
        }
        printf("Parent processPID: %d.\n", getpid());
        close(newstdin);
        close(newstdout);
    }
}

