//
// Created by fspst on 23-11-5.
//
#include <stdlib.h>
#include <nlohmann/json.hpp>
#include "Web_Task.h"
#include <unistd.h>
#include <sys/stat.h>
namespace Epoll_server {
    int Web_Task::judging_problem(HTTP_request_data httpRequestData, HTTP_response_data &httpResponseData) {
        nlohmann::json pdjg;
        int Test_id = ::atoi(httpRequestData.http_data_value["Test_id"].c_str());
        Question_Test_Information questionTestInformation = dataCachePool.get_Question_Test_Information(Test_id);
        examination_questions examinationQuestions = dataCachePool.get_examination_questions(
                questionTestInformation.getQuestionId());
        if (questionTestInformation.getTestId() == -1 || examinationQuestions.getQuestionId() == -1) {
            return -1;
        }

        UseLanguage_file_type_mtx.lock();
        string file_type = UseLanguage_file_type[questionTestInformation.getUseLanguage()];
        UseLanguage_file_type_mtx.unlock();
        ::string url = "../src/Test_temporary_directory/" + to_string(Test_id);
        ::system(("mkdir " + url).c_str());
        url += "/";
        string Compile_instruction_str = Compile_instruction(questionTestInformation, url, file_type);
        url += to_string(Test_id) + file_type;
        ofstream outsrc;
        outsrc.open(url, ios::out | ios::binary);
        string s1, s2;
        outsrc << questionTestInformation.getTestingTheCode();
        outsrc.close();
        system(Compile_instruction_str.c_str());
        url = "../src/Test_temporary_directory/" + to_string(Test_id) + "/" +
              to_string(questionTestInformation.getTestId());
        string lswj1="",lswj2="",lswj3="";
        if (file_stat(url)) {
            ::string judging_data_url= "../src/judging_data/" + to_string(examinationQuestions.getQuestionId());
            if (access(judging_data_url.c_str(), 0))
            {
                mkdir(judging_data_url.c_str(),0777);
                lswj1=judging_data_url;
            }
            if (examinationQuestions.getInputData() != "" || examinationQuestions.getOutputData() != "") {
                for (int i = 1;; i++) {
                    string in_file = "../src/judging_data/" + to_string(examinationQuestions.getQuestionId()) + "/" +
                                     to_string(i) + ".in";
                    string out_file = "../src/judging_data/" + to_string(examinationQuestions.getQuestionId()) + "/" +
                                      to_string(i) + ".out";
                    if (!file_stat(in_file)) {
                        lswj2=in_file;
                        lswj3=out_file;
                        ofstream onsrc, onsrc2;
                        onsrc.open(in_file, ios::out);
                        ::cout<<onsrc.is_open();
                        onsrc2.open(out_file, ios::out);
                        onsrc<<examinationQuestions.getInputData();
                        onsrc2<<examinationQuestions.getOutputData();
                        onsrc.close();
                        onsrc2.close();
                        break;
                    }
                }
            }
            int Running_time = 0, Memory_footprint = 0, Test_status = 1,jz=1;
            double Accuracy=0,Data_size=0;
            for (int i = 1;; i++) {
                if(Test_status==3)
                {

                    cout<<"???";
                }
                string in_file =
                        "../src/judging_data/" + to_string(examinationQuestions.getQuestionId()) + "/" + to_string(i) +
                        ".in";
                string out_file =
                        "../src/judging_data/" + to_string(examinationQuestions.getQuestionId()) + "/" + to_string(i) +
                        ".out";
                string out_file2 =
                        "../src/Test_temporary_directory/" + to_string(Test_id) + "/" + to_string(i) + ".out";
                if (file_stat(in_file)) {
                    Data_size++;
                    jz=0;
                    result r = Process_running(url, in_file, out_file2, examinationQuestions);
                    Running_time = max(r.timeUsed, Running_time);
                    Memory_footprint = max(r.memoryUsed, Memory_footprint);
                    if (r.status != 1) {
                        if (Test_status==1)
                        Test_status = r.status;
                    } else {
                        ifstream insrc, insrc2;
                        insrc.open(out_file, ios_base::binary);
                        insrc2.open(out_file2, ios_base::binary);
                        string s1, s2;
                        int bj = 0;
                        while ((getline(insrc, s1)) && (getline(insrc2, s2))) {
                            if (s1 != s2) {
                                bj = 1;
                                break;
                            }
                        }
                        insrc.close();
                        insrc2.close();
                        if (bj) {
                            if (Test_status==1)
                            Test_status = WA;
                        } else {
                            Accuracy++;
                        }
                    }
                } else if(jz){
                    if (Test_status==1)
                    Test_status = TLE;
                    if(Test_status==3)
                    {

                        cout<<"???";
                    }
                    break;
                } else{
                    break;
                }
                if(Test_status==3)
                {
                    cout<<"???";
                }
            }
            if(Test_status==3)
            {

                cout<<"???";
            }
            Accuracy=Accuracy/Data_size;
            questionTestInformation.setAccuracy(Accuracy);
            questionTestInformation.setTestStatus(Test_status);
            questionTestInformation.setRunningTime(Running_time);
            questionTestInformation.setMemoryFootprint(Memory_footprint);
            dataCachePool.Update_Question_Test_Information(questionTestInformation);
        } else {
            questionTestInformation.setTestStatus(CE);
            dataCachePool.Update_Question_Test_Information(questionTestInformation);
        }

        pdjg["Test_id"] = Test_id;
        pdjg["judging_id"] = judging_id;
        string post_str = pdjg.dump();
        epollRequest.post_url(getWebserverurl(), post_str);
        url = "../src/Test_temporary_directory/" + to_string(Test_id);
        ::system(("rm -rf " + url).c_str());
        if (lswj1!="")
        {
            ::system(("rm -rf " + lswj1).c_str());
        }else{
            if(lswj2!="")
            {
                ::system(("rm -rf " + lswj2).c_str());

            }
            if(lswj3!="")
            {
                ::system(("rm -rf " + lswj3).c_str());
            }
        }
    }
}
