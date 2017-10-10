#include "reflection.h"
#include "base_cgi.h"
#include <iostream>
using namespace std;

class CGI_B : public BaseCGI{
    public:
        int Process(){
            cout << "cgi_b running " << endl; 
            return 0;
        }
};

ADD_REFLECT_CLASS(BaseCGI,CGI_B);

