#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //包含单个字母数字判断函数   就是isalnum()这类判断数字还是标点字符来着
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数

//#include "Sales_data.h" //加载本地制作的文件

using namespace std;    //所有命名空间都加载到默认关键字里 个人懒这个不是特别推荐

int main()
{
    //4.19
    int i,ival;
    int *ptr = &i;
    vector<int> vec;
    ptr != 0 && *ptr++; //不正确首先ptr是int指针无法右移一格
    ptr != 0 && (*ptr)++
    ival++ && ival; // 不正确 因为到底是先调用 ival++ 还是ival 是未知
    ival +1 && ival;
    vec[ival++] <= vec[ival];   //还是一样 ival++ 和ival那个先运行未知 先后顺序不同结果不同.
    vec[ival +1] <= vec[ival];


}


/*
    //4.19
    int i,ival;
    int *ptr = &i;
    vector<int> vec;
    ptr != 0 && *ptr++; //不正确首先ptr是int指针无法右移一格
    ptr != 0 && (*ptr)++
    ival++ && ival; // 不正确 因为到底是先调用 ival++ 还是ival 是未知
    ival +1 && ival;
    vec[ival++] <= vec[ival];   //还是一样 ival++ 和ival那个先运行未知 先后顺序不同结果不同.
    vec[ival +1] <= vec[ival];

    //4.18
    //while 的括号里不能添加前置运算符 在{}里可以

    //4.17
    //前置运算 是加1 减1之后返回给某值 而后置运算是 先返回后+1-1

    //4.16
    if ( (p = getPtr()) != 0)
    if ( i == 1024)

    //4.15
    double dval;
    int ival;
    int *pi;
    //pi是地址 需要加*
    dval = ival = *pi = 0;

    //4.14
    //第一个if 错误 因为i无法给42赋值
    // 第二个只要 42赋值给了i 则运行

    //4.13
    int i;
    double d;
    d = i = 3.5;
    // d =3, i = 3
    i = d = 3.5;
    //i = 3, d = 3.5

    //4.12
    // i!=j<k  先判断j 是否大于k 返回 真假 然后 i 不等于 它 则真

    //4.11
    int a = 5, b = 10, c = 15, d = 20;
    if (a > b && b > c && c > d)
        cout << "正确"  << endl;

    //4.10
    int i;
    cin >> i;
    while (i != 42){
        cout << i << endl;
        cin >> i;
    }

    //4.9
    const char *cp = "Hello Word";
    if (cp && *cp)
    //cp的地址有内容且 cp指针所指元素不是空

    //4.8
    //优先级相等的表达式 其运算求值顺序为从左向右.

    //4.7
    short i = 0;
    i += 40000;
    cout << i << endl;

    //4.6
    int i;
    while (cin>> i)
        if (i%2 == 0)
            cout << "输入的数是偶数" << endl;
        else
            cout << "输入的数是奇数" << endl;
    return 0;

    //4.5
    //  -30 * 3 + 21 / 5 =  -90+4=-86
    //  -30 + 3 * 21 / 5 =  -30 + 63/5= -30+12 = -18
    //  30 / 3 * 21 % 5 =  10 *21 % 5 = 210 % 5 =0
    //  -30 / 3 * 21 % 4 = -10 *21 %4 = -210 %4 = -2
    int i = -30 / 3 * 21 % 4;
	cout << i << endl;

    //4.4
    //  (12/3*4) + (5*15) + (24%4/2) = 16 + 75 + 0 = 91
    int i = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
	cout << i << endl;

    //4.3
    //可接受因为 记住环境默认规则会给懒人更快捷的表达式书写.

    //4.2
    // (* ((vec.begin) () ) )
    // (* ( ((vec.begin) () ) ) + 1 ))

    //4.1
    cout << 5+10*20/2 << endl;
    //105
*/
