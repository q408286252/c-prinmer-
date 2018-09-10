#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //单个字符判断(是否是符号 数字 标点 字母啊 什么的.)函数的库
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数
#include <fstream>  //文件IO
#include <sstream>  //strIO
#include <list>     // 链表容器
#include <forward_list> //单向链表
#include <deque>    // 双向vector
#include <array>

#include "Sales_data.h"

using namespace std;
//bdfhikltgjpqy
//acemnorsuvwxz

int main() {


    string s = "ataaaatatattaataa";
    //cin >> s;
    int i=0,ii=0;
    string::size_type pos=0, posb, posbegin;
    while ( (pos = s.find_first_of("acemnorsuvwxz",pos)) != string::npos ){
        if (i ==0 ){ //第一次循环开始记录始;
            posb = pos;
            ++i;
        } else if(posb + i == pos){ //如果下标连续则;
            ++i;
            if (i > ii){    //连续记录超过 历史纪录就跟新:
                ii = i;
                posbegin = posb;
            }
        } else{ //一旦不连续 则
            if (i > ii) {   //和历史纪录对比如果大则
                ii = i;   //连续次数赋予新值
                posbegin = posb;    //并把起始终端保留下来
                i = 1;
                posb = pos;
            } else{         //比历史纪录小则刷新初始值;
                i = 1;
                posb = pos;
            }
        }
        ++pos;
    }

    for (int is = 0; is != ii; ++is)
        cout << s[posbegin+is];
    cout << s.length() << endl;
}



