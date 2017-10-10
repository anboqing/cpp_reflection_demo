#ifndef _REFLECTION_H_
#define _REFLECTION_H_

#include <boost/any.hpp>
#include <map>
#include <string>

class ObjectFactory{
public:
    virtual boost::any GetInstance(boost::any& req,boost::any& resp)=0;
};

std::map<std::string,std::map<std::string,ObjectFactory*> >& GetReflectionMap();

#define ADD_REFLECT_BASE_CLASS(baseClassName) \
class baseClassName##Reflector { \
public: \
 static baseClassName* GetInstanceByClassName(const std::string& className, \
         boost::any& req, \
         boost::any& resp){ \
     std::map<std::string,ObjectFactory*>& childClassFactoryMap = GetReflectionMap()[#baseClassName]; \
     std::map<std::string,ObjectFactory*>::iterator it = childClassFactoryMap.find(className); \
     if( it != childClassFactoryMap.end()){\
         boost::any instance = it->second->GetInstance(req,resp); \
         return boost::any_cast<baseClassName*>(instance);\
     } \
     return NULL; \
 } \
}; \

#define ADD_REFLECT_CLASS(baseClassName,className,reqClassName,respClassName) \
    class ObjectFactory##baseClassName##className : public ObjectFactory { \
    public: \
        ObjectFactory##baseClassName##className(){} \
        boost::any GetInstance(boost::any& req,boost::any& resp){ \
            reqClassName* pReq = boost::any_cast<reqClassName*>(req); \
            respClassName* pResp = boost::any_cast<respClassName*>(resp); \
            className* obj = new className(pReq,pResp); \
            return boost::any(static_cast<baseClassName*>(obj)); \
        } \
    }; \
    void RegistFactory##baseClassName##className(){ \
        GetReflectionMap()[#baseClassName][#className] =new ObjectFactory##baseClassName##className(); \
    } \
    __attribute__((constructor)) void RegistFactory##baseClassName##className();

#endif

