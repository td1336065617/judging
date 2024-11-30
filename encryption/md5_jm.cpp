//
// Created by fspst on 23-5-5.
//
#include "encryption.h"
using namespace CryptoPP;
namespace cry {
    std::string encryption::md5_jm(std::string str) {
        for (int i=0;i<10;i++) {
            str=md5_cookie(str);
        }
        return str;
    }
}