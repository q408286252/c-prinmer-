#include <iostream> 		//输入输出流
#include <string>   		//字符串文件
#include <cctype>   		//单个字符判断(是否是符号 数字 标点 字母啊 什么的.)函数的库
#include <vector>   		//容纳对象的容器 俗称列表
#include <cstring>  		//提供C语言标准库的一些函数
#include <fstream>  		//文件IO
#include <sstream>  		//strIO
#include <list>     		// 双链表 容器
#include <forward_list> 	//单链表容器
#include <deque>    		// 双向vector容器
#include <array>    		//固定容器 array
#include <stack>    		//栈适配器stack
#include <queue>    		//队列适配器 包括: priority_queue 和 queue;
#include <algorithm>    	//大部分算法文件
#include <iterator> 		//各种迭代器  插入迭代器 流迭代器;方向迭代器;移动迭代器;
#include <functional>   	//有bind函数;  ref(os) 返回一个特殊可拷贝对象   cref(os)返回特殊可拷贝const对象 主要用于无法传值对象
#include <map>  			//对应值容器
#include <set>  			//关键字容器
#include <unordered_map>    //无序对应值容器
#include <unordered_set>    //无序关键字容器
#include <cxxabi.h>         //用typeid(变量名).name() 时用到的帮助gcc显示完整类型
#include <utility>          //使用pair一对变量类型
#include <ctime>            //c的程序计时软件
#include <memory>           //智能指针, allocator类


using namespace std;


class A{
public:
    A(const string &s = string()): ps(new string(s)), i(0), use(new size_t(1)) {}
    A(const A& p): ps(p.ps), i(p.i), use(p.use){ ++*p.use; }
    A& operator=(const A& p){
        ++*p.use;
        if (--*use ==0){
            delete use;
            delete ps;
        }
        ps = p.ps;
        i = p.i;
        use = p.use;
        return *this;
    };
    ~A(){
        if (--*use ==0){
            delete use;
            delete ps;
        }
    }

private:
    string *ps;
    int i;
    size_t *use;
};


class Message;

class Folder{
public:
    friend class Message;
    void remMsg(Message *ptr){
        set_Message.erase(ptr);
    }
    void addMsg(Message *ptr){
        set_Message.insert(ptr);
    }
    void save(Message &f){
        set_Message.insert(&f);
    }
    void remove(Message &f){
        set_Message.erase(&f);
    }
private:
    set<Message*> set_Message;
};

class Message{
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
public:
    explicit Message(const std::string &str = ""): contents(str) {} //初始化string值
    //如果拷贝构造函数 string 和 F实例指针的集合 拷贝  并且 被拷贝m的集合每个实例指针调用Msg
    Message(const Message &m):contents(m.contents), folders(m.folders) { add_to_Folders(m);}
    //拷贝赋值运算符
    Message& operator=(const Message &rhs){
        //当前实例的集合 每个元素调用remMsg一次
        remove_from_Folders();
        contents = rhs.contents;
        folders = rhs.folders;
        //传参的实例集合 每个元素调用addMsg一次
        add_to_Folders(rhs);
        return *this;
    }
    ~Message(){
        //当前实例的集合 每个元素调用 remMsg一次;
        remove_from_Folders();
    }

    void save(Folder &f){
        folders.insert(&f);
        f.addMsg(this);
    }
    void remove(Folder &f){
        folders.erase(&f);
        f.remMsg(this);
    }
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message &m){
        for(auto f: m.folders)
            f->addMsg(this);
    }
    void remove_from_Folders(){
        for(auto f: folders)
            f->remMsg(this);
    }
};

void swap(Message &lhs, Message &rhs){
    using std::swap;
    for(auto f: lhs.folders)
        f->remMsg(&lhs);
    for(auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for(auto f: lhs.folders)
        f->addMsg(&lhs);
    for(auto f: rhs.folders)
        f->addMsg(&rhs);
}

int main(){
    Message m1("xingxiuyan"),m2("lindaiyu"),m3("xuebaochai");
	Folder f1, f2, f3, f4, f5;
	m1.save(f1);
	f1.save(m2);
}


/*

//13.33 ~13.38
class Message;

class Folder{
public:
    friend class Message;
    void remMsg(Message *ptr){
        set_Message.erase(ptr);
    }
    void addMsg(Message *ptr){
        set_Message.insert(ptr);
    }
    void save(Message &f){
        set_Message.insert(&f);
    }
    void remove(Message &f){
        set_Message.erase(&f);
    }
private:
    set<Message*> set_Message;
};

class Message{
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
public:
    explicit Message(const std::string &str = ""): contents(str) {} //初始化string值
    //如果拷贝构造函数 string 和 F实例指针的集合 拷贝  并且 被拷贝m的集合每个实例指针调用Msg
    Message(const Message &m):contents(m.contents), folders(m.folders) { add_to_Folders(m);}
    //拷贝赋值运算符
    Message& operator=(const Message &rhs){
        //当前实例的集合 每个元素调用remMsg一次
        remove_from_Folders();
        contents = rhs.contents;
        folders = rhs.folders;
        //传参的实例集合 每个元素调用addMsg一次
        add_to_Folders(rhs);
        return *this;
    }
    ~Message(){
        //当前实例的集合 每个元素调用 remMsg一次;
        remove_from_Folders();
    }

    void save(Folder &f){
        folders.insert(&f);
        f.addMsg(this);
    }
    void remove(Folder &f){
        folders.erase(&f);
        f.remMsg(this);
    }
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message &m){
        for(auto f: m.folders)
            f->addMsg(this);
    }
    void remove_from_Folders(){
        for(auto f: folders)
            f->remMsg(this);
    }
};

void swap(Message &lhs, Message &rhs){
    using std::swap;
    for(auto f: lhs.folders)
        f->remMsg(&lhs);
    for(auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for(auto f: lhs.folders)
        f->addMsg(&lhs);
    for(auto f: rhs.folders)
        f->addMsg(&rhs);
}

int main(){
    Message m1("xingxiuyan"),m2("lindaiyu"),m3("xuebaochai");
	Folder f1, f2, f3, f4, f5;
	m1.save(f1);
	f1.save(m2);
}

//13.5
HasPtr(const HasPtr &a): ps(new string(*a.ps)), i(a.i) {cout << "我运行了哦";}

//13.4
传参时候;
Point local = arg; 时候;
Point pa[4] 的时候
返回时候;

//13.3
只要是类拷贝就是 调用拷贝构造函数啊;

//13.2
这个构造函数是非常严重错误的; Sales_data rhs要创立必须拷贝构造 然后还要调用它 它继续拷贝构造 递归了


//13.1
拷贝构造函数就是 函数参数在非引用的形参 返回值 和=  {}赋值时候的 调用的构造函数;
只不过它的形参需要 其他构造函数自动变换成实参传递给它;


*/
