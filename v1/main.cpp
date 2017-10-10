#include "reflection.h"
#include "cgi_a.h"
#include "cgi_b.h"
#include <iostream>
using namespace std;

int main(){
    boost::any instance = GetInstanceByClassName("CGI_A");   
    boost::any instance2 = GetInstanceByClassName("CGI_B");   
    CGI_A* objCGI_A = boost::any_cast<CGI_A*>(instance);
    CGI_B* objCGI_B = boost::any_cast<CGI_B*>(instance2);
    objCGI_A->run();
    objCGI_B->run();
    return 0;
}
