#include <iostream>
using namespace std;

class A
{
protected:
    int a;

public:
    A() : a(0) { cout << "конструктор A" << endl; }
    A(int p) : a(p) { cout << "конструктор A c p" << endl; }
    void print()
    {
        cout << "class A" << endl;
    }
    virtual void draw() = 0;
};
class B : public A
{
public:
    int b;
    B() : b(0) { cout << "конструктор B" << endl; }
    B(int p) : A(p), b(p) { cout << "конструктор B c p" << endl; }
    void set(int b1)
    {
        b1 = b;
    }
    void print(string str)
    {
        cout << str << endl;
        A::print();
    }
    virtual void draw() { cout << "virtual" << endl; }
};

int main()
{
    B *f;
    f = new B(9);

    A objA;
}
