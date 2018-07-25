#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //包含单个字母数字判断函数   就是isalnum()这类判断数字还是标点字符来着
#include <vector>   //容纳对象的容器 俗称列表

#include "Sales_data.h" //加载的文件

using namespace std;    //所有命名空间都加载到默认关键字里

int main()
{   //3.20.2 十万位以内  没学string字符int类型转换
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
}

/*
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

//3.1
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


#include <iostream>
using namespace std;
int main()
{
    for (int i = 10; i >=0; --i){
        cout << i << endl;
    }
    return 0;
}


#include <iostream>
using namespace std;
int main()
{
    int i,o;
    cin >> i >> o;
    cout << i+o << endl;
    return 0;
}

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
