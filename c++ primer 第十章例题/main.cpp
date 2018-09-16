#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //�����ַ��ж�(�Ƿ��Ƿ��� ���� ��� ��ĸ�� ʲô��.)�����Ŀ�
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����
#include <fstream>  //�ļ�IO
#include <sstream>  //strIO
#include <list>     // ˫���� ����
#include <forward_list> //����������
#include <deque>    // ˫��vector����
#include <array>    //�̶����� array
#include <stack>    //ջ������stack
#include <queue>    //���������� ����: priority_queue �� queue;
#include <algorithm>    //�󲿷��㷨����
#include <iterator> //���ֵ�����  ��������� ��������;���������;�ƶ�������;
#include <functional>   //��bind����;  ref(os) ����һ������ɿ�������   cref(os)��������ɿ���const����

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

void elimDups(vector<string> &vec){
    sort(vec.begin(), vec.end());//С��������
    auto bega = unique(vec.begin(), vec.end()); //ǰ���ظ�,�����ظ�ͷ������;
    vec.erase(bega, vec.end());//ɾ��֮��ĵ�����;
}

bool isShorter(const string &s1, const string &s2){
    return s1.size()<s2.size();
}
/*
void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //ɾ�ظ�
    auto en = stable_partition(vec.begin(),vec.end(),
                     [sz](const string &sa){ return sa.size() >=5;} );
    for_each(vec.begin(), en,
            [](const string &s){cout << s << " ";} );   //��ӡ���д���5�ַ�������Ԫ��
    cout << endl;
}

void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //ɾ�ظ�
    stable_sort(vec.begin(), vec.end(),
                bind(check_sizeb, _1, _2) ); //Ȼ���С����;
    auto beg = find_if(vec.begin(), vec.end(),   //���ش���5�ַ�������λ��
                    bind(check_size, _1 ,sz) );
    for_each(beg, vec.end(),
            [](const string &s){cout << s << " ";} );   //��ӡ���д���5�ַ�������Ԫ��
}
*/
bool check_sizeb(const string &sa, const string &sb){
    return sa.size()<sb.size();
}

bool check_size(const string &s, string::size_type sz){
    return s.size() > sz;
}
void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //ɾ�ظ�
    auto en = partition(vec.begin(), vec.end(),   //���ش���5�ַ�������λ��
                    bind(check_size,_1,sz) );
}

void f(string s, string souta, string soutb){
    ifstream input(s);
    ofstream output(souta,ofstream::app), outputb(soutb,ofstream::app);
    istream_iterator<int> in(input),en;
    for(; in != en; ++in){
        if ( *in %2 == 1){//������:
            output << *in << endl;
        } else{
            outputb << *in<< endl;
        }
    }
}

int main(){
    vector<int> vec= {0,1,2,3,4,5,6,7,8,9};
    list<int> ls(vec.rbegin()+3, vec.rend()-2);
    for (auto iter : ls )
        cout << iter << endl;
    //vector<string> line = {"a","a,b", ",", "b"};
    //string line = "abcd,efgh";
    //auto comma = find(line.crbegin(), line.crend(), ',' );	//����commaʱ�������������
	//		cout << string(comma.base(), line.cend()) << endl;
}

