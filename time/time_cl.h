//
// Created by fspst on 23-6-14.
//
#include "string"
#include "time.h"
#include "../Time_data/Time_data.h"

#ifndef BOOT_CPP_TIME_CL_H
#define BOOT_CPP_TIME_CL_H


class time_cl {
    //1970至今的秒 反时间字符串
public:
    std::string get_time(time_t now,Time_data &timeData);  //转换成mysql可以存的
    std::string get_time2(time_t now,Time_data &timeData);
};


#endif //BOOT_CPP_TIME_CL_H
