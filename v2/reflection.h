#ifndef _REFLECTION_H_
#define _REFLECTION_H_

#include <boost/any.hpp>
#include <map>
#include <string>

class ObjectFactory{
public:
    virtual boost::any GetInstance()=0;
};

std::map<std::string,std::map<std::string,ObjectFactory*> >& GetReflectionMap();

#define ADD_REFLECT_BASE_CLASS(baseClassName) \
class baseClassName##Reflector { \
public: \
 static baseClassName* GetInstanceByClassName(const std::string& className){ \
     std::map<std::string,ObjectFactory*>& childClassFactoryMap = GetReflectionMap()[#baseClassName]; \
     std::map<std::string,ObjectFactory*>::iterator it = childClassFactoryMap.find(className); \
     if( it != childClassFactoryMap.end()){\
         boost::any instance = it->second->GetInstance(); \
         return boost::any_cast<baseClassName*>(instance);\
     } \
     return NULL; \
 } \
}; \

#define ADD_REFLECT_CLASS(baseClassName,className) \
    class ObjectFactory##baseClassName##className : public ObjectFactory { \
    public: \
        boost::any GetInstance(){ \
            return boost::any(static_cast<baseClassName*>(new className)); \
        } \
    }; \
    void RegistFactory##baseClassName##className(){ \
        GetReflectionMap()[#baseClassName][#className] =new ObjectFactory##baseClassName##className(); \
    } \
    __attribute__((constructor)) void RegistFactory##baseClassName##className();

#endif

