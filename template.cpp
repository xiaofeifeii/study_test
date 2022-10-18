#include <iostream>
using namespace std;

template <typename T>
void swap1(T &a, T &b)
{
    T tem;
    tem = a;
    a = b;
    b = tem;
}

template <class T>
class Point
{
private:
    T x, y;

public:
    Point() : x(0), y(0) {}
    Point(const T a, const T b) : x(a), y(b) {}
    void set(const T a, const T b);
    void Display()
    {
        cout << "Display:x=" << x << " y=" << y << endl;
    }
};

template <class T>
void Point<T>::set(const T a, const T b)
{
    x = a, y = b;
}

template <class T, int N>
class Sequence
{
public:
    void set(int i, T value);
    T Get(int i) { return array[i]; }

private:
    T array[N];
};

template<class T,int N>
void Sequence<T,N>::set(int i ,T value)
{
    array[i]=value;
}


int main(int argc, char const *argv[])
{
    int a = 11, b = 22;
    float c = 1.34, d = 2.98;
    swap1<int>(a, b);
    cout << "a=" << a << " "
         << "b=" << b << endl;
    swap1<float>(c, d);
    cout << "c=" << c << " "
         << "d=" << d << endl;

    Point<int> x, y;
    Point<double> m(1.22222, 2.3333333), n(3.4444, 4.11111);
    m.Display();
    x.Display();
    x.set(8, 9);
    x.Display();
    m.set(2.444, 5.111);
    m.Display();
    y.Display();

    Sequence <int,5> s;
    Sequence <double,5> bb;
    for (int i = 0; i < 5; i++)
    {
        s.set(i,i);
    }

    for (int i = 0; i < 5; i++)
    {
        bb.set(i,i*0.001);
    }

    for (int i = 0; i < 5; i++)
    {
        cout<<"bb:"<<bb.Get(i)<<endl;
    }

    for (int i = 0; i < 5; i++)
    {
        cout<<"s:"<<s.Get(i)<<endl;
    }
    
    

    return 0;
}
