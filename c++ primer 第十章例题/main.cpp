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
#include <iterator> //��back_inserter()����

#include "Sales_data.h"

using namespace std;



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

void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);    //ɾ�ظ�
    auto en = stable_partition(vec.begin(),vec.end(),
                     [sz](const string &sa){ return sa.size() >=5;} );
    for_each(vec.begin(), en,
            [](const string &s){cout << s << " ";} );   //��ӡ���д���5�ַ�������Ԫ��
    cout << endl;
}


int main()
{
    /*
    vector<string> words = {"a","b","aaaaaaaa","bbbbbb","aaaa","c","a","b"};
    elimDups(words);
    stable_sort(words.begin(), words.end(),
                [](const string &sa, const string &sb){return sa.size()<sb.size();} );
    for (const auto &s : words)
        cout << s << endl;
        */
     /*
    int a = 10;
    auto f = [a](const int &ia){ return ia+a;};
    cout << f(20) << endl;
    */
    vector<string> words = {"a","b","aaaaaaaa","bbbbbb","aaaa","c","a","b"};
    biggies(words,5);

    for (auto ip = words.begin(); ip != words.end(); ++ip)
        cout << *ip << endl;

}


/*
//10.20



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
