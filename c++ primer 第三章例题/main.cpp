#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //����������ĸ�����жϺ���   ����isalnum()�����ж����ֻ��Ǳ���ַ�����
#include <vector>   //���ɶ�������� �׳��б�

#include "Sales_data.h" //���ص��ļ�

using namespace std;    //���������ռ䶼���ص�Ĭ�Ϲؼ�����

int main()
{   //3.20.2 ʮ��λ����  ûѧstring�ַ�int����ת��
    int int1;
    vector<int> list1;
    while (cin >> int1)
        if (int1 < 1000000){
            list1.push_back(int1/100000);
            int1 = int1 - int1/100000*100000;
            list1.push_back(int1/10000);
            int1 = int1 - int1/10000*10000;
            list1.push_back(int1/1000);
            int1 = int1 - int1/1000*1000;
            list1.push_back(int1/100);
            int1 = int1 - int1/100*100;
            list1.push_back(int1/10);
            int1 = int1 - int1/10*10;
            list1.push_back(int1/1);
        }
    for (decltype(list1.size()) i =0; i != list1.size()/2; ++i){
        cout << list1[i] + list1[list1.size()-1] << endl;
    }
    return 0;
}

/*
 //3.20.1 ��λ����  ûѧstring�ַ�int����ת��
    int int1;
    vector<int> list1;
    while (cin >> int1)
        if (int1 < 100000){
            list1.push_back(int1/10000);
            int1 = int1 - int1/10000*10000;
            list1.push_back(int1/1000);
            int1 = int1 - int1/1000*1000;
            list1.push_back(int1/100);
            int1 = int1 - int1/100*100;
            list1.push_back(int1/10);
            int1 = int1 - int1/10*10;
            list1.push_back(int1/1);
        }
    for (decltype(list1.size()) i =0; i != list1.size()-1; ++i){
        cout << list1[i] + list1[i+1] << endl;
    }
    return 0;

//3.19
    vector<int> i(10,42);
    vector<int> i1{42,42,42,42,42,42,42,42,42,42};
    vector<int> i2;
    for (int i = 0; i != 10; ++i)
        i2.push_back(42);
    //��һ����� ��Ϊд�Ĵ�����̼��
    return 0;

//3.18
    //���Ϸ�
    vector<int> ivec;
    ivec.push_back(42);
    return 0;

//3.17
    vector<char> v;
    string in;
    string str = "qwertyuiopasdfghjklzxcvbnm";
    string str1 = "QWERTYUIOPASDFGHJKLZXCVBNM";
    while (cin >> in)
        for (decltype(in.size()) la = 0; la != in.size(); ++la)
            v.push_back(in[la]);
    for (auto &i : v){
        for (decltype(str.size()) la = 0; la != str.size(); ++la ){
            if (str[la] == i)
               i  = str1[la];
        }
    }
    for (auto i:v)
        cout << i << endl;
    return 0;

 //3.16
    vector<int> v{1,2,3,4,5,6,7,8,9};
    for (auto &i : v)
        cout << i << endl;
    return 0;

//3.15
    vector<string> v2;
    string i;
    while (cin >> i)
        v2.push_back(i);

    cout << v2[1] << endl;
    return 0;

 //3.14
    vector<int> v2;
    int i;
    while (cin >> i)
        v2.push_back(i);

    cout << v2[1] << endl;
    return 0;

//3.13
    1. 0����
    2.10��'0'
    3.10��'42'
    4.1��'10'
    5.10��'42'
    6 10����
    7.10��"hi"

//3.12
    vector<vector<int>> ivec;       //��ȷivec��Ԫ��Ϊint�����б�
    vector<string> svec = ivec;     //����ivec��Ԫ��������vector<int> ����string
    vector<string> svec(10,"null"); //��ȷ

//3.11
    const string s = "Keep out!";
    for (auto &c : s){
        //****
    }   //�Ϸ�, ����Ϊ����
    return 0;

//3.10
    string strl;
    int i = 0;
    cin >> strl;
    for (auto c : strl){
        if (ispunct(c)){
            strl[i] = ' ';
        }
        ++i;
    };
    cout << strl << endl;
    return 0;

//3.9
�����е����Ϸ�  ��Ϊ�վ����� ���ĵ�һ���ַ��ǲ����ڵ�.

//3.8
    string str1 = "0 ;'";
    decltype(str1.size()) i = 0;
    while (i < str1.size())
        str1[i] = 'X', ++i;
    cout << str1  << endl;  //��Ȼfor ������ for (���ܶ���һ��ֵ�����Զ��Ӽ�)
//3.8
    string str1 = "0123456 89";
    string::size_type i = 0;
    for (decltype(str1.size()) i=0 ; i < str1.size(); ++i )
        str1[i] = 'X';
    cout << str1 << endl;
    return 0;

//3.7
//û�ı�

//3.6
    string str1 = "0123456 89";
    int i = 0;
    for (auto c : str1)
        str1[i] = 'X',  ++i;
    cout << str1 << endl;

 //3.5
    string a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    cout << a1+a2+a3 << endl;

    string a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    cout << a1+" "+a2+" "+a3 << endl;
    return 0;

//3.4
    string a1, a2;
    cin >> a1 >> a2;
    if (a1 == a2)
        cout << "ture" << endl;
    if (a1 > a2)
        cout << a1 << endl;
    if (a2 > a1)
        cout << a2 << endl;
    return 0;

//3.3
string��cin�����հ��ַ����Զ�ת���ɽ���Ȼ���֮ǰ���ַ���ƴ�յ�һ�������󱣴� Ȼ��֮����ַ���ƴ�ճ�һ���µĶ���
getline���ÿ��'/n'�����ݵ���һ�����������

//3.2
    string a1;
    while (getline(cin, a1))
        cout << a1 << endl;
    return 0;

    string a1;
    while (cin >> a1)
        cout << a1 << endl;
    return 0;

//3.1
#include <iostream>
using namespace std;
int main()
{
    int o = 0;
    for (int i = 50; i <=100; ++i)
        o += i;
    cout << o << endl;
    return 0;
}


#include <iostream>
using namespace std;
int main()
{
    for (int i = 10; i >=0; --i){
        cout << i << endl;
    }
    return 0;
}


#include <iostream>
using namespace std;
int main()
{
    int i,o;
    cin >> i >> o;
    cout << i+o << endl;
    return 0;
}

#include <iostream>
#include "Sales_data.h"
using namespace std;
int main()
{
    Sales_data book1, book2;
    cin >> book1.bookNo >> book1.revenue >> book1.units_sold;
    cin >> book2.bookNo >> book2.revenue >> book2.units_sold;
    if (book1.bookNo == book2.bookNo)
        cout << book1.revenue * book1.units_sold + book2.revenue * book2.units_sold << endl;
    return 0;
}
*/
