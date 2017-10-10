#include "reflection.h"

using namespace std;

map<string , map<string,ObjectFactory*> >& GetReflectionMap(){
    static map<string,map<string,ObjectFactory*> >* reflectionMap = new map<string,map<string,ObjectFactory*> >();
    return *reflectionMap;
}


