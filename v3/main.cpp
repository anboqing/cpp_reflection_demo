#include "reflection.h"
#include "base_cgi.h"
#include "cgi_a.h"
#include "query_base.h"
#include "QueryUserInfo.h"
#include <iostream>
using namespace std;

int main(){
    MockReq req;
    req.value=1;
    MockResp resp;
    boost::any oReq(&req);
    boost::any oResp(&resp);
    QueryBase* pobjQueryUserInfo = QueryBaseReflector::GetInstanceByClassName("QueryUserInfo",oReq,oResp);
    pobjQueryUserInfo->DoCheck();
    pobjQueryUserInfo->DoQuery();
    cout <<"after query resp.value="<<resp.value << endl;

    CGI_A_Req reqa;
    CGI_A_Resp respa;
    reqa.value = 111;
    boost::any oReqa(&reqa);
    boost::any oRespa(&respa);
    BaseCGI* pobjCGIA = BaseCGIReflector::GetInstanceByClassName("CGI_A",oReqa,oRespa);
    pobjCGIA->Process();

    return 0;
}