/*
for (auto r_iter = vec.crbegin(); r_iter != vec.crend(); ++r_iter)
        cout << *r_iter << endl;

    ifstream input("data.txt");
    istream_iterator<Sales_item> in(input),en;
    vector<Sales_item> vecl(in,en);
    sort(vecl.begin(),vecl.end(),[](const Sales_item &lhs, const Sales_item &rhs)->bool{return lhs.isbn() == rhs.isbn();} );

    //ÿ��ʵ��ѭ��
    for (auto iter = vecl.begin(); iter != vecl.end(); ++iter){
        //�ҵ���ѭ����һ����β�� ��ͬ����ʵ��
        auto ita = find_if(iter+1, vecl.end(), [iter](Sales_item &s){ return s.isbn()==iter->isbn(); });
        //�������:
        if (ita != vecl.end()){
            //��ǰѭ��ʵ�� �� �ҵ�ʵ�����¸�  ��ʼΪͬ����;
            cout << accumulate(iter, ita+1, Sales_item(iter->isbn())) << endl;
            ++iter;
        } else {
            cout << *iter << endl;
        }
    }
}

    //auto iter = find(vecl.begin(),vecl.end(),sta);
    //accumulate(vecl.begin(),vecl.end(), int(0));

    /*
        istream_iterator<Sales_item> in(input), eof;
    vector<Sales_item> books;
    while (in != eof)
        books.push_back(*in++);
    // cout << "Enter some lists of sales_item: " << endl;
    // istream_iterator<Sales_item> in(cin), eof;
    // vector<Sales_item> books(in, eof);     //another version

    sort(books.begin(), books.end(), [](const Sales_item &lhs, const Sales_item &rhs)->bool{return lhs.isbn() == rhs.isbn();} );
    for_each(books.cbegin(), books.cend(), [](const Sales_item &s) {cout << s << '\n'; });
    cout << endl;

    auto beg = books.begin(), end = books.begin();
    while (beg != books.end()) {
        end = find_if(beg, books.end(), [beg](Sales_item &s) {return s.isbn != beg->isbn; });
        cout << accumulate(beg, end, Sales_item(beg->isbn)) << endl;
        beg = end;
    }

    system("pause");
    return 0;
}
    /*
    istream_iterator<Sales_item> in(input),en;
    vector<Sales_item> vecl(in,en);
    sort(vecl.begin(),vecl.end(),[](const Sales_item &lhs, const Sales_item &rhs)->bool{return lhs.isbn() == rhs.isbn();} );
    string sta = "asd"; //Ҫ���ҵ���
    cout << accumulate(vecl.begin()->isbn, vecl.end()->isbn, Sales_item(vecl.begin()->isbn)) << endl;
    //auto iter = find(vecl.begin(),vecl.end(),sta);
    //accumulate(vecl.begin(),vecl.end(), int(0));

    for (auto i :vecl)
        cout << i << endl;
    /*
    find(vecl.begin(),vecl.end(),)
    Sales_item new1 = *in++;
    while (in != en){
        if (new1.isbn() == in -> isbn() ){
            new1 += *in++;
        }else {
            cout << new1 << endl;
            new1 += *in++;
       }
    }
    cout << new1 << endl;

    /*
    istream_iterator<int> in(cin), en;
    ostream_iterator<int> out(cout, "\n");
    vector<int> veci(in,en);
    sort(veci.begin(),veci.end());
    unique_copy(veci.begin(),veci.end(),out);

    /*
    for (auto i : vecs)
        cout << i << endl;
    /*
    istream_iterator<Sales_item> item_iter(cin), eof;
    ostream_iterator<Sales_item> out_iter(cout,"\n");
    Sales_item sum = *item_iter++;  //��һ��ʵ������sum ������ָ��ڶ���;
    while (item_iter != eof){ //�ڶ���ʵ����ʼ��βָ����ֹ
        if (item_iter -> isbn() == sum.isbn() ) //�ڶ���ʵ����isbnʶ���� ������ڵ�һ��ʵ�������:
            sum += *item_iter++;//ˢ��sum��ָʵ��;
        else {
            out_iter = sum; //����ǵ�һ��ʵ��;
            sum = *item_iter++;//ˢ��sum��ָʵ��;
        }
    }
    out_iter = sum;

    vector<int> vec = {1,2,3,4,5,6};
    for (auto i : vec)
        out = i;
    cout << endl;

    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    list<int> lst,lsta,lstb;
    copy(vec.begin(),vec.end(),inserter(lst,lst.begin()));  //123456789
    copy(vec.begin(),vec.end(),back_inserter(lsta));    //123456789
    copy(vec.begin(),vec.end(),front_inserter(lstb));   //987654321
    for (auto &i : lst)
        cout << i;
    for (auto &i : lsta)
        cout << i;
    for (auto &i : lstb)
        cout << i;

    vector<string> words = {"a","b","aaaaaaaa","bbbbbb","aaaa","aaaaa","c","a","b"};
    biggies(words, 5);


    vector<string> words = {"a","b","aaaaaaaa","bbbbbb","aaaa","c","a","b"};
    elimDups(words);
    stable_sort(words.begin(), words.end(),
                [](const string &sa, const string &sb){return sa.size()<sb.size();} );
    for (const auto &s : words)
        cout << s << endl;

    int a = 10;
    auto f = [a](const int &ia){ return ia+a;};
    cout << f(20) << endl;


    vector<string> words = {"a","b","aaaaaaaa","bbbbbb","aaaa","c","a","b"};

    for (auto ip = words.begin(); ip != words.end(); ++ip)
        cout << *ip << endl;

    int ia =10;
    //auto f = [] {return 42;};
    auto f = [&ia]() -> bool{if (ia>0) return --ia; else return 0; };
    for (int i =0; i != 10; ++i){
        cout << f() << endl;
    }
    */



