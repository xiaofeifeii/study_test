#include <iostream>
using namespace std;

class Base
{
public:
    virtual void print() { cout << "Base" << endl; }
};

class Derived : public Base
{
public:
    void print() { cout << "Derived" << endl; }
};

class Derived2 : public Base
{
public:
    void print() { cout << "Derived2" << endl; }
};

class Derived3 : public Base
{
public:
    void print() { cout << "Derived3" << endl; }
};

class Derived4 : public Base
{
public:
    void print() { cout << "Derived4" << endl; }
};

class Derived5 : public Base
{
public:
    void print() { cout << "Derived5" << endl; }
};

class Derived6 : public Base
{
public:
    void print() { cout << "Derived6" << endl; }
};

void display(Base *p)
{
    p->print();
}

template <typename T>
void swap1(T &a, T &b)
{

    cout << "a=" << a << "b=" << b << endl;
    T t;
    t = a;
    a = b;
    b = t;
}

// int CompareDemo<T>::compare(const T &a, const T &b)

int main(int argc, char const *argv[])
{

    Derived d;
    Derived2 d2;
    Derived3 d3;
    Derived4 d4;
    Derived5 d5;
    Derived6 d6;
    Base b;

    display(&b);
    display(&d);
    display(&d2);
    display(&d3);
    display(&d4);
    display(&d5);
    display(&d6);

    float x1 = 1.05;
    float y1 = 2.01;
    swap1<float>(x1, y1);
    cout << "x1=" << x1 <<' '<< "y1=" << y1 << endl;
    int x2 = 1;
    int y2 = 2;
    swap1<int>(x2, y2);
    cout << "x2=" << x2 <<' '<< "y2=" << y2 << endl;
    return 0;
}
