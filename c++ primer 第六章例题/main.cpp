#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //����������ĸ�����жϺ���   ����isalnum()�����ж����ֻ��Ǳ���ַ�����
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����


using namespace std;    //���������ռ䶼���ص�Ĭ�Ϲؼ����� ��������������ر��Ƽ�



int main()
{


}

/*
    //6.20
    //ʵ���� ֱ�ӵ�ֵ�Ͳ����޸ĵ�ֵ,
    //�����޸�Ϊ��ͨ����һ��������Ϊʵ���� ʵ��ֵ �ͳ���ֵ���ᱨ��.


    //6.19
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

calc(23.4, 55.1) //���� ��ʵ��ֻҪһ���������Ҳ���ʹֱ�ӵ���ֵ
double is = 23.4;
calc(is);

count("abcde",'a');  //��ȷ

calc(66);   //���� ��ʵ��ֻҪһ���������Ҳ���ʹֱ�ӵ���ֵ
double is = 66.0;
calc(is);

sum(vec.begin(), vec.end(), 3.8)  //�����в��Ϸ� ��Ϊ�β���int ��ʵ����3.8 �ɸ�Ϊ3��4



    //6.18
    bool compare (int &a, int &b)
{
    if (a != b)
        return false;
    else
        return true;
}

(b)
vector<int> chang_val (int i, vector<int> ils)
{
    int ls =0;
    for (int o =0; o != i; ++o){
        ils.push_back(ls)
        ++ls;
    }
    return ils;
}


    //6.17
    bool s_A (const string &s)
{
    for (decltype(s.size()) ls = 0; ls != s.size(); ++ls )
        if (isupper(s[ls]))
            return true;
    return false;
}
string s_a (string s)
{
    for (decltype(s.size()) ls = 0; ls != s.size(); ++ls )
        s[ls] = tolower(s[ls]);
    return s;
}

int main()
{

    if (s_A("ABCDefg"))
        cout << s_a("ABCDefg") <<endl;
}
    //����ͬ��Ϊ һ����Ҫ�޸� һ����Ҫ�޸�ֻ���ж�



    //6.16
bool is_empt(const string &s) {   //ֻ�ܽ���string���ͱ�������
    return s.empty();
}

    //6.15
    ��Ϊ�����ַ����ִ��� �϶���Ҫһ��string �� Ҫ�����ַ�  ���ڳ��ִ���Ҳ��Ҫͳ�Ƶĵ��� ʵ��������������
    �����ҵ��ַ����ǲ��ܱ��޸ĵ�����ԭֵ�����ǳ������������û��Ǹ�ֵ����,����ʡ�ڴ� ����occursΪʲô����ͨ������Ϊ���ǻ�䶯��ֵ.
    ����Ϊʲôc����������Ϊûɶ��Ҫ. ����С�ַ��������øо��������������.
    sΪ��ͨ�������������û�иı䵫�Է���һ
    occurs�ǳ��������; ��Ϊ++occurs����;
    Ŷ �������ñ���Ҫ�и�����,�����֮ǰ�����ø���

    //6.14
    �������һЩ���� ÿ����mb���ַ��� ��������û��ռ�ڴ�
    �������õĵط���һЩ�Ƚ���Ҫ�ı��� �����û������Ϊ���� ��������Ķ���ԭ����鷳.


    //6.13
    void f(T)   //�ǰ�ʵ�����ݸ�ֵ��t    һ�����غ�ֵ��T���Զ�ɾ��ʵ��û�޸�
    void f(&T)  //�ǰ�ʵ�εı��дΪT    һ������ʱ���ж�T���޸ĵ��ڶ�ʵ�ε��޸�

    //6.12
void f(int &ipa,int &ipb)
{
    int i;
    i = ipa;
    ipa = ipb;
    ipb = i;
}

int main()
{
    int i = 40, p = 50;
    f(i, p);
    cout << i << p <<endl;
}
//���ñ�ָ��� ��Ϊָ�뻹��Ҫ����һ�ε�ַ�� ����ԭֵ��ĳЩ�ط���̫�������Ҫ��Ҫд����.

    //6.11
    int rese(int &j)
{
    j = 40;
}

int main()
{
    int i = 50;
    rese(i);
    cout << i <<endl;
}



    //6.10
    void f(int *ipa,int *ipb)
{
    int i;
    i = *ipa;
    *ipa = *ipb;
    *ipb = i;
}

int main()
{
    int i = 40, p = 50;
    f(&i, &p);
    cout << i << p <<endl;
}


    //6.9      6.1.2��6.1.3��ȴ��˵�
    fact.cc���� #include "Chapter6.h"
    factMain.cc ���ڵ����ļ� fact���ڸ�������ֵ���� ��Chapter6.h���ڱ�д�ĺ������û��ֵ


    //main �������ļ�ֻҪ����һ�� ����fact()���ܵõ�������������ֵ��

    //fact.cc �ļ�����
    #include "Chapter6.h"

    using namespace std;    //���������ռ䶼���ص�Ĭ�Ϲؼ����� ��������������ر��Ƽ�

    int fact()
    {
        f();
        f2(2);
        calc(1,2)
        return --s;
    }


    //6.8
    �ɴ���д��һ��Chapter6.h�ļ���
    �������������
    #ifndef _Chapter6_h
    #define _Chapter6_h

    string f()  //�������ʹ���
    {
        string s;
        //...
        return s;
    }

    int f2(int i) {//....}  //����д��������

    int calc (int v1, int v2) {//...}   //���β�һ��

    double square (double x){ return x*x;}  //���Ǽ�����
    #endif



    //6.7
int fact()
{
    static int s=1;
    if (s != 1 )
        return 1;
    return --s;

}

int main()
{
    for (size_t i = 0; i != 10; ++i)
        cout << fact() <<endl;
}

    //6.6
    //�β��� ���ú���ʱ��Ĭ�Ϻ�������Ҫ��ֵ�Ķ���
    //�ֲ������Ƕ��庯��ʱ���еĶ�����
    //�ֲ���̬������ͷʹ�ؼ�����ĳЩ���� �ڵ�����ɺ�ɾ��������.
    int f(int i)
    {
        static int s=0;
        return s*i;
    }
    //int i���β�  Ҳ�Ǿֲ�����, static int s �Ǿֲ���̬����

    //6.5
int fact(int i)
{
    return -i;
}

int main()
{
    int ii;
    cin >> ii;
    cout << fact(ii) <<endl;
}



    //6.4
int fact(int i)
{
    int o = 1;
    while (i>1){
        o *= i;
        i--;
    }
    return o;
}

int main()
{
    int ii;
    cin >> ii;
    cout << fact(ii) <<endl;
}



    //6.3
    int fact(int i)
{
    int o = 1;
    while (i>1){
        o *= i;
        i--;
    }
    return o;
}

int main()
{
    cout << fact(5) <<endl;
}


    //6.2
string f()  //�������ʹ���
    {
        string s;
        //...
        return s;
    }

int f2(int i) {//....}  //����д��������

int calc (int v1, int v2) {//...}   //���β�һ��

double square (double x){ return x*x;}  //���Ǽ�����

    //6.1
    //ʵ�� �� �β�����ܴ�. ʵ����Ҫ��ֵ���βεĶ��� һ����ʵ��һ��ֻ������
*/
