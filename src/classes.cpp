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
        Car(const Car& another_car): color { another_car.color}, make {another_car.make}, year { another_car.year} {}
        //Copy assignment
        Car& operator=(const Car& another_car) { this->color = another_car.color; this->make = another_car.make; this->year = another_car.year; return *this;} 
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
        void set_name(std::string name){ this->name = name; }
    };


int main() {
    Car MyCar { RED, "Honda", 2025};
    Car MarlaCar = MyCar;
    Car AmbieCar;
    AmbieCar = MyCar;

    MyCar.set_name("Mark");
    MarlaCar.set_name("Marla");
    AmbieCar.set_name("Ambie");

    MyCar.info();
    MarlaCar.info();
    AmbieCar.info();

}