/*
    //9.49    挺耗时间的..
    //我看了下其他人的csdn写这例子有人写 s.length() 书上没写它从哪找到的 笑!!! 有人抄之前人写的. 有人写容器形式; 貌似这种纯if else的很受鄙视啊.
    string s = "ataaaatatattaataa";
    //cin >> s;
    int i=0,ii=0;
    string::size_type pos=0, posb, posbegin;
    while ( (pos = s.find_first_of("acemnorsuvwxz",pos)) != string::npos ){
        if (i ==0 ){ //第一次循环开始记录始;
            posb = pos;
            ++i;
        } else if(posb + i == pos){ //如果下标连续则;
            ++i;
            if (i > ii){    //连续记录超过 历史纪录就跟新:
                ii = i;
                posbegin = posb;
            }
        } else{ //一旦不连续 则
            if (i > ii) {   //和历史纪录对比如果大则
                ii = i;   //连续次数赋予新值
                posbegin = posb;    //并把起始终端保留下来
                i = 1;
                posb = pos;
            } else{         //比历史纪录小则刷新初始值;
                i = 1;
                posb = pos;
            }
        }
        ++pos;
    }

    for (int is = 0; is != ii; ++is)
        cout << s[posbegin+is];



    //9.48
    string name = "r2d2" , numbers = "0123456789";
    numbers.find(name); //返回string::npos成员 类型为const string::size_type 无符号类型;


    //9.47
    //啊啊啊啊find_first_not_of 这个写....的识别容器有点大.不想写= = 因该后面正则能快速解决.
    string s = "ab2c3d7R4E6";
    string::size_type pos=0;
    while ( (pos = s.find_first_of("0123456789",pos)) != string::npos ){
        cout << s[pos];
        ++pos;
    }
    cout <<  endl;
    pos = 0;
    while ( (pos = s.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM",pos)) != string::npos ){
        cout << s[pos];
        ++pos;
    }



    //9.46
    string &replacedef(string &s,const string &stra,const string &strb){
    for (auto i = 0; i != s.size(); ++i){
        string name = s.substr(i,4);
        //cout << name << endl;
        if (name == "yang"){
            s.insert(i,stra);
            s.insert(i+7,strb);
            i+=3;
        }
    }
    return s;
}


int main() {

    string s = "and two yang three tho";
    cout << replacedef(s,"Mr.","Jr.") << endl;
}



    //9.45
    //事实证明用迭代器写很恶心 函数接受迭代器的方法和下标比少多了.
string &replacedef(string &s,const string &stra,const string &strb){
    for (auto i = s.begin(); i != s.end(); ++i){
        char s1[] = {*i,*(i+1),*(i+2),*(i+3)};
        string name(s1,4);
        //auto *ip = &*i;  上两行可以换成
        //string name(ip,4);
        if (name == "yang"){
            i = s.insert(i,stra.begin(),stra.end());
            i += 7;
            i = s.insert(i,strb.begin(),strb.end());
        }
    }
    return s;
}


int main() {

    string s = "and two yang three tho";
    cout << replacedef(s,"Mr.","Jr.") << endl;
}


    //9.44
    void replacedef(string &s,const string &oldVal,const string &newVal){

    for (int i = 0; i != s.size(); ++i){
        string stra = s.substr(i,i+3);
        if (stra == oldVal){
            s.replace(i,3,newVal);
        }
    }
}
int main() {

    string s = "and two three tho";
    replacedef(s,"tho","though");
    cout << s << endl;
}



    //9.43
void replacedef(string &s,const string &oldVal,const string &newVal){
    //没留意写成下标形式了懒得改.
    for (int i = 0; i != s.size(); ++i){
        string stra = s.substr(i,i+3);
        if (stra == oldVal){
            s.erase(i,3);
            s.insert(i,newVal);
        }
    }
}
int main() {

    string s = "and two three tho";
    replacedef(s,"tho","though");
    cout << s << endl;
}

    //9.42
    char c;
    string stra;
    while (cin >>c){
        stra = stra + c;
    }
    cout << stra << endl;


    //9.41
    vector<char> css = {'h','e','l','l','o'};
    auto *ip = &css[0];
    string s(ip,5);
    //我热我调了半天容器. 感觉不对 设定个指针就行了.........


    //9.40
    256元素后还是1024, 512也是 1000个是2000; 1048个时候时2048
    //这个2000很好玩.是初始化的元素添加不会准寻2的谬次方定律吗?

    //9.39
        vector<string> svec;
    svec.reserve(1024); //给容器设置的1024元素的内存
    string word;
    while (cin >> word)
        svec.push_back(word);   //每有输入则保存到容器里;
    svec.resize(svec.size() + svec.size()/2);   //输入终止时扩大容器元素至1.5倍



    //9.38
    0 - 1 - 2 -4 -8 -16 - 32-64-128


    //9.37
    array因为是固定数组他不需要capacity() 因为 分配的内存元素肯定和size()相等
    而list 是双向链表; 它是分散内存链接在一起 压根不要重新分配


    //9.36
    不可能


    //9.35
    //capacity()是容器重新分配内存的最大元素数  size()是容器已有元素数
    //就相当于一个是给10张纸, 一个是写了3张纸这种性质



    //9.34
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while (iter != vi.end()){
        if (*iter % 2)  //奇数则:
            iter = vi.insert(iter,*iter);//迭代器前添加元素 并移动指针到添加元素位置
        ++iter; //遇到偶数死循环 因为 指针在循环中左侧添加元素 左移然后右移 等于一直左侧添加元素
    }
    for (auto &i : vi)
        cout << i;


    //9.33
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    auto begin = v.begin();
    while (begin != v.end()){
        ++begin;
        //这里会发生问题打比方 下行表达式移动到元素9 然后继续循环 接着移动到尾后 尾后添加元素这是错误的
        v.insert(begin,42);
        ++begin;
    }
    for (auto &i : v)
        cout << i;


    //9.32
    *iter++ //说实话翻书前面部分有点烦. 而且参数到底调用前后修改这种事情很烦躁的..
    //不合法. 因为他是 *(iter++) 而且是右结合 导致左参数 iter也污染
    //表达式变成  把当前奇数给迭代器下一个位置可惜容器最后一个是9那么他的下一个是尾后不存在=, =
    容器最后元素变成10就能过了
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9,10};
    auto iter = vi.begin();
    while (iter != vi.end()){
        if (*iter % 2){ //奇数则
            iter = vi.insert(iter,*iter++ ); //奇数位置前一个位置 添加 同样值 并移动迭代器
            ++iter;  //移动两格
            ++iter;
        }else{
            iter = vi.erase(iter);  //偶数删除当前元素 并跟新迭代器
        }
    }
    for (auto &i : vi)
        cout << i;


    //9.31
    因为list无法一次性移动两个位置;
        list<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while (iter != vi.end()){
        if (*iter % 2){ //奇数则
            iter = vi.insert(iter,*iter); //奇数位置前一个位置 添加 同样值 并移动迭代器
            ++iter;  //移动两格
            ++iter;
        }else{
            iter = vi.erase(iter);  //偶数删除当前元素 并跟新迭代器
        }
    }
    for (auto &i : vi)
        cout << i;

    //而forward_list复杂的多需要双迭代器 和 特殊函数;
    forward_list<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin(), ipa  = vi.before_begin();
    while (iter != vi.end()){
        if (*iter % 2){ //奇数则
            iter = vi.insert_after(ipa,*iter); //奇数位置前一个位置 添加 同样值 并移动迭代器
            ++iter;  //移动两格
            ipa = iter;
            ++iter;
        }else{
            iter = vi.erase_after(ipa);  //偶数删除当前元素 并跟新迭代器
        }
    }
    for (auto &i : vi)
        cout << i;



    //9.30
    限制有 如果需要初始化那么这个元素类型有初始化的默认值. 如果没有默认值则会戳五;


    //9.29
    会在vec的25个元素后面添加75个元素默认初始化;
    vec.resize(10) 会会删除除前10个元素外所有元素;


    //9.28
void lala(forward_list<string> &fstrs, const string &stra,const string &strb){
    int i = 0;
    auto ipa = fstrs.before_begin(), ip = fstrs.begin();
    while (ip != fstrs.end()){
        if (*ip == stra){
            ++i;
            ip = fstrs.insert_after(ip, strb);
        }else {
            ipa = ip;
            ++ip;
        }
    }
    if (i == 0)
        fstrs.insert_after(ipa, strb);
}

int main() {

    forward_list<string> fl = {"aa","bb","cc","dd"};
    lala(fl,"cc","dd");
    for (auto &i : fl)
        cout << i  << endl;
}


    //9.27
    forward_list<int> flist = {0,1,2,3,4,5,6,7,8,9};
    auto ipa = flist.before_begin();
    auto ip = flist.begin();
    while ( ip != flist.end()){
        if (*ip % 2 == 1)
            ip = flist.erase_after(ipa);
        else{
            ipa = ip;
            ++ip;
        }
    }
    for (auto i : flist)
        cout << i;


    //9.26
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89}; //array不支持迭代器
    vector<int> ints;
    list<int> lists;
    for (auto &a: ia){
        ints.push_back(a);
        lists.push_back(a);
    }

    auto ip = ints.begin();
    while (ip != ints.end())
        if (*ip % 2 ==0)
            ip = ints.erase(ip);
        else
            ++ip;

    auto ipb = lists.begin();
    while (ipb != lists.end())
        if (*ipb % 2 ==1)
            ipb = lists.erase(ipb);
        else
            ++ipb;


    //9.25
    elem1 == elem2 则什么都没删除
    elem1和elem2都是尾后 也是什么都没删除;
        vector<int> ints = {0,1,2,3};
    ints.erase(ints.begin(), ints.begin());
    cout << ints[0] << endl;




    //9.24
    vector<int> ints = {0,1,2,3};
    cout << ints.at(0) << " " << ints[0] << " " << ints.front() << " " << *ints.begin() << endl;
    空容器编译器不会报错但 终端会


    //9.23
    c容器数为一则:
    val 值是 元素值;
    val2 值是 元素值;
    val3 这里last是未知变量;
    val4 值是 元素值;

    //9.22
    //错误代码
    vector<int> iv;
    vector<int>::iterator iter = iv.begin(),
                         mid = iv.begin() + iv.size()/2;
    while (iter != mid)
        if (*iter == some_val)
            iv.insert(iter, 2 * some_val);
    //错误1 some_val是啥?
    //错误2 很有可能while死循环
    //错误3 往容器添加元素指针会失效

    //修改后代码
    int some_val = 4;
    vector<int> iv = {0,1,2,3,4,5,6,7,8,9,10}, ivb;
    vector<int>::iterator iter = iv.begin(),
                         mid = iv.begin() + iv.size()/2;
    while (iter != mid){
        if (*iter == some_val)
            ivb.insert(ivb.begin(), 2 * some_val);
        ++iter;
    }


    //9.21
    string word;
    vector<string> strs;
    auto iter = strs.begin()
    //cin输出的string给word 只要cin不终止一直循环
    while (cin >> word)
        //word插入strs的迭代器首; 然后 刷新iter的迭代器位置到新的首部;
        iter = strs.insert(iter, word);


    //9.20
    list<int> ilsa = {0,1,2,3,4};
    deque<int> dequesa, dequesb;
    for (auto ip = ilsa.begin(); ip != ilsa.end(); ++ip)
        if ( (*ip%2) == 1 ){
            dequesa.push_back(*ip);
        }else{
            dequesb.push_back(*ip);
        }


    //9.19
    list<string> ils;
    string stra;
    while (cin >> stra)
        ils.emplace_back(stra);
    for (auto ip = ils.begin(); ip != ils.end(); ++ip)
        cout << *ip << endl;
    //我这写法不需要做改变的-. =

    //9.18
    deque<string> ils;
    string stra;
    while (cin >> stra)
        ils.emplace_back(stra);
    for (auto ip = ils.begin(); ip != ils.end(); ++ip)
        cout << *ip << endl;


    //9.17
    限制1: 容器类型要一样 2.元素类型相同 3.元素类型可比


    //9.16
    list<int> v1 = {1,2,3,4,};
    vector<int> v2 = {1,2,3,4};
    vector<int> v3(v1.begin(),v1.end());    //我把v1元素写给v3然后做比较而没用for auto指针挨个移动识别
    if ( v3 == v2)
        cout << "v1元素和c2相等" << endl;


    //9.15
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {1,2,3,4};
    if (v1 == v2)
        cout << "v1元素和c2相等" << endl;


    //9.14
    list<const char*> ls = {"a","at","are"};
    vector<string> lsv;
    lsv.assign(ls.begin(), ls.end());

    //9.13
    list<int> ls = {0,1,2,3};
    vector<double> lsv(ls.begin(), ls.end());


    //9.12
    接受一个容器的构造函数 它如果要拷贝元素 必须容器和元素类型相同,
    而接受迭代器的不需要容器相同. 而且只要元素值能转换 元素类型也可以不同.


    //9.11
    vector<int> i = {0,1,2,3};; //0,1,2,3
    vector<int> i1; //空
    vector<int> i2(i);  //0,1,2,3
    vector<int> i3(i.begin(), i.end());//0,1,2,3
    vector<int> i4{0,1,2,3};//0,1,2,3
    vector<int> i5 = i;//0,1,2,3


    //9.10
    vector<int> v1; //vecotr容器元素为int;
    const vector<int> v2;   //常量固定容器 元素为int 无法修改
    auto it1 = v1.begin(), it2 = v2.begin();    //vector<int>::iterator
    auto it3 = vi.cbegin(), it4 = v2.cend();    //vector<int>::const_iterator

    //9.9
    不同处:一个为普通迭代器可修改;一个为常量迭代器不能修改指针位置;

    //9.8
    读取需要 list<string>::iterator 迭代器类型;  写入类型为: 容器名[list<sring>::size_type] 直接覆盖.

    //9.7
    索引vector的int 需要 vector<int>::size_type 类型;  写成:容器名[vector<int>::size_type]


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
