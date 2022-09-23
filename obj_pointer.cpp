#include <iostream>
using namespace std;

class Time
{
public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
    void set(int h = 0, int m = 0, int s = 0)
    {
        hour = h, minute = m, second = s;
    }
    void display()
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }
    int hour, minute, second;
};

int main()
{
    Time now(12, 0, 0), *pt;
    pt = &now;
    pt->display();

    pt->set(13, 13, 0);
    pt->display();
    pt->hour = 1;
    pt->display();
    now.hour=5;
    now.minute=2;
    now.second=50;
    now.display();
    return 0;
}