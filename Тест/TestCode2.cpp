#include <iostream>

using namespace std;

class A
{
protected:
    int a;

public:
    A() : a(0) { cout << "constructor A" << endl; }
    A(int p) : a(p) { cout << "constructor A with p" << endl; }
    void print()
    {
        cout << "class A" << endl;
    }
};
class B : public A
{
public:
    int b;
    B() : b(0) { cout << "constructor B" << endl; }
    B(int p) : A(p), b(p) { cout << "constructor B with p" << endl; }
    void set(int b1)
    {
        b1 = b;
    }
    void print(string str)
    {
        cout << str << endl;
        A::print();
    }
};

int main()
{
    B obj1;
    B obj2(7);
    // obj2.b=8;
    // B *f=new B(9);
}
