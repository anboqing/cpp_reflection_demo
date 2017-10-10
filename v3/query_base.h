#ifndef _QUERY_BASE_H_
#define _QUERY_BASE_H_
#include "reflection.h"
#include <iostream>

class QueryBase{
public:
    virtual int DoCheck(){
        // 做一些参数检查
        // 权限校验: eg. checksession
        return 0;
    }
    virtual int DoQuery(){
        // 查询逻辑
        return 0; 
    }
    virtual int DoClean(){
        // 释放资源
        return 0;    
    }
};

ADD_REFLECT_BASE_CLASS(QueryBase);

#endif
