#include <iostream>
#include <memory>

using namespace std;


class Base {
    public:
        void virtual print_message() { cout << "hello from base" << endl;}
};

class Derived: public Base {
    public:
        void print_message() override { cout << "hello from derived" << endl; } 
};

int main()
{
    unique_ptr<Base> ptr = make_unique<Derived>();
    ptr->print_message();
    return 0;

}