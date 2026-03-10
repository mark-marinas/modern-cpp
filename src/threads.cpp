#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

mutex cout_lock;

class Sum {
    private:
        int a, b, sum;
    public:
        Sum() = default;
        Sum(int a, int b): a {a}, b{b} { sum = a + b; }
        Sum& operator=(Sum sum){ this->a = sum.a; this->b=sum.b; this->sum = sum.sum; return *this; }
        int get_sum() { return sum; } 
};

void add(int a, int b, int& sum)
{
    lock_guard<mutex> lg(cout_lock);
    sum = a + b;
    cout << a << "+" << b << "=" << sum << endl;
}

int main()
{
    int sum1, sum2, sum3;
    thread t1 { add, 1, 2, ref(sum1)};
    thread t2 { add, 3, 4, ref(sum2)};
    thread t3 { add, 5, 6, ref(sum3)};

    t1.join(); t2.join(); t3.join();
    cout << sum1 << " " << sum2 << " " << sum3 << endl;

    Sum s1 {5,4};
    Sum s2;
    s2 = s1;
    cout << s2.get_sum() << endl;

}