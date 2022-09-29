#include <iostream>
using namespace std;

class Base1
{
private:
    int b1;

public:
    Base1()
    {
        b1 = 0;
        cout << "默认构造函数Base1 b1= " << b1 << endl;
    }
    Base1(int i)
    {
        b1 = i;
        cout << "构造函数Base1 b1= " << b1 << endl;
    }
    void fun(){
        cout<<"Base1 fun"<<endl;
    }
};

class Base2
{
private:
    int b2;

public:
    Base2()
    {
        b2 = 0;
        cout << "默认构造函数Base2 b2= " << b2 << endl;
    }
    Base2(int i)
    {
        b2 = i;
        cout << "构造函数Base2 b2= " << b2 << endl;
    }
    void fun(){
        cout<<"Base2 fun"<<endl;
    }
    void gun(){
        cout<<"Base2 gun"<<endl;
    }
};
class Base3
{
public:
    Base3()
    {
        cout << "默认构造函数Base3  " << endl;
    }
};

class Derive : public Base1, public Base2, public Base3
{
private:
    Base1 memberBase1;
    Base2 memberBase2;
    Base3 memberBase3;

public:
    Derive() { cout << "默认构造函数Derive." << endl; }
    Derive(int a, int b, int c, int d) : Base1(a), Base2(b), memberBase1(c), memberBase2(d)
    {
        cout << "构造函数Derive." << endl;
    }
    void gun(){
        cout<<"Derive fun"<<endl;
    }
};

int main()
{
    cout << "\n创建派生类对象obj1: " << endl;
    Derive obj1;
    cout << "\n创建派生类对象obj2(1,2,3,4): " << endl;
    Derive obj2(1, 2, 3, 4);
    return 0;

}








