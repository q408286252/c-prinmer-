#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //����������ĸ�����жϺ���   ����isalnum()�����ж����ֻ��Ǳ���ַ�����
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����

using namespace std;    //���������ռ䶼���ص�Ĭ�Ϲؼ����� ��������������ر��Ƽ�

int main()
{
    //5.22
    int itema = 0;
    if (itema == 0)
        throw runtime_error("���ܴ�������");
}


/*
    //5.22
    for (int sz = get_size(); !sz.empty();){
        if (sz <= 0)
            continue;
        ;// ....
    }

    //5.21
    string s, s_n;
    while (cin >> s)
        if (!isupper(s[0])) //���Ǵ�д��ĸ��
            continue;
        else{
            if (s != s_n){
                s_n = s;
            }else{
                break;
            }
        }

    //5.20
    string s, s_n;
    while (cin >> s)
        if (s != s_n)
            s_n = s;
        else
            break;

    //5.19
    string rsp ="0";
    do {
        cout << "�����������ַ��� ���ǻ������С���Ǹ�";
        string sa, sb;
        cin >> sa >> sb;
        if (sa > sb)
            cout << sa <<endl;
        else
            cout << sb <<endl;
        cout << "����n����ֹ�����������ݿɼ���" <<endl;
        cin >> rsp;
    } while (rsp != "n");

    //5.18
    do{ //�ټ���{}
        int v1, v2;
        cout << "please";
        if (cin >> v1 >> v2)
            cout << "sum:" << v1+v2 << endl;
    }while (cin);

    do {
        // ...
    }while ( ��д���ж� ); //while���涨��������.

    do{
        int ival = get_resonse();
        cin >> ival;
    } while (ival); //����ȷ �ж������޷����� ���true��һֱѭ����ȥ


    //5.17
    vector<int> ls = {1,2,3,4,5,6};
    vector<int> lsb = {1,2,3,4,5,6,7,8};
    std :: vector <int> :: size_type shu = 0;
    if ( ls.size() > lsb.size() ){
        for (auto ib = lsb.begin(), ia = ls.begin(); *ia == *ib && ib != lsb.end(); ++ia, ++ib, ++shu )
            ;
        if (shu == lsb.size())
            cout << "lsb������ls" <<endl;
    } else {
        for (auto ib = lsb.begin(), ia = ls.begin(); *ia == *ib && ia != ls.end(); ++ia, ++ib, ++shu )
            ;
        if (shu == ls.size())
            cout << "ls������lsb" <<endl;
    }

    //5.16
    //ƫ��ʹ��forѭ�� ��Ϊ���ɿ�.

    //5.15
    // ix��ֵΪ0, ix ������szʱ ����ѭ�� , ÿѭ��һ��ix+1
    for (int ix = 0; ix != sz; ++ix) {}
    //�����ifʽ�Ӻ�����ѭ���Ѿ��ظ��˿���ȥ��

    int ix;
    //ix������sz������, ÿ����һ��ix+1
    for (;ix != sz; ++ix) {}

    //++ix, ++sz ����Զѭ�� �����
    for (int ix =0; ix != sz; ++ix, --sz) {}

    //5.14
    int i = 1, i_m =0;
    string s, s_n, s_m;
    while (cin >> s){
        if (s_n == s){
            ++i;
            if ( i >= i_m ){
                i_m =i;
                s_m = s;
            }
        } else{
            s_n = s;
            i = 1;
        }
    }
    cout << s_m << "   " << i_m << endl;

    //5.13
    a : ÿ�е�case ûдbreak;
    b : ��case ������һ��ix��int����ȴ�� default��ʹ�� ���ǲ���ȷ����Ϊ �������ݲ�����ͬʱ����
    c : ƥ��ʱû�� ,�ŵ�д�� Ҫƥ�伸����Ҫд���� case
    d : case ƥ��ı����ǳ��������Ǳ���.

    //5.12
    char c;
    int f=0,ff=0,fl=0,fi=0;
    while (cin >> c){
        switch(c){
                case 'f':
                    if (f ==0)
                        ++f;
                    else{
                        ++ff;
                        --f;
                    }
                    break;
            if( f ==1 )
                --f;
                case 'i':
                    ++fi;
                    break;
                case 'l':
                    ++fl;
                    break;
                }
        }
    cout << "ff��" <<ff << "\nfl��" << fl << "\nfi��" << fi << endl;

    //5.11
    char c;
    int a=0,e=0,i=0,o=0,u=0,t=0,space=0,n=0;
    while (cin >> c){
        switch(c){
            case 'a': case 'A':
                ++a;
                break;
            case 'e': case 'E':
                ++e;
                break;
            case 'i': case 'I':
                ++i;
                break;
            case 'o': case 'O':
                ++o;
                break;
            case 'u': case 'U':
                ++u;
                break;
            case '\t':
                ++t;
                break;
            case '\0':
                ++space;
                break;
            case '\n':
                ++n;
                break;
        }
    }
    cout << "a��" <<a << "\ne��" << e << "\ni��" << i << "\no��" << o << "\nu��" << u << "\n�ո���" <<space << "\ntab��" <<t << "\n������" << n << endl;//ò��tab \n ' 'ͳ�Ʋ������ȷ���.

    //5.10
    char c;
    int a=0,e=0,i=0,o=0,u=0;
    while (cin >> c){
        switch(c){
            case 'a': case 'A':
                ++a;
                break;
            case 'e': case 'E':
                ++e;
                break;
            case 'i': case 'I':
                ++i;
                break;
            case 'o': case 'O':
                ++o;
                break;
            case 'u': case 'U':
                ++u;
                break;
        }
    }
    cout << "a��" <<a << "\ne��" << e << "\ni��" << i << "\no��" << o << "\nu��" << u << endl;

    //5.9
    char c;
    int a=0,e=0,i=0,o=0,u=0;
    while (cin >> c){
        switch(c){
            case 'a':
                ++a;
                break;
            case 'e':
                ++e;
                break;
            case 'i':
                ++i;
                break;
            case 'o':
                ++o;
                break;
            case 'u':
                ++u;
                break;
        }
    }
    cout << "a��" <<a << "\ne��" << e << "\ni��" << i << "\no��" << o << "\nu��" << u << endl;

    //5.8
    //����else ��if����Ƕ��if ��else�����
    //��δ���Ҫ�����ı��ʽ�Ƿ���{} ������������

    //5.7
    int ival, ival2,minval,cccurs;
    if (ival != ival2)
        ival = ival2;
    else
        ival = ival2 =0;

    if (ival < minval){
        minval = ival;
        cccurs = 1;
    }

    if (int ival = get_value(); ival )
        cout << "ival = " << ival << endl;
    else
        cout << "ival = 0\n";

    if (ival ==0 )
        ival = get_value();

    //5.6
    int grade = 0;
    string p = "";
    cin >> grade;
    (grade < 60) ?
        p += "C" :
        (grade > 70) ?
            p += "A" :
            p += "B";
    cout << p << endl;
    return 0;

    //5.5
    int grade = 0;
    string p = "";
    cin >> grade;
    if (grade < 60){
        p += "C";
    }else{
        if (grade > 70){
            p += "A";
        }else{
            p += "B";
        }
    }
    cout << p << endl;
    return 0;

    //5.4
    int s[5]
    while (string::iterator oter != s.end() )
        {}
    //��������
    while (auto oter = s.begin(); oter != s.end())

    while (bool status = find(word)) {}
    if (!status) {}
    // ����word ����з���1 ִ��whileѭ��  ����0ִ��if����

    //5.3
    int sum = 0;
    for (int  val = 1; val <= 10; ++val)
        sum += val;
    cout  << sum << endl;

    //5.2
    //�����{}  ��for ��while��������� ���ѭ������Ҫд2�����ϱ��ʽ��Ҫ�õ�

    //5.1
    //��������û����Ҫ���е����ݵĶ���
    //��Щ�ط����ݻ�û�����ôд��ʱ������ÿ�������

*/
