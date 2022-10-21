#include <iostream>
#include <stdlib.h>

using namespace std;

enum ErrorType
{
    invalidArraySize,
    memoryAllocationError,
    indexOutOfRange
};

char *errorMsg[]={
    "invalid array size",
    "memory allocation error",
    "invalid index "
};

template <class T>
class Array
{
    T *alist;
    int size;
    void Error(ErrorType error ,int badIndex=0) const;
public:
    Array(int sz=50);
    Array(const Array<T>& A);
    ~Array(void);
};