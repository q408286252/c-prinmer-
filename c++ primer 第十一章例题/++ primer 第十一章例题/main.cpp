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

#define MAX 100

#include "Sales_data.h"
//#include "Sales_item.h"

using namespace std;

int method (vector<int> List, int X){
    int i = List.size()/2, low = 0, high = List.size();
    for (; List[i] != X;){
        if (List[i] < X){
            low = i;
            i = i + (high-i+1)/2;
        }
        else{
            high = i;
            i = i - (i-low+1)/2;
        }
    }
    return i;
}

int main()
{
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    cout << vec[method(vec,4)] << endl;
    //method()


}

/*
    multimap<string,string > mapa;
    ifstream in("data.txt");
    string s,s1,s2;
    int i = 0;
    while (in){
        in >> s;
        if (i % 2 == 0){
            s1 = s;
        } else{
            s2 = s;
            mapa.insert({s1,s2});
        }
        ++i;
    }

    for (auto i : mapa)
        cout << i.first << endl;
        */



/*
//11.32
    multimap<string,string > mapa;
    ifstream in("data.txt");
    string s,s1,s2;
    int i = 0;
    while (in){
        in >> s;
        if (i % 2 == 0){
            s1 = s;
        } else{
            s2 = s;
            mapa.insert({s1,s2});
        }
        ++i;
    }

    //for (auto i : mapa)
    //    cout << i.first << endl;




//11.31
    multimap<string,string > mapa = { {"a","aaaaa"}, {"a","aa"}, {"c","cccc"} };
    string s = "a";
    i:
    if (mapa.find(s) != mapa.end()){
        auto iter = mapa.find(s);
        mapa.erase(iter);
    }
    if ( mapa.find(s) != mapa.end() )
        goto i;
    for (auto ii : mapa)
        cout << ii.first << endl;


//11.30
    pos.first->second
    //pos 是pair;
    //pos.first 是找pair的第一个元素也就是找到第一个大于等于search_item值的迭代器;
    //pos.first->second 是迭代器引用然后找第二元素 也就是关联值的内容



//11.29
    upper_bound 指向大于关键字的迭代器; 没有则end();
    lower_bound 指向大于关键字的迭代器; 没有则end();
    equal_range 的pair 两元素分别指向 指向相同大于关键字的迭代器; 没有则end();


//11.28
    map<string,vector<int> > mapa = { {"a",{0,1,2,3}}, {"c",{4,5,6,7}} };
    pair<string, vector<int>> paira = {"",{0} };
    paira = *mapa.find("a");



//11.27
    count 用来解决 重复map 和set时使用
    find在不重复的 map和set时候使用,



//11.26
    //可以用关联值类型相同的值进行操作;
    //下标返回类型为 下标关键字的关联值 关联值类型由map定义;
    map<string,int> mapa;
    mapa["a"] = 1;
    mapa["a"] += 5;
    cout << mapa["a"] <<endl;



//11.25
    vector<int> v;
    v[0] = 1;   //这行属于未定义;
    //可以看出vector 和map差别很大


//11.24
    map<int,int> m;
    m[0] = 1;   //添加关键字0 其关联值初始化并赋值1



//11.23
    multimap<string, string> family;
    vector<string> vec;
    string  surname,name;
    cout << "如果输入完毕要输入下一个姓则输入y" << endl;
    i:
    while(cin >> surname){
        while(cin>> name){
            if (name == "y"|| name == "Y")
                goto i;
            family.insert({surname,name});
        }
    }
    for (auto &i : family)
        cout << "姓名为:" << i.first << i.second  << endl;



//11.22
    map<string, vector<int>> word_count;
    pair<string,vector<int>> paira = {"s",{1}};
    pair<map<string,vector<int>>::iterator, bool> set = word_count.insert(paira);



//11.21
    默认添加 word的字符 和0关联值 他们的返回pair找到第一成员first 这迭代器里的第二成员seond递增;



//11.20
    map<string, size_t> word_count;
    string s;
    while(cin >> s){
        auto ret = word_count.insert({s,1});
        if (!ret.second)    //pair的bool != 0
			++ret.first->second;
    }
    for (auto &i : word_count)
        cout << "出现" << i.first << "的次数为:" << i.second << endl;
    //不方便理解 特别第一值迭代器里的 第二元素 有点绕人


//11.19
    using f = bool(Sales_data const&, Sales_data const&);
    multiset<Sales_data,f* > bookstore(compareIsbn);
    multiset<Sales_data,f*>::iterator i = bookstore.begin();



//11.18
    map<string,string> mapa = { {"1","11"},{"2","22"} };\
    for (map<string,string>::iterator it = mapa.begin(); it != mapa.end();++it)
        cout << it->first << " " << it->second << endl;



//11.17
    copy(v.begin(), v.end(), inserter(c,c.end()));//v的全部元素插入到 c容器c.end()开始位置 c时set集合会自动排序
    copy(v.begin(), v.end(), back_inserter(c));//不合法 因为c这set集合不支持push_back;
    copy(c.begin(), c.end(), inserter(v,v.end()));//吧c元素按顺序 插入到v的队尾
    copy(c.begin(), c.end(), back_inserter(v));//和上行一样



//11.16
    map<int, vector<int>> mapa ={ {1,{1,2,3}},{2,{1,2,3} } };
    auto map_iter = mapa.begin();
    int i = map_iter->second[2];
    cout << i <<endl;



//11.15
    key_type 和 value_type 时一格意思就是关键字类型
    mapped_tyep 为关键字关联值 的类型



//11.14
        map<string, vector<pair<string,string>>> mapa= {
            {"yang",    {  {"rui","09-11"},{"niu","09-12"}  }     }
            };



//11.13
        vec.push_back({*in++,*ini++});
        vec.push_back(pair<string,int>(*in++,*ini++));
        vec.push_back(make_pair(*in++,*ini++));




//11.12
    ifstream input("data1.txt");	//读取文件流
    ifstream inputb("data2.txt");
	istream_iterator<string> in(input), en; //in和读取文件流绑定
	istream_iterator<int>ini(inputb),eni;
    vector<pair<string,int>> vec;
	while(in != en && ini != eni)
        vec.push_back({*in++,*ini++});
    for (auto i : vec)
        cout<< i.first << i.second << endl;



//11.11
    using f = bool(Sales_data const&, Sales_data const&);
    multiset<Sales_data,f* > bookstore(compareIsbn);
    //我写bool(Sales_data const&, Sales_data const&)* 死活不对- -只好查了下


//11.10
    map<vector<int>::iterator,int> mapa;
    map<list<int>::iterator,int> mapa;
    //测试了能

//11.9
    map<string,list<int>> mapa;



//11.8
    vector<int> vec = {0,1,2,3,4,5,6,1,2,3};
    sort(vec.begin(),vec.end());
    auto iter = unique(vec.begin(),vec.end());
    vec.erase(iter, vec.end());
    for (auto i : vec)
        cout << i << endl;
    //优点很明显 我这里要写4行命令 而set一行就行 而且vector的元素内容如果多了.删除重复将非常慢.


//11.7      //这破书没写怎么添加 关联值不是数字的map集合.... 就要我写添加元素... 看了网上例题写push_back().....这题算我写错把.
    map<string, vector<string>> demo= {{"yang",{"rui","niu"} },{"yu",{"rui","niu"} } };
    demo.insert({"nana",{"ni","hao"}});


//11.6
    set和list区别太大了 第一list是链表形式且每元素右顺序排列,右编号,可重复
    而set 不可重复,不是链表形式等.


//11.5
    //分情况 map在很多需要查找很多信息时候使用非常好 而set则是唯一对于很多不可重复编号是好用的.



//11.4
    map<string, size_t> word;
    string s;
    while(cin >> s){
        s[0] = tolower(s[0]);
        for (size_t i =0; i <= s.size(); ++i){  //我这里写!= 然后错误半天没找出来.....
            if(s[i] == '.' || s[i] == ',')
                s = s.erase(i,1);
        }
        ++word[s];
    }
    for (auto &i : word)
        cout << "出现" << i.first << "的次数为:" << i.second << endl;



//11.3
map<string, size_t> word;
    string s;
    while(cin >> s)
        ++word[s];
    for (auto &i : word)
        cout << "出现" << i.first << "的次数为:" << i.second << endl;



//11.2
    list    临时组建规模小的组织随意加入删除
    vector  一些纪录; 纪录永远保存并且顺序固定
    deque   排队名单只有尾添加和 首删除
    map     纪录某些东西出现次数啊, 身份证姓名啊; 每个人员纪录啊;
    set     保存永远不重复的东西如身份证



//11.1
    不同多了 map能同时保存两个类型值; 而vector只能保存一个
    vector是顺序保存 而map可以顺序可以无序;
    vector的元素值可以相同不同, 而map可以设置只能不同;


*/
