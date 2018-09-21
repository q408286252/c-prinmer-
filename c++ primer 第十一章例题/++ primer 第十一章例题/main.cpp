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

#include "Sales_data.h"
//#include "Sales_item.h"

using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() < rhs.isbn();
}
pair<string, int>  process(vector<string> &v){
    if(!v.empty())  //v为空则
        //return {v.back(),v.back().size()};
        return pair<string,int>(v.back(),v.back().size());
    else
        return pair<string,int>();  //空返回
}

int main()
{

    //for (auto i : v)
     //   cout << i << endl;
    //cout << typeid( i ).name() <<endl;
    //Sales_data la("50"), lb("60");
    using f = bool(Sales_data const&, Sales_data const&);
    multiset<Sales_data,f* > bookstore(compareIsbn);
    multiset<Sales_data,f*>::iterator i = bookstore.begin();
    /*
    vector<int> vec = {0,1,2,3,4,5,6,1,2,3};
    sort(vec.begin(),vec.end());
    auto iter = unique(vec.begin(),vec.end());
    vec.erase(iter, vec.end());
    for (auto i : vec)
        cout << i << endl;
        */
}
    /*
    map<string, size_t> word_count;
    set<string> exclude =  {"111","222","333"};
    string word;
    while (cin>> word)
        //变成只统计111 222 333之外的string次数
        if (exclude.find(word) == exclude.end() )   //在关键字容器查找同名关键字 如果空迭代器则:
            ++word_count[word];
    for (const auto &w : word_count)
        cout << w.first << "拉" << w.second << ((w.second > 1) ? "times" : "time" ) << endl;
    */


/*

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


//11.7      //这破书没写怎么增加map元素.... 就要我写添加元素...
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
