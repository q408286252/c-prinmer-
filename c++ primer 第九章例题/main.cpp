#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //�����ַ��ж�(�Ƿ��Ƿ��� ���� ��� ��ĸ�� ʲô��.)�����Ŀ�
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����
#include <fstream>  //�ļ�IO
#include <sstream>  //strIO
#include <list>     // ��������
#include <forward_list> //��������
#include <deque>    // ˫��vector
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
        if (i ==0 ){ //��һ��ѭ����ʼ��¼ʼ;
            posb = pos;
            ++i;
        } else if(posb + i == pos){ //����±�������;
            ++i;
            if (i > ii){    //������¼���� ��ʷ��¼�͸���:
                ii = i;
                posbegin = posb;
            }
        } else{ //һ�������� ��
            if (i > ii) {   //����ʷ��¼�Ա��������
                ii = i;   //��������������ֵ
                posbegin = posb;    //������ʼ�ն˱�������
                i = 1;
                posb = pos;
            } else{         //����ʷ��¼С��ˢ�³�ʼֵ;
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
    //9.49    ͦ��ʱ���..
    //�ҿ����������˵�csdnд����������д s.length() ����ûд�������ҵ��� Ц!!! ���˳�֮ǰ��д��. ����д������ʽ; ò�����ִ�if else�ĺ��ܱ��Ӱ�.
    string s = "ataaaatatattaataa";
    //cin >> s;
    int i=0,ii=0;
    string::size_type pos=0, posb, posbegin;
    while ( (pos = s.find_first_of("acemnorsuvwxz",pos)) != string::npos ){
        if (i ==0 ){ //��һ��ѭ����ʼ��¼ʼ;
            posb = pos;
            ++i;
        } else if(posb + i == pos){ //����±�������;
            ++i;
            if (i > ii){    //������¼���� ��ʷ��¼�͸���:
                ii = i;
                posbegin = posb;
            }
        } else{ //һ�������� ��
            if (i > ii) {   //����ʷ��¼�Ա��������
                ii = i;   //��������������ֵ
                posbegin = posb;    //������ʼ�ն˱�������
                i = 1;
                posb = pos;
            } else{         //����ʷ��¼С��ˢ�³�ʼֵ;
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
    numbers.find(name); //����string::npos��Ա ����Ϊconst string::size_type �޷�������;


    //9.47
    //��������find_first_not_of ���д....��ʶ�������е��.����д= = ��ú��������ܿ��ٽ��.
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
    //��ʵ֤���õ�����д�ܶ��� �������ܵ������ķ������±���ٶ���.
string &replacedef(string &s,const string &stra,const string &strb){
    for (auto i = s.begin(); i != s.end(); ++i){
        char s1[] = {*i,*(i+1),*(i+2),*(i+3)};
        string name(s1,4);
        //auto *ip = &*i;  �����п��Ի���
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
    //û����д���±���ʽ�����ø�.
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
    //�����ҵ��˰�������. �о����� �趨��ָ�������.........


    //9.40
    256Ԫ�غ���1024, 512Ҳ�� 1000����2000; 1048��ʱ��ʱ2048
    //���2000�ܺ���.�ǳ�ʼ����Ԫ����Ӳ���׼Ѱ2�����η�������?

    //9.39
        vector<string> svec;
    svec.reserve(1024); //���������õ�1024Ԫ�ص��ڴ�
    string word;
    while (cin >> word)
        svec.push_back(word);   //ÿ�������򱣴浽������;
    svec.resize(svec.size() + svec.size()/2);   //������ֹʱ��������Ԫ����1.5��



    //9.38
    0 - 1 - 2 -4 -8 -16 - 32-64-128


    //9.37
    array��Ϊ�ǹ̶�����������Ҫcapacity() ��Ϊ ������ڴ�Ԫ�ؿ϶���size()���
    ��list ��˫������; ���Ƿ�ɢ�ڴ�������һ�� ѹ����Ҫ���·���


    //9.36
    ������


    //9.35
    //capacity()���������·����ڴ�����Ԫ����  size()����������Ԫ����
    //���൱��һ���Ǹ�10��ֽ, һ����д��3��ֽ��������



    //9.34
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while (iter != vi.end()){
        if (*iter % 2)  //������:
            iter = vi.insert(iter,*iter);//������ǰ���Ԫ�� ���ƶ�ָ�뵽���Ԫ��λ��
        ++iter; //����ż����ѭ�� ��Ϊ ָ����ѭ����������Ԫ�� ����Ȼ������ ����һֱ������Ԫ��
    }
    for (auto &i : vi)
        cout << i;


    //9.33
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    auto begin = v.begin();
    while (begin != v.end()){
        ++begin;
        //����ᷢ�������ȷ� ���б��ʽ�ƶ���Ԫ��9 Ȼ�����ѭ�� �����ƶ���β�� β�����Ԫ�����Ǵ����
        v.insert(begin,42);
        ++begin;
    }
    for (auto &i : v)
        cout << i;


    //9.32
    *iter++ //˵ʵ������ǰ�沿���е㷳. ���Ҳ������׵���ǰ���޸���������ܷ����..
    //���Ϸ�. ��Ϊ���� *(iter++) �������ҽ�� ��������� iterҲ��Ⱦ
    //���ʽ���  �ѵ�ǰ��������������һ��λ�ÿ�ϧ�������һ����9��ô������һ����β�󲻴���=, =
    �������Ԫ�ر��10���ܹ���
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9,10};
    auto iter = vi.begin();
    while (iter != vi.end()){
        if (*iter % 2){ //������
            iter = vi.insert(iter,*iter++ ); //����λ��ǰһ��λ�� ��� ͬ��ֵ ���ƶ�������
            ++iter;  //�ƶ�����
            ++iter;
        }else{
            iter = vi.erase(iter);  //ż��ɾ����ǰԪ�� �����µ�����
        }
    }
    for (auto &i : vi)
        cout << i;


    //9.31
    ��Ϊlist�޷�һ�����ƶ�����λ��;
        list<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while (iter != vi.end()){
        if (*iter % 2){ //������
            iter = vi.insert(iter,*iter); //����λ��ǰһ��λ�� ��� ͬ��ֵ ���ƶ�������
            ++iter;  //�ƶ�����
            ++iter;
        }else{
            iter = vi.erase(iter);  //ż��ɾ����ǰԪ�� �����µ�����
        }
    }
    for (auto &i : vi)
        cout << i;

    //��forward_list���ӵĶ���Ҫ˫������ �� ���⺯��;
    forward_list<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin(), ipa  = vi.before_begin();
    while (iter != vi.end()){
        if (*iter % 2){ //������
            iter = vi.insert_after(ipa,*iter); //����λ��ǰһ��λ�� ��� ͬ��ֵ ���ƶ�������
            ++iter;  //�ƶ�����
            ipa = iter;
            ++iter;
        }else{
            iter = vi.erase_after(ipa);  //ż��ɾ����ǰԪ�� �����µ�����
        }
    }
    for (auto &i : vi)
        cout << i;



    //9.30
    ������ �����Ҫ��ʼ����ô���Ԫ�������г�ʼ����Ĭ��ֵ. ���û��Ĭ��ֵ������;


    //9.29
    ����vec��25��Ԫ�غ������75��Ԫ��Ĭ�ϳ�ʼ��;
    vec.resize(10) ���ɾ����ǰ10��Ԫ��������Ԫ��;


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
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89}; //array��֧�ֵ�����
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
    elem1 == elem2 ��ʲô��ûɾ��
    elem1��elem2����β�� Ҳ��ʲô��ûɾ��;
        vector<int> ints = {0,1,2,3};
    ints.erase(ints.begin(), ints.begin());
    cout << ints[0] << endl;




    //9.24
    vector<int> ints = {0,1,2,3};
    cout << ints.at(0) << " " << ints[0] << " " << ints.front() << " " << *ints.begin() << endl;
    ���������������ᱨ�� �ն˻�


    //9.23
    c������Ϊһ��:
    val ֵ�� Ԫ��ֵ;
    val2 ֵ�� Ԫ��ֵ;
    val3 ����last��δ֪����;
    val4 ֵ�� Ԫ��ֵ;

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
