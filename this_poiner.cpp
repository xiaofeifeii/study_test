#include <iostream>
#include <string>
using namespace std;

class Data
{
public:
    typedef unsigned int index;
    string get() const
    {
        return content;
    };

    string get(index st, index eb)
    {
        char buf[10];
        cout << "st:" << st + 1 << " eb:" << eb + 1 << endl;
        sprintf(buf, "%dand%d", st, eb);
        content = buf;
        return content;
    };

    string content = "start";
    index cursor, top, bottom;
};

class Point
{
public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void MovePoint(int a, int b)
    {
        x = x + a;
        y = y + b;
    }
    void print() { cout << "x=" << x << " y=" << y << endl; }

private:
    int x, y;
};

main()
{
    Data a, *p = &a;
    string Data::*ps = &Data::content;
    string (Data::*pmf)() const = &Data::get;
    typedef string (Data::*GETFUNC)(Data::index, Data::index);
    GETFUNC pfget = &Data::get;
    unsigned int Data::*pt = &Data::top;

    cout << "hello" << endl;
    cout << (p->*pmf)() << endl;
    cout << (a.*pfget)(1, 2)<< "\n" << endl;

    Point pt1(10, 10);
    pt1.print();
    pt1.MovePoint(2, 2);
    pt1.print();
    return 0;
}
