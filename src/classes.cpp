#include <iostream>
#include <string>


typedef enum COLOR {
    RED,
    WHITE,
    BLUE
} color_t;

class Car {
    private:
        std::string name;
        color_t color;
        std::string make;
        int year;
    public:
        Car(){}
        Car(color_t color, std::string make, int year) : color { color }, make { make }, year {year}  { }
        //Copy constructor
        Car(const Car& another_car): color { another_car.color}, make {another_car.make}, year { another_car.year}, name{ another_car.name} {}
        //Copy assignment
        Car& operator=(const Car& another_car) { this->name = another_car.name; this->color = another_car.color; this->make = another_car.make; this->year = another_car.year; return *this;} 
        //Move constructor. T&& is a reference to a rvalue
        Car(const Car&& rhs): name{std::move(rhs.name)}, color{std::move(rhs.color)}, make{std::move(rhs.make)}, year{std::move(rhs.year)} { }
        //Move assignment
        Car& operator=(const Car&& rhs) { this->name = std::move(rhs.name); this->color = std::move(rhs.color); this->make = std::move(rhs.make); this->year = std::move(rhs.year); return *this; };      
        void info() {
            std::string c;
            switch (color) {
                case RED:
                    c = "RED";
                    break;
                case WHITE:
                    c = "WHITE";
                    break;
                case BLUE:
                    c = "BLUE";
                    break;
                default:
                    c = "BLACK";
                    break;
            }
            std::cout << "Owner:\t" << name << std::endl;
            std::cout << "Color:\t" << color << std::endl;
            std::cout << "Make:\t" << make << std::endl;
            std::cout << "Year:\t" << year << std::endl;
        } 
        void set_name(const std::string name){ this->name = name; }
        
    };

class Fifo {
    #define MAX 4
    private:
        std::string content[MAX];
        int pointer;
    public:
        Fifo(): pointer{0}, content{"","","", "" } {}
        void push(const std::string e) { 
            content[pointer++] = e;
            if (pointer == MAX){ pointer = 0;}
        }
        std::string pop() {
            std::string retval = content[--pointer];
            if (pointer < 0) { pointer = 0;} 
            return retval;
        }
        std::string operator[](int index) {
            return content[index];
        }
};


//Different rules for different operator.
//https://en.cppreference.com/w/cpp/language/operators.html
class Accumulator {
    private:
        int value;
    public:
        Accumulator(): value{0} { };
        int operator+(int increment) {
            value += increment;
            return value;
        }
        int operator+=(int increment) {
            value += increment;
            return value;
        }

        //prefix operator
        int operator++() { 
            value++;
            return value;
        }

        //postfix operator
        int operator++(int n) {
            int old_value{value};
            value++;
            return old_value;
        }

        int operator*(int factor) {
            value *= factor;
            return value;
        }
        int get_value() { return value; }
};

template<typename T>
class Generic {
    public:
        T add(T a, T b);
};

template <typename T>
T Generic<T>::add(T a, T b)
{
    return (a + b);
}

template <>
std::string Generic<std::string>::add(std::string a, std::string b)
{
    return a + ":" + b;
}

int main() {
    Car MyCar { RED, "Honda", 2025};    //calls constructor
    Car MarlaCar = MyCar;               //calls copy constructor
    Car AmbieCar;
    AmbieCar = MyCar;                   //calls copy assignment

    MyCar.set_name("Mark");
    MarlaCar.set_name("Marla");
    AmbieCar.set_name("Ambie");

    MyCar.info();
    MarlaCar.info();
    AmbieCar.info();

    std::cout << "=======" << std::endl;
    Car SoldCar = std::move(MyCar); //calls move constructor
    SoldCar.info();

    Car AnotherSoldCar;
    AnotherSoldCar = std::move(AmbieCar); //calls move assignment
    AnotherSoldCar.info();

    Fifo Marinas;
    Marinas.push("Mark");
    Marinas.push("Marla");
    Marinas.push("Ambie");

    std::cout << "=====" << std::endl;
    std::string me = Marinas[0];
    std::string wife = Marinas[1];
    std::string daughter = Marinas[2];
    std::cout << me << " " << wife << " " << daughter << std::endl;

    daughter = Marinas.pop();
    wife = Marinas.pop();
    me = Marinas.pop();
    std::cout << me << " " << wife << " " << daughter << std::endl;

    Accumulator Acc;
    Acc+=5;
    std::cout << Acc.get_value() << std::endl;

    ++Acc;
    std::cout << Acc++ << std::endl;

    int doubled = Acc*2;
    std::cout << doubled << std::endl;


    Generic<int> nInt;
    Generic<std::string> nStr;
    std::cout << nInt.add(5,10) << " " << nStr.add("hi", "mark") << std::endl;
}