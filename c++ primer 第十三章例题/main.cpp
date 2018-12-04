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

class StrVec{
public:
    StrVec():elements(nullptr), first_free(nullptr),cap(nullptr){}
    StrVec(const initializer_list<string> &s){
        auto newdata = alloc_n_copy(s.begin(),s.end());
        elements = newdata.first;
        cap = first_free = newdata.second;
    }
    StrVec(const StrVec&s){            //拷贝构造函数
        auto newdata = alloc_n_copy(s.begin(),s.end());
        elements = newdata.first;
        cap = first_free = newdata.second;
    }
    StrVec& operator=(const StrVec&s){    //拷贝赋值运算符;
        auto newdata = alloc_n_copy(s.begin(), s.end());    //开辟新的内存创建向量
        free();                             //删除当前
        elements = newdata.first;
        cap = first_free = newdata.second;
        return *this;
    }
    ~StrVec(){  free();}

    void push_back(const string&s){
        chk_n_alloc();
        alloc.construct(first_free++,s);
    }
    void reserve(const int &n){ //重新构造能保存n元素的分配内存;
        if( n > capacity()){
            auto newcapacity = n;   //坑0元素分配是能创建的!
            auto newdata = alloc.allocate(newcapacity); //分配新内存
            auto dest = newdata;
            auto elem = elements;
            for (size_t i = 0; i != size(); ++i)
                alloc.construct(dest++, std::move(*elem++));
            free();
            elements = newdata;
            first_free = dest;
            cap = elements + newcapacity;
        }
    }
    void resize(int ls,string s = string("")){
        if (ls > size() ){
            auto newcapacity = ls;   //坑0元素分配是能创建的!
            auto newdata = alloc.allocate(newcapacity); //分配新内存
            auto dest = newdata;
            auto elem = elements;
            for (size_t i = 0; i != size(); ++i)
                alloc.construct(dest++, std::move(*elem++));
            for (size_t i = 0; i != newcapacity- size(); ++i)
                alloc.construct(dest++, s);
            free();
            elements = newdata;
            first_free = dest;
            cap = elements + newcapacity;
        }  else if (ls < size() && ls>= 0){
            auto p = first_free;
            for(auto i= 0; i != size()-ls;++i)
                alloc.destroy(--p);
        }
    }
    size_t size() const{ return first_free - elements;} //当前使用元素
    size_t capacity() const {return cap-elements;}  //最大可使用元素;
    string* begin() const {return elements;}
    string* end() const {return first_free;}

private:
    static std::allocator<string> alloc; //静态变量
    string *elements;   //首
    string *first_free; //自由
    string *cap;        //尾后

    void chk_n_alloc(){     //计算当前元素是否等于 最大分配元素数;
        if(size() == capacity())
            reallocate();
    }
    //传参 构造一个分配内存动态向量,返回 首和尾后 指针;
    pair<string*,string*> alloc_n_copy(const string*s1,const string*s2){
        auto data = alloc.allocate(s2-s1);
        return { data, uninitialized_copy(s1,s2,data) };
    }
    void reallocate(){  //重新分配动态内存
        auto newcapacity = size() ? 2*size(): 1 ;   //坑0元素分配是能创建的!
        auto newdata = alloc.allocate(newcapacity); //分配新内存
        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;
    }
    void free(){    //删除函数
        if(elements){    //始指针不为空则
            for(auto p = first_free; p != elements;)
                alloc.destroy(--p);
            alloc.deallocate(elements, cap-elements);
            //另一种写法没测过 for_each(first_free,elements, [first_free](const string &s){alloc.destroy(--first_free);});
        }
    }
};
std::allocator<string> StrVec::alloc;


void push_back(const int&a){
    cout << "运行了1";
}
void push_back(int&&a){
    cout << "运行了2";
}
int main(){
    push_back(12);
    int a = 12;
    push_back(a);
    push_back(std::move(a));
    const int b = 12;
    push_back(b);
}

