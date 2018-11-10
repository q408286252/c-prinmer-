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
int main()
{
    vector<string> aa = {"a","b"};
    StrBlob a(aa);

}
/*
//12.3


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
