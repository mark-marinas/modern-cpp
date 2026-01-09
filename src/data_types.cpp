#include <iostream>

int main(int argc, char **argv) { 
    char a = 'a';
    bool yes = true;
    unsigned long int nNum = 0; //unsigned and long are modifiers
    double pi = 3.14;

    std::cout << "sizeof(char)" << sizeof(char) << std::endl;
    std::cout << "sizeof(bool)" << sizeof(bool) << std::endl;
    std::cout << "sizeof(int)" << sizeof(int) << std::endl;
    std::cout << "sizeof(double)" << sizeof(double) << std::endl;

    int nNum1 = {1}, nNum2{2}, nNum3 = 3; //different type of initializations
    std::cout << nNum1 << " " << nNum2 << " " << nNum3 << std::endl; 

    double half = nNum1/float(2);
    std::cout << half << std::endl;

    int xpp = nNum1++;
    nNum1 = 1;
    int ppx = ++nNum1;

    std::cout << xpp << " " << ppx << " " << nNum1 << std::endl;

    return 0;
}