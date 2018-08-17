#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //包含单个字母数字判断函数   就是isalnum()这类判断数字还是标点字符来着
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数

using namespace std;    //所有命名空间都加载到默认关键字里 个人懒这个不是特别推荐

int fact(int i)
{
    return -i;
}

int main()
{
    int ii;
    cin >> ii;
    cout << fact(ii) <<endl;
}

/*
    //6.5
int fact(int i)
{
    return -i;
}

int main()
{
    int ii;
    cin >> ii;
    cout << fact(ii) <<endl;
}



    //6.4
int fact(int i)
{
    int o = 1;
    while (i>1){
        o *= i;
        i--;
    }
    return o;
}

int main()
{
    int ii;
    cin >> ii;
    cout << fact(ii) <<endl;
}



    //6.3
    int fact(int i)
{
    int o = 1;
    while (i>1){
        o *= i;
        i--;
    }
    return o;
}

int main()
{
    cout << fact(5) <<endl;
}


    //6.2
string f()  //返回类型错误
    {
        string s;
        //...
        return s;
    }

int f2(int i) {//....}  //忘记写返回类型

int calc (int v1, int v2) {//...}   //两形参一样

double square (double x){ return x*x;}  //忘记加括号

    //6.1
    //实参 和 形参区别很大. 实参是要赋值给形参的对象 一个有实数一个只定义了
*/
