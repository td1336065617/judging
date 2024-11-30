//
// Created by fspst on 23-11-5.
//
#include "Web_Task.h"
namespace Epoll_server{
    string Web_Task::Compile_instruction(Question_Test_Information questionTestInformation,::string url, string file_type){
        string Compile_instructionstr;
        if (questionTestInformation.getUseLanguage()==1||questionTestInformation.getUseLanguage()==2)
        {
            Compile_instructionstr="g++ -std=c++17 "+url+ to_string(questionTestInformation.getTestId())+file_type+" -O3 -o "+url+ to_string(questionTestInformation.getTestId());
        }
        return Compile_instructionstr;
    }
}
