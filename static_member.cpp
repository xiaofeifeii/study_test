#include <iostream>
using namespace std;

class test
{
private:
    int x;
    int y;

public:
    static int num;
    static int Getnum()
    {
        // x+=5;
        num += 15;
        return num;
    }
};

class CTest
{
public:
    CTest()
    {
        s_total++;
        id = s_total;
        cout << "构造" << id << "  ";
    }
    ~CTest()
    {
        s_total--;
        cout << "析构" << id << "  ";
    }
    static int getTotal() { return s_total; }

private:
    static int s_total;
    int id;
};

class test2
{
public:
    void init() {}
    static void output() { cout << "\n"<< x << endl; }

private:
    static int x;
};

int test::num = 10;
int CTest::s_total = 0;
int test2::x=0;


int main()
{
    test a;
    cout << test::num << endl;
    test::num = 20;
    cout << test::num << endl;
    cout << test::Getnum() << endl;
    cout << a.Getnum() << endl << endl;

    CTest a1, b2, c3;
    CTest *p = new CTest;
    cout << "\n合计=" << CTest::getTotal() << " " << endl;
    delete p;
    cout << "\n合计=" << a1.getTotal() << " " << endl;

    test2 t;
    t.init();
    t.output();
    test2::output();

    return 0;
}
