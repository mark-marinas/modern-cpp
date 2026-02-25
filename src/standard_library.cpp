#include <iostream>
#include <array>
#include <vector>

using namespace std;

class Name {
    private:
        string first, last;
    public:
        Name(string fname, string lname): first{fname}, last{lname} {};
        string get_fullname() { return  first + " " + last; } 
};

/*
template<size_t SIZE>
void print_names(array<Name, SIZE>& n)
{
    for (int i=0; i<n.size(); i++) {
        cout << n.at(i).get_fullname() << endl;
    }
}
*/
void print_names(const vector<Name>& names) {
    for (auto name: names) {
        cout << name.get_fullname() << endl;
    }
}

int main()
{
    //array<Name, 3> Marinas { Name{"mark", "marinas" }, Name{"marla", "marinas"}, Name{"Mikaela", "Marinas"} };
    vector<Name> Marinas { Name{"mark", "marinas" }, Name{"marla", "marinas"}, Name{"Mikaela", "Marinas"} }; 
    print_names(Marinas);

}