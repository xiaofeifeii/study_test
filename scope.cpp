#include <iostream>
using namespace std;
class A
{
public:
    int n;
    A(int _n = 10) : n(_n) { cout << "A(" << n << ")构造\t"; }
    ~A() { cout << "A(" << n << ")析构\t"; }
};

class B
{
public:
    int m;
    B(int _n = 10) : m(_n), a(_n) { cout << "B(" << m << ")构造" << endl; }
    ~B() { cout << "B(" << m << ")析构" << endl; }
    A a;                           //嵌套类
};

B *gp, gb(30);                     //全局对象

void fun4()
{
    static B b41(41);              //静态局部对象
    B b42(42);                     //局部对象
    gp = new B(43);                //自由存储对象
}

void fun5()
{
    static B b51(51);              //静态局部对象
    B b52(52);                     //局部对象
}

B fun6(B b61)
{
    delete gp;                      //释放自由存储对象
    return b61;
}

int main()
{
    cout << "----------------main  start---------------------" << endl;
    fun4();
    cout << "\n---------------fun4 end-----------------------" << endl;
    fun5();
    cout << "\n---------------fun5 end-----------------------" << endl;
    B b71(71), b72(72);              //局部对象
    b72 = fun6(b71);                 //函数返回临时对象
    cout << "\n----------------main end----------------------" << endl;
    return 0;
}