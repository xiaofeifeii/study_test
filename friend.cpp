#include <iostream>
using namespace std;
class B;
class A
{
public:
    A(int _a = 0) : a(_a) {}
    void setb(B &r);

private:
    int a;
};

class B
{
public:
    B(int _b = 0) : b(_b) {}

private:
    int b;
    friend void A::setb(B &r);
    friend A;
};
  
void A::setb(B& r)
{
    r.b=a;
}


class a1:public A{
public:
int val;
};

int main ()
{
    a1 q;
    q.val=0;
    return 0;
}