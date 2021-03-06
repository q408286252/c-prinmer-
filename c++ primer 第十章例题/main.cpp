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

#include "Sales_data.h"
#include "Sales_item.h"

using namespace std;
using std::placeholders::_1;
using std::placeholders::_2;

bool compareIsbn (const Sales_data &la,const Sales_data &lb){
    return la.isbn() > lb.isbn();
}

bool rules (const string &stra){

    return stra.size() >= 5;
}


bool isShorter(const string &s1, const string &s2){
    return s1.size()<s2.size();
}
/*
void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //删重复
    auto en = stable_partition(vec.begin(),vec.end(),
                     [sz](const string &sa){ return sa.size() >=5;} );
    for_each(vec.begin(), en,
            [](const string &s){cout << s << " ";} );   //打印所有大于5字符的容器元素
    cout << endl;
}

void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //删重复
    stable_sort(vec.begin(), vec.end(),
                bind(check_sizeb, _1, _2) ); //然后大小排序;
    auto beg = find_if(vec.begin(), vec.end(),   //返回大于5字符的容器位置
                    bind(check_size, _1 ,sz) );
    for_each(beg, vec.end(),
            [](const string &s){cout << s << " ";} );   //打印所有大于5字符的容器元素
}
*/
bool check_sizeb(const string &sa, const string &sb){
    return sa.size()<sb.size();
}

bool check_size(const string &s, string::size_type sz){
    return s.size() > sz;
}


void f(string s, string souta, string soutb){
    ifstream input(s);
    ofstream output(souta,ofstream::app), outputb(soutb,ofstream::app);
    istream_iterator<int> in(input),en;
    for(; in != en; ++in){
        if ( *in %2 == 1){//奇数则:
            output << *in << endl;
        } else{
            outputb << *in<< endl;
        }
    }
}

void elimDups(list<string> &lst){
    lst.sort();//小到大排序
    lst.unique();
}

int main(){
    vector<string> lst = {"a","b","a","a","c","a"};
    list<vector<string>> ls = {lst,lst,lst,lst};
    for (auto i = ls.begin(); i != ls.end(); ++i){
        auto ia = count(i->begin(),i->end(), "a");
        cout<< ia << endl;
    }
    //for (auto iter = lst.begin(); iter != lst.end();++iter ){
    //    auto i = find(lst.begin(), iter, string("c") );
    //    cout << *i << endl;
        //if ( *(lst.end()) == *i ) {
        //    cout << "运行了" << endl;
        //}

}




