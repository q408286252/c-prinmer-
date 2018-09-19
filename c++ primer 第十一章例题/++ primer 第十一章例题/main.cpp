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

#include "Sales_data.h"
#include "Sales_item.h"

using namespace std;

int main()
{

    list<vector<string>> vecdata;
    vector<string> name = {"b1","b2","b3","c1","c2","c3"};

    for (auto str1 : name)
        for (auto str2 : name)
            for (auto str3 : name)
                for (auto str4 : name)
                    for (auto str5 : name)
                        for (auto str6 : name)
                            vecdata.push_back({str1,str2,str3,str4,str5,str6});
    //beg 是每个方案
    for (auto beg = vecdata.begin(); beg != vecdata.end(); ++beg){
        //删除开头c1 c2 c3
        if ((*beg)[0] != "b1" && (*beg)[0] != "b2" && (*beg)[0] != "b3" ){
            beg = vecdata.erase(beg); //删除这个迭代器元素
            --beg;  //上移一格
        //结尾必须是c
        } else if ( (*beg)[5] != "c1"
                   &&(*beg)[5] != "c2"
                   &&(*beg)[5] != "c3"
                   ){
            beg = vecdata.erase(beg);
            --beg;
        //删除元素重复的
        }else if ( 1 != count(beg->begin(), beg->end(), string("b1"))
                   || 1 != count(beg->begin(), beg->end(), "b2")
                   || 1 != count(beg->begin(), beg->end(), "b3")
                   || 1 != count(beg->begin(), beg->end(), "c1")
                   || 1 != count(beg->begin(), beg->end(), "c2")
                   || 1 != count(beg->begin(), beg->end(), "c3")
                   ){
            beg = vecdata.erase(beg);
            --beg;
        }else {
            int i = 0;  //控制i
            int siz = 0;
            siz += count(beg->begin(),(beg->begin())+3, "b1");
            siz += count(beg->begin(),(beg->begin())+3, "b2");
            siz += count(beg->begin(),(beg->begin())+3, "b3");
            //前三元素不能出现三次b1 b2 b3
            if (siz ==3){
                i += 1;
                goto en;
            }
            //begg尾每个方案的元素迭代器
            for (auto begiter = beg->begin(); begiter != (*beg).end();++begiter){
                //遇到元素c1c2c3 时 且 之前元素没有b1b2b3
                if ( (*begiter) == "c1" && begiter == find(beg->begin(), begiter, string("b1") ) ){
                    i += 1;
                    break;
                } else if (*begiter == "c2" && begiter == find(beg->begin(), begiter, "b2") ){
                    i += 1;
                    break;
                } else if (*begiter == "c3" && begiter == find(beg->begin(), begiter, "b3") ){
                    i += 1;
                    break;
                }
            }
            en:
            if (i != 0){
                beg = vecdata.erase(beg);
                --beg;
                i = 0;
            }
        }
    }
    ofstream out("data.txt",ofstream::app);
    //显示剩下方案:
    for (auto i : vecdata)
        out << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << " " << i[4] << " " << i[5] << endl;
}
    /*
    map<string, size_t> word;
    string s;
    while(cin >> s){
        s[0] = tolower(s[0]);
        for (size_t i =0; i <= s.size(); ++i){
            if(s[i] == '.' || s[i] == ',')
                s = s.erase(i,1);
        }
        ++word[s];
    }
    for (auto &i : word)
        cout << "出现" << i.first << "的次数为:" << i.second << endl;
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
