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
#include <ctime>            //c�ĳ����ʱ���
#include <memory>           //����ָ��

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
//����ת�������ļ����� ת�������ֵ�.
map<string,string> buildMap(ifstream &map_file){
    map<string,string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file,value)){
        if (value.size() > 1)
            //��һ������Ϊ�ؼ���; �ڶ������ո����ֵ
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for" + key);
    }
    return trans_map;
}
//ƥ�亯��
const string & transform(const string &s, const map<string,string> &m){
    //ת������
    auto map_it = m.find(s);
    //���map_itָ�벻����ĩβ;�������
    if (map_it != m.cend())
        return map_it->second;  //�������ֵ;
    else
        return s;
}
//���ļ����� ת���ַ������
void word_transform(ifstream &map_file, ifstream &input){
    map<string,string> trans_map = buildMap(map_file);  //����ת���ֵ�.
    string text;
    while (getline(input,text)){    //����һ��һ�з���text;
        istringstream stream(text); //Ȼ���text������;
        string word;
        bool firstword = true;
        while (stream >> word){ //text ����word;
            if (firstword)  //�治��ӡ�ո�
                firstword = false;
            else
                cout << " ";
                //transform��wordƥ���ֵ�ת�����;
            cout << transform(word, trans_map);

        }
        cout << endl;
    }
}
map<string,string> shengchengzidian (ifstream &s){
    map<string,string> m;
    string key, value;
    while(s>>key && getline(s,value)){
        if (value.size() >1)
            m[key] = value.substr(1);
        else
            throw runtime_error("������!");
    }
}
string zhuanhuan (string &s, map<string,string> &m){
    auto iter = m.find(s);
    if (iter != m.end())
        return iter->second;
    else
        return s;
}
void string_string (ifstream &s, ifstream &input){
    map<string,string> m = shengchengzidian(s);
    string text;
    while (getline(input, text)){
        istringstream stream(text);
        string word;
        while (stream >> word){
            cout << zhuanhuan(word, m);
        }
    }
}


int main()
{
    int i=0;
    cout << i ;
}
/*
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    cout << vec[method(vec,4)] << endl;
    //method()




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
//11.38
    ��

//11.37
    ����ʱ����Ӿ��Ȼ�;
    ��������Ĳ�ѯ�и���, �ӳ���1~999ms�ķ��������Χ��.û��ϲ������999ms
    ��˳�������ظ�����ĩβ�ؼ��־ʹ�����������.

//11.36
    ĳһ�о�һ��char �ᵼ�³����׳�����;

//11.35
    һ����Ч��


//11.34
    ��д��������.
    ��������ڹ����������� ����¹ؼ��� ֵΪ�յ�ֵ;
    �����ù���ֵ�Ƿ�Ϊ���ж����������������ؼ��ֻ�Խ��Խ��;����ӷ��.


//11.33
map<string,string> shengchengzidian (ifstream &s){
    map<string,string> m;
    string key, value;
    while(s>>key && getline(s,value)){
        if (value.size() >1)
            m[key] = value.substr(1);
        else
            throw runtime_error("������!");
    }
}
string zhuanhuan (string &s, map<string,string> &m){
    auto iter = m.find(s);
    if (iter != m.end())
        return iter->second;
    else
        return s;
}
void string_string (ifstream &s, ifstream &input){
    map<string,string> m = shengchengzidian(s);
    string text;
    while (getline(input, text)){
        istringstream stream(text);
        string word;
        while (stream >> word){
            cout << zhuanhuan(word, m);
        }
    }
}

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
    //pos ��pair;
    //pos.first ����pair�ĵ�һ��Ԫ��Ҳ�����ҵ���һ�����ڵ���search_itemֵ�ĵ�����;
    //pos.first->second �ǵ���������Ȼ���ҵڶ�Ԫ�� Ҳ���ǹ���ֵ������



//11.29
    upper_bound ָ����ڹؼ��ֵĵ�����; û����end();
    lower_bound ָ����ڹؼ��ֵĵ�����; û����end();
    equal_range ��pair ��Ԫ�طֱ�ָ�� ָ����ͬ���ڹؼ��ֵĵ�����; û����end();


//11.28
    map<string,vector<int> > mapa = { {"a",{0,1,2,3}}, {"c",{4,5,6,7}} };
    pair<string, vector<int>> paira = {"",{0} };
    paira = *mapa.find("a");



//11.27
    count ������� �ظ�map ��setʱʹ��
    find�ڲ��ظ��� map��setʱ��ʹ��,



//11.26
    //�����ù���ֵ������ͬ��ֵ���в���;
    //�±귵������Ϊ �±�ؼ��ֵĹ���ֵ ����ֵ������map����;
    map<string,int> mapa;
    mapa["a"] = 1;
    mapa["a"] += 5;
    cout << mapa["a"] <<endl;



//11.25
    vector<int> v;
    v[0] = 1;   //��������δ����;
    //���Կ���vector ��map���ܴ�


//11.24
    map<int,int> m;
    m[0] = 1;   //��ӹؼ���0 �����ֵ��ʼ������ֵ1



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
