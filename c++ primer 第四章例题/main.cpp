#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //包含单个字母数字判断函数   就是isalnum()这类判断数字还是标点字符来着
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数

//#include "Sales_data.h" //加载本地制作的文件

using namespace std;    //所有命名空间都加载到默认关键字里 个人懒这个不是特别推荐

int main()
{
    //4.26
    unsigned char qu = 0;
    qu |= 1UL << 27;
    bool bo = qu & (1UL << 27);
    cout << bo << endl; //会发生
}


/*
   //4.25
    'q' << 6 返回的值 二进制为:00000000 00000000 00011100 01000000
    十进制为: 2^12 + 2^11 + 2^10 + 2^6 = 7232

    //4.24
    int grade = 55;
    //如果左结合就变成这样  阅读起来很难受
    cout << ( (grade <60) ?
             ( (grade <=75) ?
              ( (grade <=90) ? "low pass" : "high pass" )
              : "pass" )
             : "fail" ) << endl;

    //4.23
    string s = "word";
    string p1 = ( s +s[s.size() - 1] == "s" ) ? "" : "s" ;
    //首先 要加括号 然后 s是string 和她做判断的不能是's'

    //4.22
    cout << ( (grade > 90) ?
             "high pass" : (grade > 75) ?
             "low pass" : (grade >= 60) ?
             "pass" : "fail" ) << endl;


    if (grade > 90){
        cout << "high pass";
    } else {
        if (grade > 75){
            cout << "low pass";
        } else{
            if (grade >= 60){
                cout << "pass";
            } else {
                cout << "fail";
            }
        }
    }
    cout << endl;
    //废话肯定第一个好啊. 第二个if else if else 看的头大好吗?

    //4.21
    vector<int> ints = {1,2,3,4,5,6};
    for (auto i = ints.begin(); i != ints.end(); ++i)
        (*i)%2 ? *i =*i * 2 : ' ';
    cout << ints[0] << endl;

    //4.20
    vector<string>::iterator iter;      //=. =无语p137的问题要找97页内容. 神经病啊!!
    *iter++;    //合法 iter指针右移一格的元素返回
    (*iter)++;  //不合法 返回iter第一个元素 然后+1 char类型不能运算
    *iter.empty();  //不合法  iter指针没有empty成员
    iter->empty();      //合法 找到iter的引用元素并找到empty成员运行
    ++*iter;        //不合法 和(*iter)++ 一样 char类型不能运算的
    iter++->empty();      //合法意思是 iter指针右移一个然后这元素的smpty成员运行

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
