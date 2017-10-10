#include "reflection.h"
#include "base_cgi.h"
#include <iostream>
using namespace std;

struct CGI_A_Req{
    int value;
};

struct CGI_A_Resp{
    int value;
};

class CGI_A : public BaseCGI{
    public:
        CGI_A(CGI_A_Req* req,CGI_A_Resp* resp):
            m_req(req),m_resp(resp){}
        int Process(){
            cout << "cgi_a running " << endl; 
            cout << "req.value="<<m_req->value << endl;
            return 0;
        }
    private:
        CGI_A_Req* m_req;
        CGI_A_Resp* m_resp;
};

ADD_REFLECT_CLASS(BaseCGI,CGI_A,CGI_A_Req,CGI_A_Resp);

