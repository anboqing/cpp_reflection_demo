#ifndef _REFLECTION_H_
#define _REFLECTION_H_

#include <boost/any.hpp>
#include <map>
#include <string>

class ObjectFactory{
public:
    virtual boost::any GetInstance()=0;
};

std::map<std::string,ObjectFactory*>& GetReflectionMap();

boost::any GetInstanceByClassName(const std::string& className);

#define ADD_REFLECT_CLASS(className) \
    class ObjectFactory##className : public ObjectFactory { \
    public: \
        boost::any GetInstance(){ \
            return boost::any(new className); \
        } \
    }; \
    void RegistFactory##className(){ \
        GetReflectionMap()[#className]=new ObjectFactory##className(); \
    } \
    __attribute__((constructor)) void RegistFactory##className();


#endif

