#include "reflection.h"
#include <iostream>
using namespace std;

class CGI_A{
    public:
        void run(){
            cout << "cgi_a running " << endl; 
        }
};

ADD_REFLECT_CLASS(CGI_A);

