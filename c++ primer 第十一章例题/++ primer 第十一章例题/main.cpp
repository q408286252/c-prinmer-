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
#include <map>  //��Ӧֵ����
#include <set>  //�ؼ�������
#include <unordered_map>    //�����Ӧֵ����
#include <unordered_set>    //����ؼ�������
#include <cxxabi.h>         //��typeid(������).name() ʱ�õ��İ���gcc��ʾ��������
#include <utility>          //ʹ��pairһ�Ա�������

#include "Sales_data.h"
//#include "Sales_item.h"

using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() < rhs.isbn();
}
pair<string, int>  process(vector<string> &v){
    if(!v.empty())  //vΪ����
        //return {v.back(),v.back().size()};
        return pair<string,int>(v.back(),v.back().size());
    else
        return pair<string,int>();  //�շ���
}

int main()
{
    int a = 4;
    const int *x = &a, shit = 5;
    int const xa = 4, shit2 = 6;
    shit2 = 5;
}


/*
//11.23
    multimap<string, string> family;
    vector<string> vec;
    string  surname,name;
    cout << "����������Ҫ������һ����������y" << endl;
    i:
    while(cin >> surname){
        while(cin>> name){
            if (name == "y"|| name == "Y")
                goto i;
            family.insert({surname,name});
        }
    }
    for (auto &i : family)
        cout << "����Ϊ:" << i.first << i.second  << endl;



//11.22
    map<string, vector<int>> word_count;
    pair<string,vector<int>> paira = {"s",{1}};
    pair<map<string,vector<int>>::iterator, bool> set = word_count.insert(paira);



//11.21
    Ĭ����� word���ַ� ��0����ֵ ���ǵķ���pair�ҵ���һ��Աfirst ���������ĵڶ���Աseond����;



//11.20
    map<string, size_t> word_count;
    string s;
    while(cin >> s){
        auto ret = word_count.insert({s,1});
        if (!ret.second)    //pair��bool != 0
			++ret.first->second;
    }
    for (auto &i : word_count)
        cout << "����" << i.first << "�Ĵ���Ϊ:" << i.second << endl;
    //��������� �ر��һֵ��������� �ڶ�Ԫ�� �е�����


//11.19
    using f = bool(Sales_data const&, Sales_data const&);
    multiset<Sales_data,f* > bookstore(compareIsbn);
    multiset<Sales_data,f*>::iterator i = bookstore.begin();



//11.18
    map<string,string> mapa = { {"1","11"},{"2","22"} };\
    for (map<string,string>::iterator it = mapa.begin(); it != mapa.end();++it)
        cout << it->first << " " << it->second << endl;



//11.17
    copy(v.begin(), v.end(), inserter(c,c.end()));//v��ȫ��Ԫ�ز��뵽 c����c.end()��ʼλ�� cʱset���ϻ��Զ�����
    copy(v.begin(), v.end(), back_inserter(c));//���Ϸ� ��Ϊc��set���ϲ�֧��push_back;
    copy(c.begin(), c.end(), inserter(v,v.end()));//��cԪ�ذ�˳�� ���뵽v�Ķ�β
    copy(c.begin(), c.end(), back_inserter(v));//������һ��



//11.16
    map<int, vector<int>> mapa ={ {1,{1,2,3}},{2,{1,2,3} } };
    auto map_iter = mapa.begin();
    int i = map_iter->second[2];
    cout << i <<endl;



//11.15
    key_type �� value_type ʱһ����˼���ǹؼ�������
    mapped_tyep Ϊ�ؼ��ֹ���ֵ ������



//11.14
        map<string, vector<pair<string,string>>> mapa= {
            {"yang",    {  {"rui","09-11"},{"niu","09-12"}  }     }
            };



//11.13
        vec.push_back({*in++,*ini++});
        vec.push_back(pair<string,int>(*in++,*ini++));
        vec.push_back(make_pair(*in++,*ini++));




//11.12
    ifstream input("data1.txt");	//��ȡ�ļ���
    ifstream inputb("data2.txt");
	istream_iterator<string> in(input), en; //in�Ͷ�ȡ�ļ�����
	istream_iterator<int>ini(inputb),eni;
    vector<pair<string,int>> vec;
	while(in != en && ini != eni)
        vec.push_back({*in++,*ini++});
    for (auto i : vec)
        cout<< i.first << i.second << endl;



//11.11
    using f = bool(Sales_data const&, Sales_data const&);
    multiset<Sales_data,f* > bookstore(compareIsbn);
    //��дbool(Sales_data const&, Sales_data const&)* �����- -ֻ�ò�����


//11.10
    map<vector<int>::iterator,int> mapa;
    map<list<int>::iterator,int> mapa;
    //��������

//11.9
    map<string,list<int>> mapa;



//11.8
    vector<int> vec = {0,1,2,3,4,5,6,1,2,3};
    sort(vec.begin(),vec.end());
    auto iter = unique(vec.begin(),vec.end());
    vec.erase(iter, vec.end());
    for (auto i : vec)
        cout << i << endl;
    //�ŵ������ ������Ҫд4������ ��setһ�о��� ����vector��Ԫ�������������.ɾ���ظ����ǳ���.


//11.7      //������ûд��ô��� ����ֵ�������ֵ�map����.... ��Ҫ��д���Ԫ��... ������������дpush_back().....��������д���.
    map<string, vector<string>> demo= {{"yang",{"rui","niu"} },{"yu",{"rui","niu"} } };
    demo.insert({"nana",{"ni","hao"}});


//11.6
    set��list����̫���� ��һlist��������ʽ��ÿԪ����˳������,�ұ��,���ظ�
    ��set �����ظ�,����������ʽ��.


//11.5
    //����� map�ںܶ���Ҫ���Һܶ���Ϣʱ��ʹ�÷ǳ��� ��set����Ψһ���ںܶ಻���ظ�����Ǻ��õ�.



//11.4
    map<string, size_t> word;
    string s;
    while(cin >> s){
        s[0] = tolower(s[0]);
        for (size_t i =0; i <= s.size(); ++i){  //������д!= Ȼ��������û�ҳ���.....
            if(s[i] == '.' || s[i] == ',')
                s = s.erase(i,1);
        }
        ++word[s];
    }
    for (auto &i : word)
        cout << "����" << i.first << "�Ĵ���Ϊ:" << i.second << endl;



//11.3
map<string, size_t> word;
    string s;
    while(cin >> s)
        ++word[s];
    for (auto &i : word)
        cout << "����" << i.first << "�Ĵ���Ϊ:" << i.second << endl;



//11.2
    list    ��ʱ�齨��ģС����֯�������ɾ��
    vector  һЩ��¼; ��¼��Զ���沢��˳��̶�
    deque   �Ŷ�����ֻ��β��Ӻ� ��ɾ��
    map     ��¼ĳЩ�������ִ�����, ���֤������; ÿ����Ա��¼��;
    set     ������Զ���ظ��Ķ��������֤



//11.1
    ��ͬ���� map��ͬʱ������������ֵ; ��vectorֻ�ܱ���һ��
    vector��˳�򱣴� ��map����˳���������;
    vector��Ԫ��ֵ������ͬ��ͬ, ��map��������ֻ�ܲ�ͬ;


*/
