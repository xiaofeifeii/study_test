#include <iostream>
#include <stdlib.h>

using namespace std;

enum ErrorType
{
    invalidArraySize,
    memoryAllocationError,
    indexOutOfRange
};

const char *errorMsg[] = {"invalid array size", "memory allocation error", "invalid index "};

template <class T>
class Array
{
private:
    T *alist;
    int size;
    void Error(ErrorType error, int badIndex = 0) const;

public:
    Array(int sz = 50);
    Array(const Array<T> &A);
    ~Array(void);
    Array<T> &operator=(const Array<T> &rhs);
    T &operator[](int);
    operator T *() const;
    int ListSize() const;
    void Resize(int sz);
};

template <class T>
void Array<T>::Error(ErrorType error, int badIndex) const
{
    cout << errorMsg[error];
    if (error == indexOutOfRange)
    {
        cout << badIndex;
    }
    cout << endl;
    exit(1);
}

template <class T>
Array<T>::Array(int sz)
{
    if (sz <= 0)
        Error(invalidArraySize);
    else
    {
        size = sz;
        alist = new T[size];
        if (alist == NULL)
            Error(memoryAllocationError);
    }
}

template <class T>
Array<T>::Array(const Array<T> &X)
{
    int n = X.size;
    size = n;
    alist = new T[n];
    if (alist == NULL)
        Error(memoryAllocationError);
    T *srcptr = X.alist;
    T *destptr = alist;
    while (n--)
        *destptr++ = *srcptr++;
}

template <class T>
Array<T>::~Array()
{
    delete[] alist;
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
    int n = rhs.size;
    if (size != n)
    {
        delete[] alist;
        alist = new T[n];
        if (alist == NULL)
            Error(memoryAllocationError);
        size = n;
    }
    T *srcptr = rhs.alist;
    T *destptr = alist;
    while (n--)
        *destptr++ = *srcptr++;
    return *this;
}

template <class T>
T &Array<T>::operator[](int n)
{
    if (n < 0 || n > size - 1)
        Error(indexOutOfRange, n);
    return alist[n];
}

template <class T>
Array<T>::operator T *() const
{
    return alist;
}

template <class T>
int Array<T>::ListSize() const
{
    return size;
}

template <class T>
void Array<T>::Resize(int sz)
{
    if (sz <= 0)
        Error(invalidArraySize);
    if (sz == size)
        return;
    T *newlist = new T[sz];
    if (newlist == NULL)
        Error(memoryAllocationError);
    int n = (sz <= size) ? sz : size;
    T *srcptr = alist;
    T *destptr = newlist;
    while (n--)
        *destptr++ = *srcptr++;
    delete[] alist;
    alist = newlist;
    size = sz;
}
int main(int argc, char const *argv[])
{
    int i, *p;
    Array<int> a(5);
    for (int i = 0; i < 5; i++)
        a[i] = i * 10;
    cout << "a[i]: ";
    for (int i = 0; i < 5; i++)
        cout << a[i] << ' ';
    cout << endl;
    Array<int> b = a;
    cout << "b[i]: ";
    for (int i = 0; i < 5; i++)
        cout << a[i] << ' ';
    cout << endl;
    a.Resize(10);
    cout << "reset:";
    for (p = a; p < a + 10; p++)
        cout << *p << " ";
    return 0;
}
