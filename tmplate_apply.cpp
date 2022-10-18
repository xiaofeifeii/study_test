#include<iostream>
using namespace std;

template <class T>
class Compare{
public :
    Compare(T a,T b){x=a;y=b;}
    T max(){return (x>y)?x:y;}
    T min(){return (x<y)?x:y;}
private :
    T x,y;
};

template <class T>
class Array
{
public:
    Array(int c){arr=new T[c];}
    T& operator[](int i){return arr[i];}
    ~Array(){delete arr;}
private:
    T *arr;
};


int main()
{
    Compare<int> a(4,7);
    cout<<"a.max:"<<a.max()<<"  a.min:"<<a.min()<<endl;

    Compare<double> b(4.3333,2.11117);
    cout<<"b.max:"<<b.max()<<"  b.min:"<<b.min()<<endl;
    
    int i;
    Array<int> array(5);
    for(i=0;i<5;i++) cin>>array[i];
    for ( i = 0; i < 5; i++)
    {
     cout<<"array["<<i<<"]:"<<array[i]<<endl;
    }

    Array<float> a1(8);
    for(i=0;i<8;i++) {
        a1[i]=i*0.1;
    }

    for(i=0;i<8;i++) {
        cout<<"a1["<<i<<"]:"<<a1[i]<<endl;
    }

    cout<<endl;
    return 0;

}