#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //�����ַ��ж�(�Ƿ��Ƿ��� ���� ��� ��ĸ�� ʲô��.)�����Ŀ�
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����
#include <fstream>  //�ļ�IO
#include <sstream>  //strIO
#include <list>     // ��������
#include <deque>    // ˫��vector

#include "Sales_data.h"

using namespace std;



int main()
{

    vector<int> iv;
    vector<int>::iterator iter = iv.begin(),
                         mid = iv.begin() + iv.size()/2;
    while (iter != mid)
        if (*iter == some_val)
            iv.insert(iter, 2 * some_val);

    //����1 some_val��ɶ?
    //����2 ���п���while��ѭ��
    //����3 ���������Ԫ��ָ���ʧЧ

    int some_val = 4;
    vector<int> iv = {0,1,2,3,4,5,6,7,8,9,10}, ivb;
    vector<int>::iterator iter = iv.begin(),
                         mid = iv.begin() + iv.size()/2;
    while (iter != mid){
        if (*iter == some_val)
            ivb.insert(ivb.begin(), 2 * some_val);
        ++iter;
    }
    cout << ivb[0] << endl;


/*
    string word;
    vector<string> strs;
    auto iter = strs.begin()
    //cin�����string��word ֻҪcin����ֹһֱѭ��
    while (cin >> word)
        //word����strs�ĵ�������; Ȼ�� ˢ��iter�ĵ�����λ�õ��µ��ײ�;
        iter = strs.insert(iter, word);
    for (auto ip = strs.begin(); ip != strs.end(); ++ip)
        cout << *ip << endl;

    list<int> ilsa = {0,1,2,3,4};
    deque<int> dequesa, dequesb;
    for (auto ip = ilsa.begin(); ip != ilsa.end(); ++ip)
        if ( (*ip%2) == 1 ){
            dequesa.push_back(*ip);
        }else{
            dequesb.push_back(*ip);
        }
    cout << dequesa[0] << endl;

    list<string> ils;
    string stra;
    while (cin >> stra)
        ils.emplace_back(stra);
    for (auto ip = ils.begin(); ip != ils.end(); ++ip)
        cout << *ip << endl;

    vector<Sales_data> c;
    c.push_back(Sales_data("978-059",25,15.99));
    cout << c[0].name << endl;
    */


}

/*
    //9.22
    //�������
    vector<int> iv;
    vector<int>::iterator iter = iv.begin(),
                         mid = iv.begin() + iv.size()/2;
    while (iter != mid)
        if (*iter == some_val)
            iv.insert(iter, 2 * some_val);
    //����1 some_val��ɶ?
    //����2 ���п���while��ѭ��
    //����3 ���������Ԫ��ָ���ʧЧ

    //�޸ĺ����
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
    //cin�����string��word ֻҪcin����ֹһֱѭ��
    while (cin >> word)
        //word����strs�ĵ�������; Ȼ�� ˢ��iter�ĵ�����λ�õ��µ��ײ�;
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
    //����д������Ҫ���ı��-. =

    //9.18
    deque<string> ils;
    string stra;
    while (cin >> stra)
        ils.emplace_back(stra);
    for (auto ip = ils.begin(); ip != ils.end(); ++ip)
        cout << *ip << endl;


    //9.17
    ����1: ��������Ҫһ�� 2.Ԫ��������ͬ 3.Ԫ�����Ϳɱ�


    //9.16
    list<int> v1 = {1,2,3,4,};
    vector<int> v2 = {1,2,3,4};
    vector<int> v3(v1.begin(),v1.end());    //�Ұ�v1Ԫ��д��v3Ȼ�����Ƚ϶�û��for autoָ�밤���ƶ�ʶ��
    if ( v3 == v2)
        cout << "v1Ԫ�غ�c2���" << endl;


    //9.15
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {1,2,3,4};
    if (v1 == v2)
        cout << "v1Ԫ�غ�c2���" << endl;


    //9.14
    list<const char*> ls = {"a","at","are"};
    vector<string> lsv;
    lsv.assign(ls.begin(), ls.end());

    //9.13
    list<int> ls = {0,1,2,3};
    vector<double> lsv(ls.begin(), ls.end());


    //9.12
    ����һ�������Ĺ��캯�� �����Ҫ����Ԫ�� ����������Ԫ��������ͬ,
    �����ܵ������Ĳ���Ҫ������ͬ. ����ֻҪԪ��ֵ��ת�� Ԫ������Ҳ���Բ�ͬ.


    //9.11
    vector<int> i = {0,1,2,3};; //0,1,2,3
    vector<int> i1; //��
    vector<int> i2(i);  //0,1,2,3
    vector<int> i3(i.begin(), i.end());//0,1,2,3
    vector<int> i4{0,1,2,3};//0,1,2,3
    vector<int> i5 = i;//0,1,2,3


    //9.10
    vector<int> v1; //vecotr����Ԫ��Ϊint;
    const vector<int> v2;   //�����̶����� Ԫ��Ϊint �޷��޸�
    auto it1 = v1.begin(), it2 = v2.begin();    //vector<int>::iterator
    auto it3 = vi.cbegin(), it4 = v2.cend();    //vector<int>::const_iterator

    //9.9
    ��ͬ��:һ��Ϊ��ͨ���������޸�;һ��Ϊ���������������޸�ָ��λ��;

    //9.8
    ��ȡ��Ҫ list<string>::iterator ����������;  д������Ϊ: ������[list<sring>::size_type] ֱ�Ӹ���.

    //9.7
    ����vector��int ��Ҫ vector<int>::size_type ����;  д��:������[vector<int>::size_type]


    //9.6
    list<int> lst1;
    list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
    //while (iter1 < iter2)  {...}    //���� ָ��ȴ�С ��end��ָ�����޷���
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
    ��Χ���������������Ԫ��ֵ;���������������� begin��endָ�����


    //9.2
    list<deque<int>> ls;


    //9.1
    ��ȡ�̶������ĵ���,�����ǲ����ֵ������. ����ǲ��뱣�治�������ѡforward_list
    ��ȡδ֪�����ĵ������ǲ��뵽ĩβ, ɾ��ͷ������  ���ѡdeque;
    ��һ���ļ���ȡδ֪����֤��.����������Ȼ���ӡ����׼���:  list


*/