/*
//10.42
void elimDups(list<string> &lst){
    lst.sort();//小到大排序
    lst.unique();
}

int main(){
    list<string> lst = {"a","b","a","b","c","a"};
    elimDups(lst);
    for (auto iter : lst )
        cout << iter << endl;

}




//10.41
    replace(beg, end, old_val, new_val);    //替换范围迭代器元素里 old_val值的元素替换成 new_val;
    replace_if(beg, end, pred, new_val);//替换 pred给出true的元素 替换成new_val;
    replace_copy(beg, end, dest, old_val, new_val); //替换范围迭代器元素里 old_val值的元素替换成 new_val; 并把所有新值插入到迭代器例,原容器不变
    replace_copy_if(beg, end, dest, pred, new_val);//替换pred给出true的元素替换成new_val,并把所有新值插入到迭代器例,原容器不变并且




//10.40
    copy要求 第一第二参数最少是输入迭代器; 第三参数最少是输出迭代器;
    reverse 逆向要求 最少双向迭代器:
    unique 最少单向迭代器:


//10.39
    list 是双向迭代器:
    vector是随机访问迭代器



//10.38
    输入迭代器   读;++;单遍
    输出迭代器   写;++;单遍
    向前迭代器   读写;++,列表元素重复读写;
    双向迭代器   读写;++;--;列表元素重复读写;
    随机访问迭代器     读写;++;--;计算迭代器距离;迭代器大小比较;迭代器指针+ -移动运算; 下标;



//10.37
    vector<int> vec= {0,1,2,3,4,5,6,7,8,9};
    list<int> ls(vec.rbegin()+3, vec.rend()-2);
    for (auto iter : ls )
        cout << iter << endl;


//10.36
list<int> ls= {0,1,2,3,4,5,0,6};
    auto iter = find(ls.crbegin(), ls.crend(), int(0));
    cout << *iter << endl;


//10.35
vector<int> vec= {0,1,2,3,4,5,6};
    for (auto riter = vec.cend()-1; riter != vec.cbegin()-1; --riter)
        cout << *riter << endl;



//10.34
vector<int> vec= {0,1,2,3,4,5,6};
    for (auto riter = vec.crbegin(); riter != vec.crend(); ++riter)
        cout << *riter << endl;



//10.33
void f(string s, string souta, string soutb){
    ifstream input(s);
    ofstream output(souta,ofstream::app), outputb(soutb,ofstream::app);
    istream_iterator<int> in(input),en;
    for(; in != en; ++in){
        if ( *in %2 == 1){//奇数则:
            output << *in << endl;
        } else{
            outputb << *in<< endl;
        }
    }
}

int main(){
    f("data.txt", "a.txt", "b.txt");
}




//10.32 为什么一定要使用find................... 还有网上答案很多都瞎几把写 跑不了.无语
//真心恶心......... 花了2个小时?
int main(){
    ifstream input("data.txt");
    istream_iterator<Sales_item> in(input),en;
    vector<Sales_item> vecl(in,en);
    sort(vecl.begin(),vecl.end(),[](const Sales_item &lhs, const Sales_item &rhs)->bool{return lhs.isbn() == rhs.isbn();} );

    //每个实例循环
    for (auto iter = vecl.begin(); iter != vecl.end(); ++iter){
        //找到此循环下一个到尾后 中同名的实例
        auto ita = find_if(iter+1, vecl.end(), [iter](Sales_item &s){ return s.isbn()==iter->isbn(); });
        //如果有则:
        if (ita != vecl.end()){
            //当前循环实例 和 找到实例的下个  初始为同名空;
            cout << accumulate(iter, ita+1, Sales_item(iter->isbn())) << endl;
            ++iter;
        } else {
            cout << *iter << endl;
        }
    }
}



//10.31
    istream_iterator<int> in(cin), en;
    ostream_iterator<int> out(cout, "\n");
    vector<int> veci(in,en);
    sort(veci.begin(),veci.end());
    unique_copy(veci.begin(),veci.end(),out);


//10.30
    istream_iterator<int> in(cin), en;
    ostream_iterator<int> out(cout, "\n");
    vector<int> veci(in,en);
    sort(veci.begin(),veci.end());
    copy(veci.begin(),veci.end(),out);



//10.29
    ifstream input("data.txt");
    istream_iterator<string> in(input), en;
    vector<string> vecs(in,en);



//10.28
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    list<int> lst,lsta,lstb;
    copy(vec.begin(),vec.end(),inserter(lst,lst.begin()));  //123456789
    copy(vec.begin(),vec.end(),back_inserter(lsta));    //123456789
    copy(vec.begin(),vec.end(),front_inserter(lstb));   //987654321



//10.27
    vector<string> vec = {"a","b","c","a"};
    list<string> lst;
    auto ip = unique(vec.begin(),vec.end());
    unique_copy(vec.begin(),ip-1,back_inserter(lst) );
    for (auto &i : lst)
        cout << i;




//10.26
back_inserter 尾后插入 总是插入容器屁股后面;
front_inserter 首部插入 总是把元素插入到容器前面;
inserter    指定某位置 从这里到插入结束之后的位置



//10.25         这题和10.22没啥区别
void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //删重复
    auto en = partition(vec.begin(), vec.end(),   //返回大于5字符的容器位置
                    bind(check_size,_1,sz) );
}

int main(){
    vector<string> words = {"a","b","aaaaaaaa","bbbbbb","aaaa","aaaaa","c","a","b"};
    biggies(words, 5);
}



//10.24
bool check_size(const string &s, string::size_type sz){
    return s.size() > sz;
}

int main(){
    vector<int> vec = {1,10,100,1000,10000,100000};
    vector<string> vecs;
    for (auto i : vec){
        vecs.push_back( to_string(i));
    }
    string s = "aaa";
    auto f = find_if(vecs.begin(),vecs.end(),bind(check_size, _1, s.size()) );
    cout << *f << endl;
}



//10.23
??? 我为什么要知道他能接受几个参数?;例子写过一个5参数的...正常情况会有十几个参数吗?
using std::placeholders::_29; //到这里还支持. 也就是说默认不写的参数支持29个


//10.22      感觉很糟糕. 属于重复使用的lambda
bool check_size(const string &s, string::size_type sz){
    return s.size() >= sz;
}
bool check_sizeb(const string &sa, const string &sb){
    return sa.size()<sb.size();
}

void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //删重复
    stable_sort(vec.begin(), vec.end(),
                bind(check_sizeb, _1, _2) ); //然后大小排序;
    auto beg = find_if(vec.begin(), vec.end(),   //返回大于5字符的容器位置
                    bind(check_size, _1 ,sz) );
    for_each(beg, vec.end(),
            [](const string &s){cout << s << " ";} );   //打印所有大于5字符的容器元素
}

int main(){
    vector<string> words = {"a","b","aaaaaaaa","bbbbbb","aaaa","aaaaa","c","a","b"};
    biggies(words, 6);
}


//10.21
    auto f = [&ia]() -> bool{if (ia>0) return --ia; else return 0; };
    for (int i =0; i != 10; ++i){
        cout << f() << endl;
    }


//10.20
void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //删重复
    auto ls = count_if(vec.begin(),vec.end(),
                     [sz](const string &sa){ return sa.size() >6;} );
    cout << ls <<  endl;
}
int main(){
    vector<string> words = {"a","b","aaaaaaaa","bbbbbb","aaaa","c","a","b"};
    biggies(words,6);
}



//10.19
void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //删重复
    auto en = stable_partition(vec.begin(),vec.end(),
                     [sz](const string &sa){ return sa.size() >=5;} );
    for_each(vec.begin(), en,
            [](const string &s){cout << s << " ";} );   //打印所有大于5字符的容器元素
    cout << endl;
}



//10.18
void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //删重复
    stable_sort(vec.begin(), vec.end(),
                [](const string &sa, const string &sb)
                { return sa.size()<sb.size(); } ); //然后大小排序;
    auto en = partition(vec.begin(), vec.end(),   //返回大于5字符的容器位置
                    [sz](const string &a){ return a.size() >= sz;} );
    for_each(vec.begin(), en,
            [](const string &s){cout << s << " ";} );   //打印所有大于5字符的容器元素
}


//10.17
    vector<string> words = {"a","b","aaaaaaaa","bbbbbb","aaaa","c","a","b"};
    elimDups(words);
    stable_sort(words.begin(), words.end(),
                [](const string &sa, const string &sb){return sa.size()<sb.size();} );
    for (const auto &s : words)
        cout << s << endl;



//10.16
    void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //删重复
    stable_sort(vec.begin(), vec.end(),
                [](const string &sa, const string &sb)
                { return sa.size()<sb.size(); } ); //然后大小排序;
    auto beg = find_if(vec.begin(), vec.end(),   //返回大于5字符的容器位置
                    [sz](const string &a){ return a.size() >= sz;} );
    for_each(beg, vec.end(),
            [](const string &s){cout << s << " ";} );   //打印所有大于5字符的容器元素
}



//10.15
int main(){
    int a = 10;
    auto f = [a](const int &ia){ return ia+a;};
    cout << f(20) << endl;
}


//10.14
    auto f = [](const int &ia,const int &ib){ return ia+ib;};
    cout << f(10,20) << endl;



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
