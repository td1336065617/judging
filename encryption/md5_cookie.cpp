//
// Created by fspst on 23-5-5.
//
#include "encryption.h"

using namespace CryptoPP;
namespace cry {
    std::string encryption::md5_cookie(std::string str) {
        std::string md5_str;
        MD5 md5;
        HashFilter hf(md5,new HexEncoder(new StringSink(md5_str)));
        hf.Put(reinterpret_cast<const unsigned char*>(str.c_str()), str.length());
        hf.MessageEnd();
        return md5_str;
    }
}