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


    //6.48
    string s;
    while (cin >> s && s != sought) {
    }
    assert(cin);
    //������.  ΪʲôҪ���벻���� sought��ѭ����һ����?
    // ����assert(cin);�жϵ���cin ��дcin�ֲ������붫�������ж�!


    //6.47
// #define NDEBUG  д�˾��ǹز�д���ǿ�
string print(vector<string> stra,int i )
{
    if (i != stra.size())
        return  stra[i] + print(stra, i+1);
    #ifndef NDEBUG
        cout << stra.size() <<endl;
    #endif // NDEBUG
    return " ";
}



int main()
{
    vector<string> s = {"a","b","c","d"};
    cout<<  print(s,0) << endl;
}



    //6.46
    constexpr string &shorterString(const string &s1, const string &s2)
    {
        return s1.size() <= s2.size() ? s1 : s2;
    }
    //���Ǵ������Ϊ�����β������ö����ñ���Ҫ�и���ʼ���� ��constexpr����ʵ�����ַ�ֵ ����ì��.

    //6.45
    �Ƿ��д��������������Ҫ�����ص������Ƿ�����һ��д�������.
    6.42��,6.38��6.32�� 6.33������Ϊ������������Ҫ�ж�.


    //6.44
    inline bool isShorter(const string &s1, const string &s2)
    {
        return s1.size() < s2.size()
    }


    //6.43
    ��a�����Ž�ͷ�ļ� ��Ϊinline Ϊ������������˺����ṹ��,ʹ�ô�����,


    //6.42
string make_plural(size_t, const string &word, const string &ending="es");
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    string sa = "success", sb = "failure";
    cout<< make_plural(2,sa) << "\n" << make_plural(0,sb) << endl;
}
//string �������'s'? ������д����.


    //6.41
char *intit(int ht, int wd = 80, char bckgrnd = ' ');
init();  //Υ����Ϊ htֵû����
init(24,10); //����
inti(14,'*') ;   //�������ͳ��Բ���.


    //6.40
int ff(int a, int b =0, int c=0); //���ﲻ֪����ʼ�������β��Ƿ�������Ĭ�Ϻ���, ����������β�û������ô����ȷ��.
char *init(int ht = 24, int wd, char bckgrnd); //���������һ���β�û����Ĭ��ֵ��ô����ȷ��,


    //6.39
    int calc(int, int);
    int calc(const int, const int); //���ʵ���ǳ������ȵ��ô˺���

    int getc();
    double get();   //����

    int *reset(int *);
    double *reset(double *);    //���ʵ�������Ǹ��������ȵ�����


    //6.38
string s[] = {"a","b","c","d","d","d","d","d","d","d"};
decltype(s) (*print(int i))
{
    return &s;
}
int main()
{
    cout<<  (* print(5))[9] << endl;
}


    //6.37
    typedef int arr;
    arr  (*print (int i))[10];

    auto print(int i) -> string(*)[10];

    string s[] = {"a","b","c","d","d","d","d","d","d","d"};
    decltype(s) (*print(int i))


    //6.36
    string (*print(int i))[10];

    //6.35
    �����������ѭ���µľֲ����� �ݼ�ֻ����һ��.
    ����. val-- �Ǵ�����ټ�ֵ���´����ֵһֱû���������ѭ��

    //6.34
    ���������Ǹ�����������ѭ��, ����ҲҪѭ������ֵ���Ȼ����´����ֵ��0,,Ҫ�ܾ�.
    ���������Ǵ��ڵ���0������ ���֮ǰ�ĺ���������һ��ѭ��.

    //6.33
string print(vector<string> stra,int i )
{
    if (i != stra.size())
        return  stra[i] + print(stra, i+1);
    return "";
}

int main()
{
    vector<string> s = {"a","b","c","d"};
    cout<<  print(s,0) << endl;
}


    //6.32
int &get(int *arry, int index)  //����int ָ�� ��int ��ֵ
{
    return arry[index]; //����ָ��+�±�
}

