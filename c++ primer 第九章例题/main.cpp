#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //单个字符判断(是否是符号 数字 标点 字母啊 什么的.)函数的库
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数
#include <fstream>  //文件IO
#include <sstream>  //strIO
#include <list>     // 链表容器
#include <deque>    // 双向vector

#include "Sales_data.h"

using namespace std;



int main()
{

    vector<int> iv;
    vector<int>::iterator iter = iv.begin(),
                         mid = iv.begin() + iv.size()/2;
    while (iter != mid)
        if (*iter == some_val)
            iv.insert(iter, 2 * some_val);

    //错误1 some_val是啥?
    //错误2 很有可能while死循环
    //错误3 往容器添加元素指针会失效

    int some_val = 4;
    vector<int> iv = {0,1,2,3,4,5,6,7,8,9,10}, ivb;
    vector<int>::iterator iter = iv.begin(),
                         mid = iv.begin() + iv.size()/2;
    while (iter != mid){
        if (*iter == some_val)
            ivb.insert(ivb.begin(), 2 * some_val);
        ++iter;
    }
    cout << ivb[0] << endl;


/*
    string word;
    vector<string> strs;
    auto iter = strs.begin()
    //cin输出的string给word 只要cin不终止一直循环
    while (cin >> word)
        //word插入strs的迭代器首; 然后 刷新iter的迭代器位置到新的首部;
        iter = strs.insert(iter, word);
    for (auto ip = strs.begin(); ip != strs.end(); ++ip)
        cout << *ip << endl;

    list<int> ilsa = {0,1,2,3,4};
    deque<int> dequesa, dequesb;
    for (auto ip = ilsa.begin(); ip != ilsa.end(); ++ip)
        if ( (*ip%2) == 1 ){
            dequesa.push_back(*ip);
        }else{
            dequesb.push_back(*ip);
        }
    cout << dequesa[0] << endl;

    list<string> ils;
    string stra;
    while (cin >> stra)
        ils.emplace_back(stra);
    for (auto ip = ils.begin(); ip != ils.end(); ++ip)
        cout << *ip << endl;

    vector<Sales_data> c;
    c.push_back(Sales_data("978-059",25,15.99));
    cout << c[0].name << endl;
    */


}

/*
    //9.22
    //错误代码
    vector<int> iv;
    vector<int>::iterator iter = iv.begin(),
                         mid = iv.begin() + iv.size()/2;
    while (iter != mid)
        if (*iter == some_val)
            iv.insert(iter, 2 * some_val);
    //错误1 some_val是啥?
    //错误2 很有可能while死循环
    //错误3 往容器添加元素指针会失效

    //修改后代码
    int some_val = 4;
    vector<int> iv = {0,1,2,3,4,5,6,7,8,9,10}, ivb;
    vector<int>::iterator iter = iv.begin(),
                         mid = iv.begin() + iv.size()/2;
    while (iter != mid){
        if (*iter == some_val)
            ivb.insert(ivb.begin(), 2 * some_val);
        ++iter;
    }


    //9.21
    string word;
    vector<string> strs;
    auto iter = strs.begin()
    //cin输出的string给word 只要cin不终止一直循环
    while (cin >> word)
        //word插入strs的迭代器首; 然后 刷新iter的迭代器位置到新的首部;
        iter = strs.insert(iter, word);


    //9.20
    list<int> ilsa = {0,1,2,3,4};
    deque<int> dequesa, dequesb;
    for (auto ip = ilsa.begin(); ip != ilsa.end(); ++ip)
        if ( (*ip%2) == 1 ){
            dequesa.push_back(*ip);
        }else{
            dequesb.push_back(*ip);
        }


    //9.19
    list<string> ils;
    string stra;
    while (cin >> stra)
        ils.emplace_back(stra);
    for (auto ip = ils.begin(); ip != ils.end(); ++ip)
        cout << *ip << endl;
    //我这写法不需要做改变的-. =

    //9.18
    deque<string> ils;
    string stra;
    while (cin >> stra)
        ils.emplace_back(stra);
    for (auto ip = ils.begin(); ip != ils.end(); ++ip)
        cout << *ip << endl;


    //9.17
    限制1: 容器类型要一样 2.元素类型相同 3.元素类型可比


    //9.16
    list<int> v1 = {1,2,3,4,};
    vector<int> v2 = {1,2,3,4};
    vector<int> v3(v1.begin(),v1.end());    //我把v1元素写给v3然后做比较而没用for auto指针挨个移动识别
    if ( v3 == v2)
        cout << "v1元素和c2相等" << endl;


    //9.15
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {1,2,3,4};
    if (v1 == v2)
        cout << "v1元素和c2相等" << endl;


    //9.14
    list<const char*> ls = {"a","at","are"};
    vector<string> lsv;
    lsv.assign(ls.begin(), ls.end());

    //9.13
    list<int> ls = {0,1,2,3};
    vector<double> lsv(ls.begin(), ls.end());


    //9.12
    接受一个容器的构造函数 它如果要拷贝元素 必须容器和元素类型相同,
    而接受迭代器的不需要容器相同. 而且只要元素值能转换 元素类型也可以不同.


    //9.11
    vector<int> i = {0,1,2,3};; //0,1,2,3
    vector<int> i1; //空
    vector<int> i2(i);  //0,1,2,3
    vector<int> i3(i.begin(), i.end());//0,1,2,3
    vector<int> i4{0,1,2,3};//0,1,2,3
    vector<int> i5 = i;//0,1,2,3


    //9.10
    vector<int> v1; //vecotr容器元素为int;
    const vector<int> v2;   //常量固定容器 元素为int 无法修改
    auto it1 = v1.begin(), it2 = v2.begin();    //vector<int>::iterator
    auto it3 = vi.cbegin(), it4 = v2.cend();    //vector<int>::const_iterator

    //9.9
    不同处:一个为普通迭代器可修改;一个为常量迭代器不能修改指针位置;

    //9.8
    读取需要 list<string>::iterator 迭代器类型;  写入类型为: 容器名[list<sring>::size_type] 直接覆盖.

    //9.7
    索引vector的int 需要 vector<int>::size_type 类型;  写成:容器名[vector<int>::size_type]


    //9.6
    list<int> lst1;
    list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
    //while (iter1 < iter2)  {...}    //错误 指针比大小 且end所指内容无法比
    while (iter1 != iter2) {...}


    //9.5
vector<int>::iterator  cha(vector<int> &ints,const int &inta)
{
    for (auto ip = ints.begin(); ip != ints.end(); ++ip)
        if (*ip == inta)
            return ip;
}

int main()
{

    vector<int> ints = {0,1,2,3,4,5,6};
    int inta = 2;

    cout << *cha(ints,inta) << endl;
}


    //9.4
bool cha(const vector<int> &ints,const int &inta)
{
    for (auto ip = ints.begin(); ip != ints.end(); ++ip)
        if (*ip == inta)
            return true;
    return false;
}

int main()
{
    vector<int> ints = {0,1,2,3,4,5,6};
    int inta = 2;
    cout << cha(ints,inta) << endl;
}


    //9.3
    范围限制是容器的最大元素值;而迭代器的限制是 begin和end指针距离


    //9.2
    list<deque<int>> ls;


    //9.1
    读取固定数量的单词,把他们插入字典的容器. 如果是插入保存不随机访问选forward_list
    读取未知数量的单词总是插入到末尾, 删除头部单词  这个选deque;
    从一个文件读取未知数量证书.将他们排序然后打印到标准输出:  list


*/
