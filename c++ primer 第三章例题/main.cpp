#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //包含单个字母数字判断函数   就是isalnum()这类判断数字还是标点字符来着
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数

#include "Sales_data.h" //加载本地制作的文件

using namespace std;    //所有命名空间都加载到默认关键字里 个人懒这个不是特别推荐

int main()
{
    //3.45


}



/*
    //3.45
    int ia[3][4] = {
			{0,1,2,3},
			{4,5,6,7},
			{8,9,10,11}
		};
    for (auto i = ia; i != end(ia); ++i){
        for (auto u = *i; u != end(*i); ++u)
            cout << *u << ' ';
         cout << endl;
    }


    for (auto i = 0; i != 3; ++i){
        for (auto u = 0; u != 4; ++u)
            cout << ia[i][u] << ' ';
        cout << endl;
    }

    for (auto &i : ia){
        for (auto &u : i)
            cout << u << ' ';
        cout << endl;
    }

    //3.44
    using int_arr = int[4];
    typedef int int_arr[4];
    int ia[3][4] = {
			{0,1,2,3},
			{4,5,6,7},
			{8,9,10,11}
		};
    for (int_arr *i = ia; i != end(ia); ++i){
        for (int *u = *i; u != end(*i); ++u)
            cout << *u << ' ';
         cout << endl;
    }


    for (size_t i = 0; i != 3; ++i){
        for (size_t u = 0; u != 4; ++u)
            cout << ia[i][u] << ' ';
        cout << endl;
    }

    for (int_arr &i : ia){
        for (int &u : i)
            cout << u << ' ';
        cout << endl;
    }

    //3.43
    int ia[3][4] = {
			{0,1,2,3},
			{4,5,6,7},
			{8,9,10,11}
		};
    for (auto i = ia; i != end(ia); ++i){
        for (auto u = *i; u != end(*i); ++u)
            cout << *u << ' ';
         cout << endl;
    }


    for (size_t i = 0; i != 3; ++i){
        for (size_t u = 0; u != 4; ++u)
            cout << ia[i][u] << ' ';
        cout << endl;
    }

    for (auto &i : ia){
        for (auto &u : i)
            cout << u << ' ';
        cout << endl;
    }

    //3.42
    vector<int> int_vec = {0,1,2,3,4,5};
    auto ls = int_vec.size();
    int inta[ls], ii = 0;
    for (i : int_vec){
        inta[ii] = i;
        ++ii;
    }
    cout << inta[4] << endl;


    //3.41
    int inta[]= {0,1,2,3,4,5};
    vector<int> int_vec(inta, inta+6 );
    //或 vector<int> int_vec(begin(inta), end(inta) );
    cout << int_vec[5] << endl;

    //3.40
    char ca[] = "lalafei" ,ca2[] = "lalana";
    char ca4[] = "1234567123456";
    strcpy(ca4,ca);
    strcat(ca4,ca2);
    cout << ca4 << endl;

    //3.39
    string str1 = "lalafei", str2 = "lalanaaaa";
    if (str1 < str2)
        cout << "str1小于str2" << endl;

    const char ca1[] = "lalafei", ca2[] = "lalanaaaa";
    if (strcmp(ca1,ca2) < 0)
        cout << "ca1 小于ca2" << endl;

    //3.38
    //因为两个指针相加得到的不是两段字符串合并的结果. 只不过得到了一个新的错误地址而已

    //3.37
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp){
        cout << *cp << endl;
        ++cp;
    };
    //输出结果是 h /n e /n l /n l /n o /n

    //3.36.2
    vector<int> is = {0,1,2,3,4,5,6}, is2 = {0,1,2,3,4,5,6};
    auto n = end(is) - begin(is), n2 = end(is2) - begin(is2);
    for (auto p = is.begin(), e = is.end(), p2 = is2.begin(), e2 = is2.end();
        p != e && p2 != e2; ++p,++p2){
        --n;
        --n2;
    }
    if (n == 0 && n == n2)
            cout << "两数组数值都相等" << endl;

    //3.36.1
    int is[] = {1,2,3}, is2[] = {1,2,3};
    auto n = end(is) - begin(is), n2 = end(is2) - begin(is2);
    for (int *p = begin(is), *e = end(is), *p2 = begin(is2), *e2 = end(is2);
        p != e && p2 != e2; ++p,++p2){
        --n;
        --n2;
        }

    if (n == 0 && n2 == 0)
            cout << "两数组数值都相等" << endl;

    //3.35
    int is[] = {1,2,3};
    for (int *p = is, *e = end(is); p != e; ++p)
        *p = 0;
    cout << is[1] << endl;

    //3.34
    //p2 在p1右边第几个地方 的值 给与p1计算
    //必须同一数组的元素 如果p1或p2所指向的元素不存在则非法的.

    //3.33
    //设定数组名称和类型容量时是默认初始化的,不初始化那就不存在这个数组也就无法使用

    //3.32
    int ia[10] = {0,1,2,3,4,5,6,7,8,9};
    int iaa[10];
    size_t n = 0;
    vector<int> lala;
    for (i : ia)
        lala.push_back(i);
    for (i : lala){
        iaa[n] = i;
        ++n;
    }
    cout << iaa[1] <<endl;

    //3.31
    int ia[10] = {0,1,2,3,4,5,6,7,8,9};

//3.30
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (size_t ix = 1; ix <= array_size; ++ix)
        ia[ix] = ix;   //这里错误 因为一开始循环ia[1] = 1; 但没设定ia[0]的值

 //3.29
    //优点:不可修改数量 防止错误的添加 删除
    //缺点不可修改数量 如果需要修改时候无法修改且 不能赋值和拷贝

//3.28
    //答:元素值为ia的元素值为0. ia2元素值是无序的数值, as和as2为空白符号

//3.27
    int txt_size = 2;
    unsigned buf_size = 1024;
    int ia[buf_size];           //错误  保存的是2048个数组
    int ib[4*7-14];             //正确
    int ic[txt_size] = {0,1};    //错误
    char st[11] = "fundamental";    //错误字符串包括空白符总共12个

//3.26
    因为 beg +end 的迭代器位置超了 是不存在的无法计算.

//3.25
    vector<unsigned> scores(11,0);
    unsigned grade;
    while (cin >> grade){
        if (grade <= 100)
            ++*(scores.begin()+ (grade/10));
    cout << scores[0] << endl;
    }

//3.24.2 十万位以内  没学string字符int类型转换
    int int1;
    vector<int> list1;
    while (cin >> int1)
        if (int1 < 1000000){
            list1.push_back(int1/100000);
            int1 = int1 - int1/100000*100000;
            list1.push_back(int1/10000);
            int1 = int1 - int1/10000*10000;
            list1.push_back(int1/1000);
            int1 = int1 - int1/1000*1000;
            list1.push_back(int1/100);
            int1 = int1 - int1/100*100;
            list1.push_back(int1/10);
            int1 = int1 - int1/10*10;
            list1.push_back(int1/1);
        }

    for (auto beg = list1.begin(), ed = list1.end(); beg != ed;  ++beg,--ed){
        cout << *beg + *(ed-1) << endl;
    }
    return 0;

 //3.24.1 万位以内  没学string字符int类型转换
    int int1;
    vector<int> list1;
    while (cin >> int1)
        if (int1 < 100000){
            list1.push_back(int1/10000);
            int1 = int1 - int1/10000*10000;
            list1.push_back(int1/1000);
            int1 = int1 - int1/1000*1000;
            list1.push_back(int1/100);
            int1 = int1 - int1/100*100;
            list1.push_back(int1/10);
            int1 = int1 - int1/10*10;
            list1.push_back(int1/1);
        }
    for (auto beg = list1.begin(), ed = list1.end(); beg +1 != ed;  ++beg){
        cout << *beg + *(beg + 1) << endl;
    }
    return 0;

//3.23
    vector<int> intlist = {1,2,3,4,5,6,7,8,9,10};
    for (auto i = intlist.begin(); i != intlist.end() ; ++i){
        *i = *i * 2;
        cout << *i << endl;
    }

//3.22
    string str = "asdfgh";
    for (auto i = str.begin(); i != str.end() ; ++i)
        *i = toupper(*i);
    cout << str << endl;

//3.21
    vector<int> v{1,2,3,4,5,6,7,8,9};
    for (auto i = v.cbegin(); i != v.cend(); ++i)
        cout << *i << endl;
    return 0;

//3.20.2 十万位以内  没学string字符int类型转换
    int int1;
    vector<int> list1;
    while (cin >> int1)
        if (int1 < 1000000){
            list1.push_back(int1/100000);
            int1 = int1 - int1/100000*100000;
            list1.push_back(int1/10000);
            int1 = int1 - int1/10000*10000;
            list1.push_back(int1/1000);
            int1 = int1 - int1/1000*1000;
            list1.push_back(int1/100);
            int1 = int1 - int1/100*100;
            list1.push_back(int1/10);
            int1 = int1 - int1/10*10;
            list1.push_back(int1/1);
        }
    for (decltype(list1.size()) i =0; i != list1.size()/2; ++i){
        cout << list1[i] + list1[list1.size()-1] << endl;
    }
    return 0;

 //3.20.1 万位以内  没学string字符int类型转换
    int int1;
    vector<int> list1;
    while (cin >> int1)
        if (int1 < 100000){
            list1.push_back(int1/10000);
            int1 = int1 - int1/10000*10000;
            list1.push_back(int1/1000);
            int1 = int1 - int1/1000*1000;
            list1.push_back(int1/100);
            int1 = int1 - int1/100*100;
            list1.push_back(int1/10);
            int1 = int1 - int1/10*10;
            list1.push_back(int1/1);
        }
    for (decltype(list1.size()) i =0; i != list1.size()-1; ++i){
        cout << list1[i] + list1[i+1] << endl;
    }
    return 0;

//3.19
    vector<int> i(10,42);
    vector<int> i1{42,42,42,42,42,42,42,42,42,42};
    vector<int> i2;
    for (int i = 0; i != 10; ++i)
        i2.push_back(42);
    //第一行最方便 因为写的代码最短简洁
    return 0;

//3.18
    //不合法
    vector<int> ivec;
    ivec.push_back(42);
    return 0;

//3.17
    vector<char> v;
    string in;
    string str = "qwertyuiopasdfghjklzxcvbnm";
    string str1 = "QWERTYUIOPASDFGHJKLZXCVBNM";
    while (cin >> in)
        for (decltype(in.size()) la = 0; la != in.size(); ++la)
            v.push_back(in[la]);
    for (auto &i : v){
        for (decltype(str.size()) la = 0; la != str.size(); ++la ){
            if (str[la] == i)
               i  = str1[la];
        }
    }
    for (auto i:v)
        cout << i << endl;
    return 0;

 //3.16
    vector<int> v{1,2,3,4,5,6,7,8,9};
    for (auto &i : v)
        cout << i << endl;
    return 0;

//3.15
    vector<string> v2;
    string i;
    while (cin >> i)
        v2.push_back(i);

    cout << v2[1] << endl;
    return 0;

 //3.14
    vector<int> v2;
    int i;
    while (cin >> i)
        v2.push_back(i);

    cout << v2[1] << endl;
    return 0;

//3.13
    1. 0个空
    2.10个'0'
    3.10个'42'
    4.1个'10'
    5.10个'42'
    6 10个空
    7.10个"hi"

//3.12
    vector<vector<int>> ivec;       //正确ivec的元素为int类型列表
    vector<string> svec = ivec;     //错误ivec的元素类型是vector<int> 不是string
    vector<string> svec(10,"null"); //正确

//3.11
    const string s = "Keep out!";
    for (auto &c : s){
        //****
    }   //合法, 类型为引用
    return 0;

//3.10
    string strl;
    int i = 0;
    cin >> strl;
    for (auto c : strl){
        if (ispunct(c)){
            strl[i] = ' ';
        }
        ++i;
    };
    cout << strl << endl;
    return 0;

//3.9
能运行但不合法  因为空就是无 他的第一个字符是不存在的.

//3.8
    string str1 = "0 ;'";
    decltype(str1.size()) i = 0;
    while (i < str1.size())
        str1[i] = 'X', ++i;
    cout << str1  << endl;  //当然for 更方便 for (里能定义一个值还能自动加减)
//3.8
    string str1 = "0123456 89";
    string::size_type i = 0;
    for (decltype(str1.size()) i=0 ; i < str1.size(); ++i )
        str1[i] = 'X';
    cout << str1 << endl;
    return 0;

//3.7
//没改变

//3.6
    string str1 = "0123456 89";
    int i = 0;
    for (auto c : str1)
        str1[i] = 'X',  ++i;
    cout << str1 << endl;

 //3.5
    string a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    cout << a1+a2+a3 << endl;

    string a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    cout << a1+" "+a2+" "+a3 << endl;
    return 0;

//3.4
    string a1, a2;
    cin >> a1 >> a2;
    if (a1 == a2)
        cout << "ture" << endl;
    if (a1 > a2)
        cout << a1 << endl;
    if (a2 > a1)
        cout << a2 << endl;
    return 0;

//3.3
string的cin遇到空白字符会自动转换成结束然后把之前的字符串拼凑到一起当做对象保存 然后之后的字符再拼凑成一个新的对象
getline会把每行'/n'的内容当做一个整体给变量

//3.2
    string a1;
    while (getline(cin, a1))
        cout << a1 << endl;
    return 0;

    string a1;
    while (cin >> a1)
        cout << a1 << endl;
    return 0;

//3.1.4
#include <iostream>
using namespace std;
int main()
{
    int o = 0;
    for (int i = 50; i <=100; ++i)
        o += i;
    cout << o << endl;
    return 0;
}

//3.1.3
#include <iostream>
using namespace std;
int main()
{
    for (int i = 10; i >=0; --i){
        cout << i << endl;
    }
    return 0;
}

//3.1.2
#include <iostream>
using namespace std;
int main()
{
    int i,o;
    cin >> i >> o;
    cout << i+o << endl;
    return 0;
}

//3.1.1
#include <iostream>
#include "Sales_data.h"
using namespace std;
int main()
{
    Sales_data book1, book2;
    cin >> book1.bookNo >> book1.revenue >> book1.units_sold;
    cin >> book2.bookNo >> book2.revenue >> book2.units_sold;
    if (book1.bookNo == book2.bookNo)
        cout << book1.revenue * book1.units_sold + book2.revenue * book2.units_sold << endl;
    return 0;
}
*/
