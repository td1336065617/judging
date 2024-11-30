//
// Created by fspst on 23-5-5.
//
#include "../xt_heard/xt_heard.h"
#include"crypto++/md5.h"
#include"crypto++/hex.h"
#include"crypto++/filters.h"
#include"crypto++/files.h"
#ifndef CESHI1_ENCRYPTION_H
#define CESHI1_ENCRYPTION_H

namespace cry {

    class encryption {
    public:
        encryption();
        ~encryption();
        std::string md5_jm(std::string str);
    private:
        std::string md5_cookie(std::string str);
    };
} // cry

#endif //CESHI1_ENCRYPTION_H
