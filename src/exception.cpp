#include <iostream>

int main(int argc, char ** argv)
{
    std::string exc_type{argv[1]};

    try {
        if ( exc_type == "int") { throw 1; }
        else if (exc_type == "dbl") { throw 1.0;}
    }
    catch (int x) {
        std::cout << "exception of int type" << std::endl;
    }
    catch (double x) {
        std::cout << "exception of dbl type" << std::endl;
    }

    return 0;
}