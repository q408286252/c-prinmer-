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

using namespace std;


class StrBlob{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob(): data(make_shared<vector<string>>()){}
    StrBlob(std::initializer_list<std::string> il): data(make_shared<vector<string>>(il)){}
    size_type size() const {return data->empty();}
    void push_back(const std::string &t){data ->push_back(t);}
    void pop_back();
    std::string& front();
    std::string& back();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};


void StrBlob::check(size_type i, const std::string &msg) const{
    if (i >= data->size())  //容器len值如果小于等于 传入i值0则 抛错误;
        throw out_of_range(msg);
}
//同理还有front() back() pop_back()函数; 每个操作函数有个check(0,"错误提示");
template <typename T>
class BoBo{
public:
    BoBo(): data(make_shared<vector<T>>){}
    BoBo(initializer_list<T> il): data(make_shared<vector<T>>(il)){}
    typename vector<T>::size_type  size()const{
        return data->size();
    }
    void  push_back(const T &v1) const{
        check(0,"容器未空不能删除");
        data->push_back(v1);
    }
    void  pop_back();
    T  front(){
        check(0,"容器未空不能取数");
        return data->front();
    }
    T  back(){
        check(0,"容器未空不能取数");
        return data->back();
    }
private:
    shared_ptr<vector<string>> data;
    void check(const int &i,string &s){ //判断是否空 报错函数;
        if (i >= data->size())
            throw out_of_range(s);
    }
};

shared_ptr< vector<int> > fun(){
    shared_ptr< vector<int> > p = make_shared< vector<int>>();
    return p;
}
shared_ptr< vector<int> >  fun2(initializer_list<int> &la){
    shared_ptr< vector<int> > p = fun();
    for(auto iter = la.begin(); iter != la.end(); ++iter)
        p->push_back(*iter);
    return p;
}
void fun3(shared_ptr< vector<int> > p){
    for(auto iter = p->begin(); iter != p->end(); ++iter)
        cout << *iter;
}

void pro(shared_ptr<int> p){
    cout << *p;
}

struct destination{
    destination(string ss):s(ss){}
    string s;
};
void end_destination(destination *c){
    delete c;
}

unique_ptr<int> f(int p){
    return unique_ptr<int>(new int(p));
}


int main()
{
    int *p = new int(10);
    shared_ptr<int> s_p(p);
    weak_ptr<int> w_p(s_p);

}
/*
//12.18
    使用relese无非就是拷贝引用指针; 而shared_ptr直接用就行了. 为啥写这个relese?

//12.17
    //IntP p0(ix);    //错误ix是常驻内存
    IntP p2(pi2);
    IntP p4(new int(2048));
    //IntP p1(pi);    //指向了常用内存地址编译器没发现错误隐患非常大.
    //IntP p3(&ix);   //指向了常用内存地址编译器没发现错误隐患非常大.
    //IntP p5(p2.get());  //一个地址两个用完会调用删除的unique还行;


//12.16
    拷贝和赋值错误可以理解无法直接转换
    error: conversion from 'int*' to non-scalar type 'std::unique_ptr<int>' requested|



//12.15
int main()
{
    destination c("aaaaaa");
    shared_ptr<destination> p(&c,
                              [](destination *c){delete c;} );
}

//12.14
struct destination{
    destination(string ss):s(ss){}
    string s;
};

void end_destination(destination *c){
    delete c;
}


int main()
{
    destination c("aaaaaa");
    shared_ptr<destination> p(&c,end_destination);
}

//12.13
    auto sp = make_shared<int>();   //sp为智能指针
    auto p = sp.get();  //so管理的内存分配给p指针
    delete p;   //p的内存删除 导致sp管理的内存删除;

//12.12
    auto p = new int();
    auto sp = make_shared<int>();
    pro(sp);
    pro(new int()); //不合法.因为 会造成内存泄漏;
    pro(p); //p传参不能转换成shared_ptr<int> 类型
    pro(shared_ptr<int>(p));//不合法.因为sp作用范围中的内存已经被删除

//12.11
    运行完p的指针 所指的内存被释放;

//12.10
    不正确; 因为传参不是传p智能指针 而是传了一个p同分配内存的智能指针拷贝;
    把参数shared_ptr<int>(p) 改为p就行.


//12.9
    int *q= new int(42), *r = new int(100);
    r = q;  // new int(100) 占用内存永远无法delete
    auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
    r2 = q2;  //make_shared<int>(100) 占用内存自动删除;


//12.8
bool b(){
    int *p = new int;
    //...
    return p;
}
=. = bool 改为 int*才对啊;
虽然编译器过了 但p指针变为bool 调用的动态内存怎么删?


//12.7
shared_ptr< vector<int> > fun(){
    shared_ptr< vector<int> > p = make_shared< vector<int>>();
    return p;
}
shared_ptr< vector<int> >  fun2(initializer_list<int> &la){
    shared_ptr< vector<int> > p = fun();
    for(auto iter = la.begin(); iter != la.end(); ++iter)
        p->push_back(*iter);
    return p;
}
void fun3(shared_ptr< vector<int> > p){
    for(auto iter = p->begin(); iter != p->end(); ++iter)
        cout << *iter;
}
int main()
{
    initializer_list<int> la = {1,2,3};
    fun3( fun2(la) );
}


//12.6
vector<int>* fun(){
    return new vector<int>{};
}
vector<int> * fun2(initializer_list<int> &la){
    vector<int> *ptrvec = fun();
    for(auto iter = la.begin(); iter != la.end(); ++iter)
        ptrvec->push_back(*iter);
    return ptrvec;
}
void fun3(vector<int> *ptrvec){
    for(auto iter = ptrvec->begin(); iter != ptrvec->end(); ++iter)
        cout << *iter;
    delete ptrvec;
}
int main()
{
    initializer_list<int> la = {1,2,3};
    fun3( fun2(la) );
}


//12.5
    优点 能使类支更多类型的传入
    explicit 没写的缺点是: 不够谨慎,如果函数需要实例时候没传实例会可能会把传入的参数实例化,可能与原函数思想不一致埋下隐患;

//12.4
    为什么要检查i是否 大于0?  要检查也是检查是否大于等于0,抛错误主要还是看是否为空啊.

//12.3
    不需要.push_back和pop_back 经行了数据操作添加 删除了末尾值,这违反了cont 函数体的要求不改变变量


//12.2
template <typename T>
class BoBo{
public:
    BoBo(): data(make_shared<vector<T>>){}
    BoBo(initializer_list<T> il): data(make_shared<vector<T>>(il)){}
    typename vector<T>::size_type  size()const{
        return data->size();
    }
    void  push_back(const T &v1) const{
        check(0,"容器未空不能删除");
        data->push_back(v1);
    }
    void  pop_back();
    T  front(){
        check(0,"容器未空不能取数");
        return data->front();
    }
    T  back(){
        check(0,"容器未空不能取数");
        return data->back();
    }
private:
    shared_ptr<vector<string>> data;
    void check(const int &i,string &s){ //判断是否空 报错函数;
        if (i >= data->size())
            throw out_of_range(s);
    }
};


//12.1
b1包含3个元素 b2不存在

*/
