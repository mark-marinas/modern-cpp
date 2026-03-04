#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

class Name {
    private:
        string first, last;
    public:
        Name(string fname, string lname): first{fname}, last{lname} {};
        string get_fullname() { return  first + " " + last; } 
};

template<typename T>
T sub(T a) {
    return -1*a;
}

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

    map<string, int> ages {{"c", 47}, {"a", 21 }, {"v", 46}};
    for (const auto& age: ages) {
        cout << age.first << " " << age.second << endl;
    }
    cout << endl;

    vector< pair<string, int> > vAges;
     for (const auto& age: ages) {
        vAges.push_back(make_pair(age.first, age.second));
    }   

    sort(vAges.begin(), vAges.end(), []( auto a, auto b  ){ return a.second < b.second; });
    for (const auto& el: vAges) {
        cout << el.first << " " << el.second << endl;
    }
    cout << endl;


    map<string, string> roles { {"father", "mark"}, {"mother", "marla"}, {"daughter", "ambie" } };
    roles["son"] = "Miguel";
    if ( roles.find("son") != std::end(roles)) { roles.erase(roles.find("son"));}
    for (const auto& role: roles) {
        cout << role.first << "=" << role.second << endl;
    }
}