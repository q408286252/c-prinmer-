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
#include <iterator> //各种迭代器  插入迭代器 流迭代器;方向迭代器;移动迭代器;
#include <functional>   //有bind函数;  ref(os) 返回一个特殊可拷贝对象   cref(os)返回特殊可拷贝const对象
#include <map>  //对应值容器
#include <set>  //关键字容器
#include <unordered_map>    //无序对应值容器
#include <unordered_set>    //无序关键字容器
#include <cxxabi.h>         //用typeid(变量名).name() 时用到的帮助gcc显示完整类型
#include <utility>          //使用pair一对变量类型
#include <ctime>            //c的程序计时软件
#include <memory>           //智能指针
#include "Sales_data.h"

using namespace std;

template <typename T,typename T2>
int compare(const T&v1, const T2&v2){
    auto i = find(v1.begin(),v1.end(),v2);
    return *i;
}

template <typename T,size_t T2>
void print(array<T, T2> &arr){
    for (auto value: arr)
        cout << value << endl;
}
template <typename T,size_t T2>
T* begin(array<T, T2> &arr){
    T* i =&arr[0];
    return i;
}
template <typename T,size_t T2>
T* end(array<T, T2> &arr){
    T* i =&arr[T2-1];
    i++;
    return i;
}

template <typename T,size_t N>
constexpr size_t co(array<T, N> &arr){
    return N;
}
int main(){
    //vector<int> vec = {1,2,3};
    //cout << compare(vec,3);
    array<string, 5> a = {"a","b","c","d","e"};
    //print(a);
    cout << co(a);

}
/*
//16.8
因为c++ 有迭代器这玩意 能作用于几乎全部的容器类型. 迭代器的运算方式有 == 和 !=
而 <= < > >= 这些运算可能并没有实现. 所以必须换用< > ;


//16.7
template <typename T,size_t N>
constexpr size_t co(array<T, N> &arr){
    return N;
}
int main(){
    array<string, 5> a = {"a","b","c","d","e"};
    cout << co(a);
}

//16.6
template <typename T,size_t T2>
T* begin(array<T, T2> &arr){
    T* i =&arr[0];
    return i;
}
template <typename T,size_t T2>
T* end(array<T, T2> &arr){
    T* i =&arr[T2-1];
    i++;
    return i;
}
//end 这个应该是创建一个动态内存拼接在数组的尾部. 不是我这个函数的写法.
//而且我这个++ -- +n -n运算都没实现.


//16.5
template <typename T,size_t T2>
void print(array<T, T2> &arr){
    for (auto value: arr)
        cout << value << endl;
}

int main(){
    array<string, 5> a = {"a","b","c","d","e"};
    print(a);
}

//16.4
template <typename T,typename T2>
int compare(const T&v1, const T2&v2){
    auto i = find(v1.begin(),v1.end(),v2);
    return *i;
}
int main(){
    vector<int> vec = {1,2,3};
    cout << compare(vec,3);

}


//16.3
template <typename T>
T co(const T&v1, const T&v2){
    add(v1,v2);
    return add(v1,v2);
}
int main(){
    Sales_data a(10), b(20);
    a = co(a,b);
    print(a);
}


//16.2
template <typename T>
int co(const T&v1, const T&v2){
    return v1+v2;
int main()
{
   cout << co(1,2);
}



//16.1
实例化的定义:根据传入参数在模板里的运算 对自定义类型进行auto类似的辨别 编写一个特定版本的函数.来调用这实例;


*/
