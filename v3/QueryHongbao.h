#include "query_base.h"
#include "reflection.h"

#include <iostream>

class QueryHongbao : public QueryBase {
    public:
        int DoCheck(){
            std::cout << "QueryHomgbao check session " << std::endl; 
            return 0;
        }
        int DoQuery(){
            std::cout << "QueryHongbao .. " << std::endl;
            return 0;
        }
};
ADD_REFLECT_CLASS(QueryBase,QueryHongbao);

