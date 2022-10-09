#include <iostream>
using namespace std;

class man
{
protected:
    int age;
    string name;

public:
    man(int a, string n) : age(a), name(n) {}
    void print()
    {
        cout << "姓名: " << name << ",年龄： " << age << endl;
    }
    int get_age() { return age; }
    string get_name() { return name; }
};

class superman : public man
{
private:
    int force_value;

public:
    superman(int a, string n, int f) : man(a, n), force_value(f){};
    void print()
    {
        cout << "姓名: " << name << ",年龄： " << age << "，武力值：" << force_value << endl;
    }
    void fly() { cout << name << " fly ,fly,fly..." << endl; }
};

// void work(man a)
// {
//     if (a.get_age() >= 20)
//     {
//         cout << a.get_name() << "可以胜任这份工作" << endl;
//     }
//     else
//     {
//         cout << a.get_name() << "不可以胜任这份工作" << endl;
//     }
//     a.print();
// }

void work(man *a)
{
    if (a->get_age() >= 20)
    {
        cout << a->get_name() << "可以胜任这份工作1" << endl;
    }
    else
    {
        cout << a->get_name() << "不可以胜任这份工作" << endl;
    }
    a->print();
}

void work(man &a)
{
    if (a.get_age() >= 20)
        cout << a.get_name() << "可以胜任这份工作2" << endl;
    else
        cout << a.get_name() << "不可以胜任这份工作" << endl;
    a.print();
}

int main(int argc, char const *argv[])
{
    int n;
    man i(21, "Bob");
    superman j(32, "yyf", 100);
    work(i);
    work(&j);
    // j.print();
    // j.fly();
    return 0;
}
