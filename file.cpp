#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char s1[500];
    int cnt = 0;

    char src[260], dest[260], buff[16384];

    //普通文件读写
    ifstream inf("./file/a.cpp");
    if (!inf.fail())
    {
        ofstream outf("./file/b.txt");
        while (!inf.eof()) //文件结束符
        {
            inf.getline(s1, sizeof(s1) - 1);
            outf << setfill('0') << setw(4) << ++cnt << " " << s1 << endl;
        }
        for (int i = 0; i < 10; i++)
        {
            outf << "测试字符写入:" << i << endl;
        }
        outf.close();
        inf.close();
    }

    //二进制文件读写
    ifstream inf2("./file/book.dat", ios_base::in | ios_base::binary);
    if (!inf2.fail())
    {
        ofstream outf("./file/out.dat", ios_base::out | ios_base::binary);
        while (!inf2.eof())
        {
            inf2.read(buff, sizeof(buff));
            outf.write(buff, inf2.gcount());
            cout << buff << endl;
        }
        outf.close();
        inf2.close();
    }else
    {
        cout << "打开失败" << endl;
    }
    
    
    return 0;
}
