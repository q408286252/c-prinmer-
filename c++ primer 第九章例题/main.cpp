#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //单个字符判断(是否是符号 数字 标点 字母啊 什么的.)函数的库
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数
#include <fstream>  //文件IO
#include <sstream>  //strIO
#include <list>     // 链表容器
#include <deque>    // 双向vector

using namespace std;

vector<int>::iterator  cha(vector<int> &ints,const int &inta)
{
    for (auto ip = ints.begin(); ip != ints.end(); ++ip)
        if (*ip == inta)
            return ip;
}

int main()
{

    list<int> lst1;
    list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
    //while (iter1 < iter2) /* */     //错误 指针比大小 且end所指内容无法比
    while (iter1 != iter2) /* */
}

/*
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
