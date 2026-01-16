#include <iostream>
#include <string>

int hello(const std::string&); //this is called a function declaration

int main() {
    hello("mark marinas");
    return 0;
}

int hello(const std::string& name) { //and this is the function definition
    std::cout << "Hello " << name << std::endl;
    return 0;
}