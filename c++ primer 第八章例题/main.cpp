#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //单个字符判断(是否是符号 数字 标点 字母啊 什么的.)函数的库
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数

using namespace std;

istream &print(istream &in){
    string stra;
    while (getline(in, stra))
        cout << stra;
    in.clear();
    return in;
}

int main()
{
    //print(cin);
    string i;
    while (cin >> i)
        cout << i <<endl;
}


/*
    //8.3
    //输入类型和i类型不一致时, 2.文件结束时.    3.系统级别未知错误时.


    //8.1 8.2
istream &print(istream &in){
    string stra;
    while (getline(in, stra))
        cout << stra;
    in.clear();
    return in;
}
int main()
{
    print(cin);

}
*/
