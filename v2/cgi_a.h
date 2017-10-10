#include "reflection.h"
#include "base_cgi.h"
#include <iostream>
using namespace std;

class CGI_A : public BaseCGI{
    public:
        int Process(){
            cout << "cgi_a running " << endl; 
            return 0;
        }
};

ADD_REFLECT_CLASS(BaseCGI,CGI_A);

