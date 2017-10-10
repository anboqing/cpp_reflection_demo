#include "reflection.h"
#include "cgi_a.h"
#include "cgi_b.h"
#include "base_cgi.h"
#include "query_base.h"
#include "QueryUserInfo.h"
#include "QueryHongbao.h"
#include <iostream>
using namespace std;

int main(){
    BaseCGI* pobjCgiA = BaseCGIReflector::GetInstanceByClassName("CGI_A");
    pobjCgiA->Process();

    BaseCGI* pobjCgiB = BaseCGIReflector::GetInstanceByClassName("CGI_B");
    pobjCgiB->Process();

    QueryBase* pobjQueryUserInfo = QueryBaseReflector::GetInstanceByClassName("QueryUserInfo");
    pobjQueryUserInfo->DoCheck();
    pobjQueryUserInfo->DoQuery();
    QueryBase* pobjQueryHongbao = QueryBaseReflector::GetInstanceByClassName("QueryHongbao");
    pobjQueryHongbao->DoCheck();
    pobjQueryHongbao->DoQuery();


    return 0;
}
