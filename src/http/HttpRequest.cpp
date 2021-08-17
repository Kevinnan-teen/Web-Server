//
// Created by nachr on 2021/8/4
//
#include "../../include/HttpRequest.h"



// 重载HttpRequest <<
std::ostream &operator<<(std::ostream &os, const HttpRequest &request) {
    os << "method:" << request.mMethod << std::endl;
    os << "uri:" << request.mUri << std::endl;
    os << "version:" << request.mVersion << std::endl;
    //os << "content:" << request.mContent << std::endl;
    for (auto it = request.mHeaders.begin(); it != request.mHeaders.end(); it++) {
        os << it->first << ":" << it->second << std::endl;
    }
    return os;
}

