#include "reflection.h"
#include <iostream>
using namespace std;

class CGI_B{
    public:
        void run(){
            cout << "cgi 2 running " << endl; 
        }
};

ADD_REFLECT_CLASS(CGI_B);

