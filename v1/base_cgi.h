#ifndef _BASE_CGI_CLASS_
#define _BASE_CGI_CLASS_
#include "reflect.h"
/**
 * 业务逻辑的基类
 */
class BaseCGI{
public:
    virtual int BeforeProcess()=0;
    virtual int Process() = 0;
    virtual int AfterProcess()= 0;
};

#endif
