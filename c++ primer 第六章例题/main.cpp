#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //包含单个字母数字判断函数   就是isalnum()这类判断数字还是标点字符来着
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数


using namespace std;    //所有命名空间都加载到默认关键字里 个人懒这个不是特别推荐



int main()
{


}

/*
    //6.20
    //实例是 直接的值和不能修改的值,
    //常量修改为普通引用一般会错误因为实参里 实际值 和常量值都会报错.


    //6.19
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

calc(23.4, 55.1) //错误 他实参只要一个浮点数且不能使直接的数值
double is = 23.4;
calc(is);

count("abcde",'a');  //正确

calc(66);   //错误 他实参只要一个浮点数且不能使直接的数值
double is = 66.0;
calc(is);

sum(vec.begin(), vec.end(), 3.8)  //能运行不合法 因为形参是int 而实参是3.8 可改为3或4



    //6.18
    bool compare (int &a, int &b)
{
    if (a != b)
        return false;
    else
        return true;
}

(b)
vector<int> chang_val (int i, vector<int> ils)
{
    int ls =0;
    for (int o =0; o != i; ++o){
        ils.push_back(ls)
        ++ls;
    }
    return ils;
}


    //6.17
    bool s_A (const string &s)
{
    for (decltype(s.size()) ls = 0; ls != s.size(); ++ls )
        if (isupper(s[ls]))
            return true;
    return false;
}
string s_a (string s)
{
    for (decltype(s.size()) ls = 0; ls != s.size(); ++ls )
        s[ls] = tolower(s[ls]);
    return s;
}

int main()
{

    if (s_A("ABCDefg"))
        cout << s_a("ABCDefg") <<endl;
}
    //不相同因为 一个需要修改 一个不要修改只是判断



    //6.16
bool is_empt(const string &s) {   //只能接受string类型变量数据
    return s.empty();
}

    //6.15
    因为查找字符出现次数 肯定需要一个string 和 要查找字符  至于出现次数也是要统计的导致 实参是这三个类型
    被查找的字符串是不能被修改的他是原值所以是常量常量了引用还是赋值都行,引用省内存 至于occurs为什么是普通引用因为他是会变动的值.
    至于为什么c不是引用因为没啥必要. 单个小字符设置引用感觉反而理解困难了.
    s为普通引用这个函数并没有改变但以防万一
    occurs是常量会错误; 因为++occurs存在;
    哦 所有引用必须要有个声明,上面和之前答案懒得改了

    //6.14
    比如调用一些大型 每个几mb的字符串 如果不引用会很占内存
    不能引用的地方是一些比较重要的变量 如果它没有设置为常量 如果有所改动复原会很麻烦.


    //6.13
    void f(T)   //是吧实参内容赋值给t    一个返回后赋值的T会自动删掉实参没修改
    void f(&T)  //是吧实参的别称写为T    一个运行时所有对T的修改等于对实参的修改

    //6.12
void f(int &ipa,int &ipb)
{
    int i;
    i = ipa;
    ipa = ipb;
    ipb = i;
}

int main()
{
    int i = 40, p = 50;
    f(i, p);
    cout << i << p <<endl;
}
//引用比指针好 因为指针还是要拷贝一次地址但 可以原值在某些地方不太好如果需要还要写常量.

    //6.11
    int rese(int &j)
{
    j = 40;
}

int main()
{
    int i = 50;
    rese(i);
    cout << i <<endl;
}



    //6.10
    void f(int *ipa,int *ipb)
{
    int i;
    i = *ipa;
    *ipa = *ipb;
    *ipb = i;
}

int main()
{
    int i = 40, p = 50;
    f(&i, &p);
    cout << i << p <<endl;
}


    //6.9      6.1.2和6.1.3跨度大了点
    fact.cc调用 #include "Chapter6.h"
    factMain.cc 属于调用文件 fact属于给函数赋值内容 而Chapter6.h属于编写的函数框架没有值


    //main 主程序文件只要调用一下 函数fact()就能得到个函数运算后的值了

    //fact.cc 文件内容
    #include "Chapter6.h"

    using namespace std;    //所有命名空间都加载到默认关键字里 个人懒这个不是特别推荐

    int fact()
    {
        f();
        f2(2);
        calc(1,2)
        return --s;
    }


    //6.8
    吧代码写到一个Chapter6.h文件里
    代码随意可以是
    #ifndef _Chapter6_h
    #define _Chapter6_h

    string f()  //返回类型错误
    {
        string s;
        //...
        return s;
    }

    int f2(int i) {//....}  //忘记写返回类型

    int calc (int v1, int v2) {//...}   //两形参一样

    double square (double x){ return x*x;}  //忘记加括号
    #endif



    //6.7
int fact()
{
    static int s=1;
    if (s != 1 )
        return 1;
    return --s;

}

int main()
{
    for (size_t i = 0; i != 10; ++i)
        cout << fact() <<endl;
}

    //6.6
    //形参是 调用函数时候默认函数里需要赋值的对象
    //局部变量是定义函数时所有的对象都是
    //局部静态变量是头痛关键字让某些对象 在调用完成后不删除次内容.
    int f(int i)
    {
        static int s=0;
        return s*i;
    }
    //int i是形参  也是局部变量, static int s 是局部静态变量

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
