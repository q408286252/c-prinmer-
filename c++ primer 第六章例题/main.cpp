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


    //6.48
    string s;
    while (cin >> s && s != sought) {
    }
    assert(cin);
    //不合理.  为什么要输入不等于 sought就循环的一个空?
    // 而且assert(cin);判断的是cin 光写cin又不会输入东西给你判断!


    //6.47
// #define NDEBUG  写了就是关不写就是开
string print(vector<string> stra,int i )
{
    if (i != stra.size())
        return  stra[i] + print(stra, i+1);
    #ifndef NDEBUG
        cout << stra.size() <<endl;
    #endif // NDEBUG
    return " ";
}



int main()
{
    vector<string> s = {"a","b","c","d"};
    cout<<  print(s,0) << endl;
}



    //6.46
    constexpr string &shorterString(const string &s1, const string &s2)
    {
        return s1.size() <= s2.size() ? s1 : s2;
    }
    //这是错误的因为他的形参是引用而引用必须要有个初始变量 而constexpr必须实例是字符值 互相矛盾.

    //6.45
    是否改写成内联函数还是要看返回的内容是否简单最好一行写完的类型.
    6.42是,6.38是6.32是 6.33不是因为有两个返回需要判断.


    //6.44
    inline bool isShorter(const string &s1, const string &s2)
    {
        return s1.size() < s2.size()
    }


    //6.43
    吧a函数放进头文件 因为inline 为内联函数代表此函数结构简单,使用次数多,


    //6.42
string make_plural(size_t, const string &word, const string &ending="es");
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    string sa = "success", sb = "failure";
    cout<< make_plural(2,sa) << "\n" << make_plural(0,sb) << endl;
}
//string 如何输入's'? 估计书写错了.


    //6.41
char *intit(int ht, int wd = 80, char bckgrnd = ' ');
init();  //违法因为 ht值没设置
init(24,10); //正常
inti(14,'*') ;   //正常但和初衷不服.


    //6.40
int ff(int a, int b =0, int c=0); //这里不知道初始函数的形参是否设置了默认函数, 如果第三个形参没设置那么是正确的.
char *init(int ht = 24, int wd, char bckgrnd); //如果函数第一个形参没设置默认值那么是正确的,


    //6.39
    int calc(int, int);
    int calc(const int, const int); //如果实参是常量优先调用此函数

    int getc();
    double get();   //错误

    int *reset(int *);
    double *reset(double *);    //如果实参类型是浮点数优先调用他


    //6.38
string s[] = {"a","b","c","d","d","d","d","d","d","d"};
decltype(s) (*print(int i))
{
    return &s;
}
int main()
{
    cout<<  (* print(5))[9] << endl;
}


    //6.37
    typedef int arr;
    arr  (*print (int i))[10];

    auto print(int i) -> string(*)[10];

    string s[] = {"a","b","c","d","d","d","d","d","d","d"};
    decltype(s) (*print(int i))


    //6.36
    string (*print(int i))[10];

    //6.35
    首先这个函数循环下的局部变量 递减只运行一次.
    而且. val-- 是传入后再减值导致传入的值一直没变会陷入死循环

    //6.34
    如果传入的是负数会陷入死循环, 至少也要循环到数值溢出然后从新从最大值到0,,要很久.
    如果传入的是大于等于0的数则 会比之前的函数多运行一个循环.

    //6.33
string print(vector<string> stra,int i )
{
    if (i != stra.size())
        return  stra[i] + print(stra, i+1);
    return "";
}

int main()
{
    vector<string> s = {"a","b","c","d"};
    cout<<  print(s,0) << endl;
}


    //6.32
int &get(int *arry, int index)  //传入int 指针 和int 数值
{
    return arry[index]; //返回指针+下标
}

int main()
{
    int ia[10];
    for (int i=0; i != 10; ++i)
        get(ia, i) = 1;
        //get(ia,i) 意思为传入一个ia第一个元素指针给arry, i变量传入index 返回 & arry[index] =  ia[i]
}


    //6.31
    //返回的引用无效 是引用的局部变量的内容时候,或者类型不对

    //6.30
bool str_subrange(const string &sa, const string &sb)
{
    if (sa.size() == sb.size())
        return 1;
    auto size = (sa.size() < sb.size()) ? sa.size() : sb.size();
    for (decltype(size) i = 0; i != size; ++i)
        if (sa[i] != sb[i])
            return;     //不会处理会报错 应该返回 return 0;
}

int main()
{
    string s = "lala", ss = "lala";
    cout<< str_subrange(s,ss)<<endl;
}

    //6.29
    initializer_list是常量元素,循环控制变量设置成引用 那么引用一个常量如何修改递增?

    //6.28
    elem 是const string  指针类型.

    //6.27
    int print(initializer_list<int> il)
{
    int i=0;
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        i += *beg;
    return i;
}

int main()
{
    cout << print({10,20,33,450,60}) << endl;
}




    //6.26
windows 打开cmd 然后找到这个文件 main.cpp 然后终端输入:
    g++ -o main.exe main.cpp
    之后输入
    main -d -o ofile data0  啥的都行. 只要main开头就行.
int main(int argc, char* *argv)
{
    for (int ii = 0; ii != argc; ++ii){
        if (argv[ii])
            while (*(argv[ii]))
                cout<<*( (argv[ii])++);
        cout << endl;
    }
}

    //6.25
    //6.2.5跨度有点大..
    int main(string stra, string strb)
{
    stra += strb;
    cout << stra << endl;
}


    //6.24
int print(const int ia[10])
//本人编译器直接把数组传入一个数组没问 题但 const int i[10] = j; 就显示错误 em....
{
    for (size_t i=0; i != 10; ++i)  //设置一个i为计数器初始为0,每次循环完+1
        cout <<ia[i] << endl;   //每个循环输出ia第一个元素
}

int main()
{
    int j[10] = {0,1,2,3,4,5,6,7,8,9};
    print(j);
}


    //6.23
//固定数组写法
int print(int ia, int (&ib)[2])
{
    cout << ia << ib[0] << ib[1] << endl;
}


int main()
{
    int i=0, j[2] = {0,1};
    print(i,j);
    //cout <<  << endl;
}
//传入数组容量写法
int print(int ia, int ib[], size_t size)
{
    cout << ia << "\n" ;
    for (size_t i =0; i != size; ++i)
        cout << ib[i] << endl;
}
int main()
{
    int i=0, j[2] = {0,1};
    size_t t = 2;
    print(i,j,t);
}
//传入首位指针写法
int print(int ia, int *beg, int *en)
{
    cout << ia << "\n" ;
    while (beg != en)
        cout << *beg++ << endl;
}


int main()
{
    int i=0, j[2] = {0,1};
    print(i,j,end(j));
}



    //6.22
int print( int* &ipa, int* &ipb)
{
    int *ipc;
    ipc = ipa;
    ipa = ipb;
    ipb = ipc;
}


int main()
{
    int ia =2, ib = 3;
    int *ipaa = &ia, *ipbb = &ib;
    print(ipaa,ipbb);
    cout << *ipaa << *ipbb << endl;
}



    //6.21
    int print(const int i, const int *ip)
{
    if (i > *ip)
        return i;
    else
        return *ip;
}


int main()
{
    int ia =2, ib = 3;
    int ic = print(ia,&ib);
    cout << ic << endl;
    //指针类型是const int *类型
}


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
