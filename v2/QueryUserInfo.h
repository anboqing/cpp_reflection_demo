#include "reflection.h"
#include "query_base.h"

#include <iostream>

class QueryUserInfo : public QueryBase {
    public:
        int DoCheck(){
            std::cout << "Check QueryUserInfo param" << std::endl; 
            return 0;
        }
        int DoQuery(){
            std::cout << "QueryUserInfo" << std::endl;            
            return 0;
        }
};

ADD_REFLECT_CLASS(QueryBase,QueryUserInfo);


