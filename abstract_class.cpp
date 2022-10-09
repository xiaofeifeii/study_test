#include <iostream>
using namespace std;
class Base
{
public:
    Base(){};
    virtual ~Base(){};
    virtual void fun() { cout << "in class Base!" << endl; }
};
class Derived : public Base
{
public:
    Derived(){};
    ~Derived() { cout << "the destructor of class Derived!" << endl; }
    void fun() { cout << "in class Derived!" << endl; };
};

class Sharp
{
public:
    virtual double area() = 0;  //纯虚函数
    virtual double volum() = 0; //纯虚函数
};

class Circle : public Sharp
{
public:
    Circle(double a) : r(a) {}
    virtual double area() { return 2 * 3.1415926 * r; } //虚函数
    virtual double volumn() { return 0; }               //虚函数

private:
    double r;
};

class Cylinder : public Circle
{
private:
    double h;
public:
    Cylinder(double a, double b) : Circle(a), h(b) {}
    virtual double volumn() { return area() * h; }
};

int main(int argc, char const *argv[])
{
    // Base *pTest=new Derived;
    Base *pTest = new Base;
    pTest->fun();
    delete pTest;

    Circle cir(10.5);
    Cylinder b(5.0, 10.0);
    cout << "a.area=" << cir.area() << "," << "a.volum=" << cir.volumn() << endl;
    Sharp *pb;
    pb = &b;
    cout << "b.area=" << pb->area() << "," << "pb.volum=" << pb->volumn() << endl;

    return 0;
}
