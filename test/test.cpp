#include <boost/any.hpp>
#include <iostream>
using namespace std;

class Base{
public:
    virtual void run(){
        cout << "base run" << endl; 
    }
};

class Extend : public Base {
    public:
        void run(){
            cout << "extend run " <<endl;
        }
};

boost::any getInstance(){
    return boost::any(static_cast<Base*>(new Extend())); 
}

int main(){
    //Extend* pextend = boost::any_cast<Extend*>(getInstance());
    //pextend->run();
    Base* pbase = boost::any_cast<Base*>(getInstance());
    pbase->run();
}