/*
//13.49



//13.47  13.48
    emmmmm

//13.46
    //int f();
    vector<int> vi(100);
    //int &r1 = f();   //错误
    //int r1 = f();      //错误
    //const int &r1 = f();    //错误
    //int &&r1 = f();   //错误
    //我有点蒙. 然后发现按编译器吧int f();当一个函数声明了. 蒙蔽. 那就是例题的问题
    int f(5);
    int &r1 = f;
    int &r2 = vi[0];
    int &r3 = r1;
    int &&r4 = vi[0] * f;


//13.45
右值引用  绑定一个 无用户控制, 唯一, 临时性随时被删除的右值
左值引用  绑定一个变量起个别名 如果常量加const



//13.44  42 ..
emmmm犯懒.

//13.43
for_each(first_free,elements, [first_free](const string &s){alloc.destroy(--first_free);});
不便于理解. for循环更容易理解. 而且性能方面貌似没区别吧?


//13.41
写入元素= 内存分配元素时 会超内存.
第一个元素位置永远空着
析构元素时错误; 删除内存也会错误

//13.39 -40
class StrVec{
public:
    StrVec():elements(nullptr), first_free(nullptr),cap(nullptr){}
    StrVec(const initializer_list<string> &s){
        auto newdata = alloc_n_copy(s.begin(),s.end());
        elements = newdata.first;
        cap = first_free = newdata.second;
    }
    StrVec(const StrVec&s){            //拷贝构造函数
        auto newdata = alloc_n_copy(s.begin(),s.end());
        elements = newdata.first;
        cap = first_free = newdata.second;
    }
    StrVec& operator=(const StrVec&s){    //拷贝赋值运算符;
        auto newdata = alloc_n_copy(s.begin(), s.end());    //开辟新的内存创建向量
        free();                             //删除当前
        elements = newdata.first;
        cap = first_free = newdata.second;
        return *this;
    }
    ~StrVec(){  free();}

    void push_back(const string&s){
        chk_n_alloc();
        alloc.construct(first_free++,s);
    }
    void reserve(const int &n){ //重新构造能保存n元素的分配内存;
        if( n > capacity()){
            auto newcapacity = n;   //坑0元素分配是能创建的!
            auto newdata = alloc.allocate(newcapacity); //分配新内存
            auto dest = newdata;
            auto elem = elements;
            for (size_t i = 0; i != size(); ++i)
                alloc.construct(dest++, std::move(*elem++));
            free();
            elements = newdata;
            first_free = dest;
            cap = elements + newcapacity;
        }
    }
    void resize(int ls,string s = string("")){
        if (ls > size() ){
            auto newcapacity = ls;   //坑0元素分配是能创建的!
            auto newdata = alloc.allocate(newcapacity); //分配新内存
            auto dest = newdata;
            auto elem = elements;
            for (size_t i = 0; i != size(); ++i)
                alloc.construct(dest++, std::move(*elem++));
            for (size_t i = 0; i != newcapacity- size(); ++i)
                alloc.construct(dest++, s);
            free();
            elements = newdata;
            first_free = dest;
            cap = elements + newcapacity;
        }  else if (ls < size() && ls>= 0){
            auto p = first_free;
            for(auto i= 0; i != size()-ls;++i)
                alloc.destroy(--p);
        }
    }
    size_t size() const{ return first_free - elements;} //当前使用元素
    size_t capacity() const {return cap-elements;}  //最大可使用元素;
    string* begin() const {return elements;}
    string* end() const {return first_free;}

private:
    static std::allocator<string> alloc; //静态变量
    string *elements;   //首
    string *first_free; //自由
    string *cap;        //尾后

    void chk_n_alloc(){     //计算当前元素是否等于 最大分配元素数;
        if(size() == capacity())
            reallocate();
    }
    //传参 构造一个分配内存动态向量,返回 首和尾后 指针;
    pair<string*,string*> alloc_n_copy(const string*s1,const string*s2){
        auto data = alloc.allocate(s2-s1);
        return { data, uninitialized_copy(s1,s2,data) };
    }
    void reallocate(){  //重新分配动态内存
        auto newcapacity = size() ? 2*size(): 1 ;   //坑0元素分配是能创建的!
        auto newdata = alloc.allocate(newcapacity); //分配新内存
        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;
    }
    void free(){    //删除函数
        if(elements){    //始指针不为空则
            for(auto p = first_free; p != elements;)
                alloc.destroy(--p);
            alloc.deallocate(elements, cap-elements);
        }
    }
};
std::allocator<string> StrVec::alloc;
int main(){
    StrVec li;
    StrVec l2({"a","b","c"});
    cout << li.capacity()<< "\n" << l2.capacity() << "\n";
    li.push_back("aa");
    cout << li.capacity() << "\n";
    li.reserve(10);
    cout << li.capacity() << "\n";
    li.resize(20,"a");
    cout << *(li.begin() +11) << li.capacity() << "\n";
    StrVec l3 = li;
    cout << l3.capacity() << "\n";
}

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
