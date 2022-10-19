#include <vector>
#include <iostream>

using namespace std;

void display(vector<int> arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void debug(string s)
{
    cout << s << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> v1, v2;
    int A[] = {1949, 10, 1}, i;
    vector<int>::iterator It;
    v1.assign(A, A + 3); // V1:1949 10 1
    v2.assign(3, 10);    // v2:10 10 10
    debug("v1");
    display(v1);
    debug("v2");
    display(v2);
    for (i = 1; i <= 5; i++)
    {
        v1.push_back(i);
    }
    debug("v1 push_back");
    display(v1);

    v1.pop_back();
    debug("v1 pop_back");
    display(v1);

    v1.front() -= v1.back(); //第一个减最后一个
    debug("v1.front() -= v1.back()");
    display(v1);

    for (It = v1.begin(); It < v1.end(); It++)
    {
        v2.push_back(*It);
    }
    debug("v2.push_back(*It)");
    display(v2);
    v2.insert(v2.begin(), 2, 300);
    debug("v2.insert(v2.begin(), 2, 300);");
    display(v2);
    v2.erase(v2.begin() + 5);
    debug("v2.erase(v2.begin() + 5);");
    debug("遍历v2");
    display(v2);
    return 0;
}
