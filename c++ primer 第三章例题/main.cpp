#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //包含单个字母数字判断函数   就是isalnum()这类判断数字还是标点字符来着
#include <vector>   //容纳对象的容器 俗称列表

#include "Sales_data.h" //加载的文件

using namespace std;

int main()
{
    return 0;
}

/*
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