int main()
{
    int ia[10];
    for (int i=0; i != 10; ++i)
        get(ia, i) = 1;
        //get(ia,i) ��˼Ϊ����һ��ia��һ��Ԫ��ָ���arry, i��������index ���� & arry[index] =  ia[i]
}


    //6.31
    //���ص�������Ч �����õľֲ�����������ʱ��,�������Ͳ���

    //6.30
bool str_subrange(const string &sa, const string &sb)
{
    if (sa.size() == sb.size())
        return 1;
    auto size = (sa.size() < sb.size()) ? sa.size() : sb.size();
    for (decltype(size) i = 0; i != size; ++i)
        if (sa[i] != sb[i])
            return;     //���ᴦ��ᱨ�� Ӧ�÷��� return 0;
}

int main()
{
    string s = "lala", ss = "lala";
    cout<< str_subrange(s,ss)<<endl;
}

    //6.29
    initializer_list�ǳ���Ԫ��,ѭ�����Ʊ������ó����� ��ô����һ����������޸ĵ���?

    //6.28
    elem ��const string  ָ������.

    //6.27
    int print(initializer_list<int> il)
{
    int i=0;
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        i += *beg;
    return i;
}

int main()
{
    cout << print({10,20,33,450,60}) << endl;
}




    //6.26
windows ��cmd Ȼ���ҵ�����ļ� main.cpp Ȼ���ն�����:
    g++ -o main.exe main.cpp
    ֮������
    main -d -o ofile data0  ɶ�Ķ���. ֻҪmain��ͷ����.
int main(int argc, char* *argv)
{
    for (int ii = 0; ii != argc; ++ii){
        if (argv[ii])
            while (*(argv[ii]))
                cout<<*( (argv[ii])++);
        cout << endl;
    }
}

    //6.25
    //6.2.5����е��..
    int main(string stra, string strb)
{
    stra += strb;
    cout << stra << endl;
}


    //6.24
int print(const int ia[10])
//���˱�����ֱ�Ӱ����鴫��һ������û�� �⵫ const int i[10] = j; ����ʾ���� em....
{
    for (size_t i=0; i != 10; ++i)  //����һ��iΪ��������ʼΪ0,ÿ��ѭ����+1
        cout <<ia[i] << endl;   //ÿ��ѭ�����ia��һ��Ԫ��
}

int main()
{
    int j[10] = {0,1,2,3,4,5,6,7,8,9};
    print(j);
}


    //6.23
//�̶�����д��
int print(int ia, int (&ib)[2])
{
    cout << ia << ib[0] << ib[1] << endl;
}


int main()
{
    int i=0, j[2] = {0,1};
    print(i,j);
    //cout <<  << endl;
}
//������������д��
int print(int ia, int ib[], size_t size)
{
    cout << ia << "\n" ;
    for (size_t i =0; i != size; ++i)
        cout << ib[i] << endl;
}
int main()
{
    int i=0, j[2] = {0,1};
    size_t t = 2;
    print(i,j,t);
}
//������λָ��д��
int print(int ia, int *beg, int *en)
{
    cout << ia << "\n" ;
    while (beg != en)
        cout << *beg++ << endl;
}


int main()
{
    int i=0, j[2] = {0,1};
    print(i,j,end(j));
}



    //6.22
int print( int* &ipa, int* &ipb)
{
    int *ipc;
    ipc = ipa;
    ipa = ipb;
    ipb = ipc;
}


int main()
{
    int ia =2, ib = 3;
    int *ipaa = &ia, *ipbb = &ib;
    print(ipaa,ipbb);
    cout << *ipaa << *ipbb << endl;
}



    //6.21
    int print(const int i, const int *ip)
{
    if (i > *ip)
        return i;
    else
        return *ip;
}


int main()
{
    int ia =2, ib = 3;
    int ic = print(ia,&ib);
    cout << ic << endl;
    //ָ��������const int *����
}


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
