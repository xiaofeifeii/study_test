#include <iostream>
#include <thread>
#include <string>
#include <vector>

using namespace std;

void thread_one()
{
    puts("hello");
}

void thread_two(int num, string &str)
{
    cout << "num:" << num << ",name:" << str << endl;
}

void test()
{
    vector<int> v1;

    for (int i = 0; i < 5; i++)
    {
        v1.push_back((i + 1) * 10);
        cout << v1[i] << ",";
    }

    for (int i = 0; i < 2; i++)
    {
        v1.pop_back();
    }
    cout << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << endl;
    }

    cout << endl;
    v1.clear();
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << ",";
    }

    vector<int> demo{1, 2, 3, 4, 5};
    demo.pop_back();
    //输出 dmeo 容器新的size
    cout << "size is :" << demo.size() << endl;
    //输出 demo 容器新的容量
    cout << "capacity is :" << demo.capacity() << endl;
    for (int i = 0; i < demo.size(); i++)
    {
        cout << demo[i] << " ";
    }
    cout << endl;
    vector<string> v2 = {"a", "b", "c", "d", "e", "f", "g"};
    cout << "v2 size:" << v2.size() << endl;

    while (1)
    {
        if (!(v2.empty()))
        {
            cout << v2.back() << " ";
            v2.pop_back();
        }
        else
        {
            cout << endl;
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    string str = "luckin";

    thread tt(thread_one);
    tt.join();

    thread test_thread(test);
    // test_thread.join();

    thread yy(thread_two, 88, ref(str)); //这里要注意是以引用的方式调用参数
    // yy.detach();
    yy.join();

    _sleep(2 * 1000);
    // system("pause");
    return 0;
}