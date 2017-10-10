#ifndef _BASE_CGI_CLASS_
#define _BASE_CGI_CLASS_
#include "reflection.h"

/**
 * 业务逻辑的基类
 */
class BaseCGI{
public:
    virtual int BeforeProcess() {
        return 0;      
    }
    virtual int Process() = 0;
    virtual int AfterProcess() {
        return 0; 
    }
};

ADD_REFLECT_BASE_CLASS(BaseCGI);

#endif
