#include <iostream>
#include <memory>
#include <string> 

using namespace std;


class Base {
    public:
        void virtual print_message() { cout << "hello from base" << endl;}
};

class Derived: public Base {
    private:
        string name;
    public:
        void print_message() override { cout << "hello " << name << endl; } 
        Derived(string name): name(name) { }
};

int main()
{
    unique_ptr<Base> ptr = make_unique<Derived>("Marla");
    ptr->print_message();

    shared_ptr<Base> oPtr = make_shared<Derived>("Mark");
    shared_ptr<Base> ptr2 = oPtr; 
    shared_ptr<Base> ptr3 = ptr2; //this doesnt work on unique ptr because a unique_ptr points to only 1 object.
    ptr3->print_message();
    cout << (oPtr == ptr2) << endl;

    return 0;

}