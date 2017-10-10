#include "reflection.h"

using namespace std;

map<string,ObjectFactory*>& GetReflectionMap(){
    static map<string,ObjectFactory*>* reflectionMap = new map<string,ObjectFactory*>();
    return *reflectionMap;
}

boost::any GetInstanceByClassName(const string& className){
    if(GetReflectionMap().find(className)!=GetReflectionMap().end()){
        return GetReflectionMap()[className]->GetInstance(); 
    }
    return NULL;
}

