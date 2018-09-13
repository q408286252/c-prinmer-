#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //单个字符判断(是否是符号 数字 标点 字母啊 什么的.)函数的库
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数
#include <fstream>  //文件IO
#include <sstream>  //strIO
#include <list>     // 双链表 容器
#include <forward_list> //单链表容器
#include <deque>    // 双向vector容器
#include <array>    //固定容器 array
#include <stack>    //栈适配器stack
#include <queue>    //队列适配器 包括: priority_queue 和 queue;
#include <algorithm>    //大部分算法整合
#include <iterator> //有back_inserter()函数

#include "Sales_data.h"

using namespace std;

void elimDups(vector<string> &vec){
    sort(vec.begin(), vec.end());
    auto bega = unique(vec.begin(), vec.end());
    vec.erase(bega, vec.end());
}

bool isShorter(const string &s1, const string &s2){
    return s1.size()<s2.size();
}

bool compareIsbn (const Sales_data &la,const Sales_data &lb){
    return la.isbn() > lb.isbn();
}

bool rules (const string &stra){

    return stra.size() >= 5;
}

int main()
{
    vector<string> vecS = {"a","b","aaaaaaaa","bbbbbb","aaaa","c"};
    auto en = partition(vecS.begin(),vecS.end(),rules);
    for (auto ip = vecS.begin(); ip != en; ++ip)
        cout << *ip << endl;

    /*
    Sales_data la("aaa"),lb("bbb");
    vector<Sales_data> vec = {la,lb};
    stable_sort(vec.begin(), vec.end(), compareIsbn);

    vector<string> vec = {"a","bb","ccc","a","bb","a"};
    elimDups(vec);
    stable_sort(vec.begin(), vec.end(), isShorter);
    for (auto i : vec)
        cout << i << endl;
        */
}


/*
//10.13
bool rules (const string &stra){

    return stra.size() >= 5;
}
int main()
{
    vector<string> vecS = {"a","b","aaaaaaaa","bbbbbb","aaaa","c"};
    auto en = partition(vecS.begin(),vecS.end(),rules);
    for (auto ip = vecS.begin(); ip != en; ++ip)
        cout << *ip << endl;
}


//10.12
bool compareIsbn (const Sales_data &la,const Sales_data &lb){
    return la.isbn() > lb.isbn();
}
int main()
{
    Sales_data la("aaa"),lb("bbb");
    vector<Sales_data> vec = {la,lb};
    stable_sort(vec.begin(), vec.end(), compareIsbn);
}


//10.11
void elimDups(vector<string> &vec){
    sort(vec.begin(), vec.end());
    auto bega = unique(vec.begin(), vec.end());
    vec.erase(bega, vec.end());
}

bool isShorter(const string &s1, const string &s2){
    return s1.size()<s2.size();
}

int main()
{
    vector<string> vec = {"a","bb","ccc","a","bb","a"};
    elimDups(vec);
    stable_sort(vec.begin(), vec.end(), isShorter);
    for (auto i : vec)
        cout << i << endl;
}



//10.10
    因为添加和删除会导致传入的迭代器失效啊!;



//10.9
void elimDups(vector<string> &vec){
    sort(vec.begin(), vec.end());
    auto bega = unique(vec.begin(), vec.end());
    vec.erase(bega, vec.end());
}

int main()
{
    vector<string> vec = {"a","b","c","a","b","a"};
    elimDups(vec);
    for (auto i : vec)
        cout << i << endl;
}



//10.8
    back_inserter() 这个是插入迭代器,是修改容器大小的函数
    但标准函数没有介绍它  它并不是标准函数里的;



//10.7
    vector<int> vec;
    list<int> lst;
    int i;
    while (cin >> i)
        lst.push_back(i);
    //copy(lst.cbegin(),lst.cend(),vec.begin());//这里有问题. 因为vec是空 无法拷贝进去
    copy(lst.cbegin(),lst.cend(),back_inserter(vec));
    for (auto i : vec)
        cout << i << endl;


    vector<int> vec;
    vec.reserve(10);//不行虽然设置了内存元素个数 但迭代器还是空的.
    fill_n(back_inserter(vec),10,0);
    for (auto i : vec)
        cout << i << endl;



//10.6
    vector<int> vec = {0,1,2,3,4,5,6};
    fill_n(vec.begin(), vec.size(), int(0));
    for (auto i : vec)
        cout << i << endl;



//10.5
    还是无法运行, 因为c风格字符串和 string字符串无法 '+'



//10.4
    有错0这值类型没有定类型 无类型和double 在函数里是无法运算的
    vector<double> v = {0.0,0.1,0.2,0.3};
    auto i = accumulate(v.cbegin(), v.cend(), double(0));
    cout << i << endl;



//10.3
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    auto result = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << "输出:" << result << endl;


//10.2
    list<string> vec;
    string stra;
    while (cin >> stra)
        vec.push_back(stra);
    auto result = count(vec.cbegin(), vec.cend(), "a");
    cout << "输出:" << result << endl;


//10.1
    vector<int> vec = {};
    int i;
    while (cin >> i)
        vec.push_back(i);
    auto result = count(vec.cbegin(), vec.cend(), 1);
    cout << "输出:" << result << endl;

*/
