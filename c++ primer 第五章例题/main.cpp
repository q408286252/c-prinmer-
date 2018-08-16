#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //包含单个字母数字判断函数   就是isalnum()这类判断数字还是标点字符来着
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数

using namespace std;    //所有命名空间都加载到默认关键字里 个人懒这个不是特别推荐

int main()
{
    //5.22
    int itema = 0;
    if (itema == 0)
        throw runtime_error("介绍错误内容");
}


/*
    //5.22
    for (int sz = get_size(); !sz.empty();){
        if (sz <= 0)
            continue;
        ;// ....
    }

    //5.21
    string s, s_n;
    while (cin >> s)
        if (!isupper(s[0])) //不是大写字母则
            continue;
        else{
            if (s != s_n){
                s_n = s;
            }else{
                break;
            }
        }

    //5.20
    string s, s_n;
    while (cin >> s)
        if (s != s_n)
            s_n = s;
        else
            break;

    //5.19
    string rsp ="0";
    do {
        cout << "请输入两个字符串 我们会输出较小的那个";
        string sa, sb;
        cin >> sa >> sb;
        if (sa > sb)
            cout << sa <<endl;
        else
            cout << sb <<endl;
        cout << "输入n可中止输入其他内容可继续" <<endl;
        cin >> rsp;
    } while (rsp != "n");

    //5.18
    do{ //少加了{}
        int v1, v2;
        cout << "please";
        if (cin >> v1 >> v2)
            cout << "sum:" << v1+v2 << endl;
    }while (cin);

    do {
        // ...
    }while ( 该写成判断 ); //while里面定义类型了.

    do{
        int ival = get_resonse();
        cin >> ival;
    } while (ival); //不正确 判断内容无法控制 如果true则一直循环下去


    //5.17
    vector<int> ls = {1,2,3,4,5,6};
    vector<int> lsb = {1,2,3,4,5,6,7,8};
    std :: vector <int> :: size_type shu = 0;
    if ( ls.size() > lsb.size() ){
        for (auto ib = lsb.begin(), ia = ls.begin(); *ia == *ib && ib != lsb.end(); ++ia, ++ib, ++shu )
            ;
        if (shu == lsb.size())
            cout << "lsb包括了ls" <<endl;
    } else {
        for (auto ib = lsb.begin(), ia = ls.begin(); *ia == *ib && ia != ls.end(); ++ia, ++ib, ++shu )
            ;
        if (shu == ls.size())
            cout << "ls包括了lsb" <<endl;
    }

    //5.16
    //偏向使用for循环 因为更可控.

    //5.15
    // ix赋值为0, ix 不等于sz时 继续循环 , 每循环一次ix+1
    for (int ix = 0; ix != sz; ++ix) {}
    //这里的if式子和上面循环已经重复了可以去掉

    int ix;
    //ix不等于sz是运行, 每运行一次ix+1
    for (;ix != sz; ++ix) {}

    //++ix, ++sz 会永远循环 必须改
    for (int ix =0; ix != sz; ++ix, --sz) {}

    //5.14
    int i = 1, i_m =0;
    string s, s_n, s_m;
    while (cin >> s){
        if (s_n == s){
            ++i;
            if ( i >= i_m ){
                i_m =i;
                s_m = s;
            }
        } else{
            s_n = s;
            i = 1;
        }
    }
    cout << s_m << "   " << i_m << endl;

    //5.13
    a : 每行的case 没写break;
    b : 在case 声明了一个ix的int类型却在 default里使用 这是不正确的因为 两个内容并不会同时运行
    c : 匹配时没有 ,号的写法 要匹配几个就要写几个 case
    d : case 匹配的必须是常量而不是变量.

    //5.12
    char c;
    int f=0,ff=0,fl=0,fi=0;
    while (cin >> c){
        switch(c){
                case 'f':
                    if (f ==0)
                        ++f;
                    else{
                        ++ff;
                        --f;
                    }
                    break;
            if( f ==1 )
                --f;
                case 'i':
                    ++fi;
                    break;
                case 'l':
                    ++fl;
                    break;
                }
        }
    cout << "ff有" <<ff << "\nfl有" << fl << "\nfi有" << fi << endl;

    //5.11
    char c;
    int a=0,e=0,i=0,o=0,u=0,t=0,space=0,n=0;
    while (cin >> c){
        switch(c){
            case 'a': case 'A':
                ++a;
                break;
            case 'e': case 'E':
                ++e;
                break;
            case 'i': case 'I':
                ++i;
                break;
            case 'o': case 'O':
                ++o;
                break;
            case 'u': case 'U':
                ++u;
                break;
            case '\t':
                ++t;
                break;
            case '\0':
                ++space;
                break;
            case '\n':
                ++n;
                break;
        }
    }
    cout << "a有" <<a << "\ne有" << e << "\ni有" << i << "\no有" << o << "\nu有" << u << "\n空格有" <<space << "\ntab有" <<t << "\n换行有" << n << endl;//貌似tab \n ' '统计不出来先放着.

    //5.10
    char c;
    int a=0,e=0,i=0,o=0,u=0;
    while (cin >> c){
        switch(c){
            case 'a': case 'A':
                ++a;
                break;
            case 'e': case 'E':
                ++e;
                break;
            case 'i': case 'I':
                ++i;
                break;
            case 'o': case 'O':
                ++o;
                break;
            case 'u': case 'U':
                ++u;
                break;
        }
    }
    cout << "a有" <<a << "\ne有" << e << "\ni有" << i << "\no有" << o << "\nu有" << u << endl;

    //5.9
    char c;
    int a=0,e=0,i=0,o=0,u=0;
    while (cin >> c){
        switch(c){
            case 'a':
                ++a;
                break;
            case 'e':
                ++e;
                break;
            case 'i':
                ++i;
                break;
            case 'o':
                ++o;
                break;
            case 'u':
                ++u;
                break;
        }
    }
    cout << "a有" <<a << "\ne有" << e << "\ni有" << i << "\no有" << o << "\nu有" << u << endl;

    //5.8
    //垂悬else 是if里面嵌套if 和else的语句
    //如何处理要看语句的表达式是否有{} 和行数来决定

    //5.7
    int ival, ival2,minval,cccurs;
    if (ival != ival2)
        ival = ival2;
    else
        ival = ival2 =0;

    if (ival < minval){
        minval = ival;
        cccurs = 1;
    }

    if (int ival = get_value(); ival )
        cout << "ival = " << ival << endl;
    else
        cout << "ival = 0\n";

    if (ival ==0 )
        ival = get_value();

    //5.6
    int grade = 0;
    string p = "";
    cin >> grade;
    (grade < 60) ?
        p += "C" :
        (grade > 70) ?
            p += "A" :
            p += "B";
    cout << p << endl;
    return 0;

    //5.5
    int grade = 0;
    string p = "";
    cin >> grade;
    if (grade < 60){
        p += "C";
    }else{
        if (grade > 70){
            p += "A";
        }else{
            p += "B";
        }
    }
    cout << p << endl;
    return 0;

    //5.4
    int s[5]
    while (string::iterator oter != s.end() )
        {}
    //存在问题
    while (auto oter = s.begin(); oter != s.end())

    while (bool status = find(word)) {}
    if (!status) {}
    // 查找word 如果有返回1 执行while循环  返回0执行if条件

    //5.3
    int sum = 0;
    for (int  val = 1; val <= 10; ++val)
        sum += val;
    cout  << sum << endl;

    //5.2
    //块就是{}  在for 和while后面的内容 如果循环后面要写2行以上表达式都要用到

    //5.1
    //空语句就是没有需要运行的内容的东西
    //有些地方内容还没想好怎么写的时候可以用空语句代替

*/
