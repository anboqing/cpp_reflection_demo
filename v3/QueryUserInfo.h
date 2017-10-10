#include "reflection.h"
#include "query_base.h"

#include <iostream>

struct MockReq{
    int value;
};

struct MockResp{
    int value;
};

class QueryUserInfo : public QueryBase {
    public:
        QueryUserInfo(MockReq* req,MockResp* resp) : m_req(req),m_resp(resp){}
        int DoCheck(){
            std::cout << "Check QueryUserInfo param" << std::endl; 
            std::cout << "req.value = " << m_req->value << std::endl;
            return 0;
        }
        int DoQuery(){
            std::cout << "QueryUserInfo" << std::endl;            
            m_resp->value = 2;
            return 0;
        }
    private:
        MockReq *m_req;
        MockResp *m_resp;
};

ADD_REFLECT_CLASS(QueryBase,QueryUserInfo,MockReq,MockResp);