/*
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
        if ( *in %2 == 1){//������:
            output << *in << endl;
        } else{
            outputb << *in<< endl;
        }
    }
}

int main(){
    f("data.txt", "a.txt", "b.txt");
}




//10.32 Ϊʲôһ��Ҫʹ��find................... �������ϴ𰸺ܶ඼Ϲ����д �ܲ���.����
//���Ķ���......... ����2��Сʱ?
int main(){
    ifstream input("data.txt");
    istream_iterator<Sales_item> in(input),en;
    vector<Sales_item> vecl(in,en);
    sort(vecl.begin(),vecl.end(),[](const Sales_item &lhs, const Sales_item &rhs)->bool{return lhs.isbn() == rhs.isbn();} );

    //ÿ��ʵ��ѭ��
    for (auto iter = vecl.begin(); iter != vecl.end(); ++iter){
        //�ҵ���ѭ����һ����β�� ��ͬ����ʵ��
        auto ita = find_if(iter+1, vecl.end(), [iter](Sales_item &s){ return s.isbn()==iter->isbn(); });
        //�������:
        if (ita != vecl.end()){
            //��ǰѭ��ʵ�� �� �ҵ�ʵ�����¸�  ��ʼΪͬ����;
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
back_inserter β����� ���ǲ�������ƨ�ɺ���;
front_inserter �ײ����� ���ǰ�Ԫ�ز��뵽����ǰ��;
inserter    ָ��ĳλ�� �����ﵽ�������֮���λ��



//10.25         �����10.22ûɶ����
void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //ɾ�ظ�
    auto en = partition(vec.begin(), vec.end(),   //���ش���5�ַ�������λ��
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
??? ��ΪʲôҪ֪�����ܽ��ܼ�������?;����д��һ��5������...�����������ʮ����������?
using std::placeholders::_29; //�����ﻹ֧��. Ҳ����˵Ĭ�ϲ�д�Ĳ���֧��29��


//10.22      �о������. �����ظ�ʹ�õ�lambda
bool check_size(const string &s, string::size_type sz){
    return s.size() >= sz;
}
bool check_sizeb(const string &sa, const string &sb){
    return sa.size()<sb.size();
}

void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //ɾ�ظ�
    stable_sort(vec.begin(), vec.end(),
                bind(check_sizeb, _1, _2) ); //Ȼ���С����;
    auto beg = find_if(vec.begin(), vec.end(),   //���ش���5�ַ�������λ��
                    bind(check_size, _1 ,sz) );
    for_each(beg, vec.end(),
            [](const string &s){cout << s << " ";} );   //��ӡ���д���5�ַ�������Ԫ��
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
    elimDups(vec);    //ɾ�ظ�
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
    elimDups(vec);    //ɾ�ظ�
    auto en = stable_partition(vec.begin(),vec.end(),
                     [sz](const string &sa){ return sa.size() >=5;} );
    for_each(vec.begin(), en,
            [](const string &s){cout << s << " ";} );   //��ӡ���д���5�ַ�������Ԫ��
    cout << endl;
}



//10.18
void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //ɾ�ظ�
    stable_sort(vec.begin(), vec.end(),
                [](const string &sa, const string &sb)
                { return sa.size()<sb.size(); } ); //Ȼ���С����;
    auto en = partition(vec.begin(), vec.end(),   //���ش���5�ַ�������λ��
                    [sz](const string &a){ return a.size() >= sz;} );
    for_each(vec.begin(), en,
            [](const string &s){cout << s << " ";} );   //��ӡ���д���5�ַ�������Ԫ��
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
    elimDups(vec);    //ɾ�ظ�
    stable_sort(vec.begin(), vec.end(),
                [](const string &sa, const string &sb)
                { return sa.size()<sb.size(); } ); //Ȼ���С����;
    auto beg = find_if(vec.begin(), vec.end(),   //���ش���5�ַ�������λ��
                    [sz](const string &a){ return a.size() >= sz;} );
    for_each(beg, vec.end(),
            [](const string &s){cout << s << " ";} );   //��ӡ���д���5�ַ�������Ԫ��
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
    ��Ϊ��Ӻ�ɾ���ᵼ�´���ĵ�����ʧЧ��!;



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
    back_inserter() ����ǲ��������,���޸�������С�ĺ���
    ����׼����û�н�����  �������Ǳ�׼�������;



//10.7
    vector<int> vec;
    list<int> lst;
    int i;
    while (cin >> i)
        lst.push_back(i);
    //copy(lst.cbegin(),lst.cend(),vec.begin());//����������. ��Ϊvec�ǿ� �޷�������ȥ
    copy(lst.cbegin(),lst.cend(),back_inserter(vec));
    for (auto i : vec)
        cout << i << endl;


    vector<int> vec;
    vec.reserve(10);//������Ȼ�������ڴ�Ԫ�ظ��� �����������ǿյ�.
    fill_n(back_inserter(vec),10,0);
    for (auto i : vec)
        cout << i << endl;



//10.6
    vector<int> vec = {0,1,2,3,4,5,6};
    fill_n(vec.begin(), vec.size(), int(0));
    for (auto i : vec)
        cout << i << endl;



//10.5
    �����޷�����, ��Ϊc����ַ����� string�ַ����޷� '+'



//10.4
    �д�0��ֵ����û�ж����� �����ͺ�double �ں��������޷������
    vector<double> v = {0.0,0.1,0.2,0.3};
    auto i = accumulate(v.cbegin(), v.cend(), double(0));
    cout << i << endl;



//10.3
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    auto result = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << "���:" << result << endl;


//10.2
    list<string> vec;
    string stra;
    while (cin >> stra)
        vec.push_back(stra);
    auto result = count(vec.cbegin(), vec.cend(), "a");
    cout << "���:" << result << endl;


//10.1
    vector<int> vec = {};
    int i;
    while (cin >> i)
        vec.push_back(i);
    auto result = count(vec.cbegin(), vec.cend(), 1);
    cout << "���:" << result << endl;

*/
