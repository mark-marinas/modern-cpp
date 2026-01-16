#include <iostream>
#include <string>

int main(int argc, char **argv) { 
    /*
    instead of cin, just use getline. Put everything to a string buffer, and just convert to another data_type;
    */

    std::string buffer;
    std::string full_name;
    int age;
    // std::cout << "Enter your first name, last name, age (separated by space):";
    // std::cin >> fname >> lname >> age;
    // std::cout << "Hello " << fname.append("_").append(lname) << ":" << age << std::endl;  

    // std::string full_name;
    // getline(std::cin, full_name); //needed because the carriage return from the previous line was considered a string.
    
    // std::cout << "Enter your first name, last name, age (separated by space)(2):";
    // getline(std::cin, full_name);
    // std::cout << full_name << std::endl;

    // std::cout << "Enter your first name, last name, age (separated by space)(3):";
    // getline(std::cin, full_name);
    // std::cout << full_name << std::endl;

    std::cout << "Enter your name:\t" ;
    getline(std::cin, buffer);
    full_name = buffer;

    std::cout << "Enter your age:\t";
    getline(std::cin, buffer);
    age = atoi(buffer.c_str());

    std::cout << "Hello " << full_name << std::endl;
    std::cout << "In 10 years, you will be " << (age+10) << " years old" << std::endl;

    std::cout << "Enter string:\t";
    getline(std::cin, buffer );
    std::string haystack = buffer;

    std::cout << "Enter string to find:\t";
    getline(std::cin, buffer);
    std::string needle = buffer;

    size_t position = haystack.find(needle);
    if (position != std::string::npos) {
        std::cout << needle << " is found at position " << position << std::endl;
        std::string prefix = haystack.substr(0, position); 
        std::cout << "The prefix is " << prefix << std::endl;
    } else {
        std::cout << needle << " not found" << std::endl;
    }

    return 0;
}
