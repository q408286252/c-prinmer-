#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //����������ĸ�����жϺ���   ����isalnum()�����ж����ֻ��Ǳ���ַ�����
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����

//#include "Sales_data.h" //���ر����������ļ�

using namespace std;    //���������ռ䶼���ص�Ĭ�Ϲؼ����� ��������������ر��Ƽ�

int main()
{
    return 0;
}


/*
    //4.38
    // j��i����ֵ ת���ɸ����� ���� slope������
    double slope = static_cast<double>(j/i);

    //4.37
    int i;
    double d;
    const string *ps;
    char *pc;
    void *pv;
    pv = static_cast<void*>( const_cast<string*>(ps) );
    i = reinterpret_cast<int>(pc);
    pv = static_cast<void*>(&d);
    pc = static_cast<char*>(pv);

    //4.36
    int i = 3;
    double d = 3.44;
    i *= static_cast<int>(d) ;
    cout << i <<endl;

    //4.35
    char cval;
    int ival;
    unsigned int ui;
    float fval;
    double dval;

    cval = 'a' + 3; // 'a'ת����int ��3����
    fval = ui - ival * 1.0; //ival ת����double Ȼ����1.0�������� ת�����޷���������
    dval = ui * fval;   // fval ת����int Ȼ��ת����unsigned int ��ui��������
    cval = ival + fval + dval;  //fvalת���� int ��ת����double int��ivalҲת����double

    //4.34
    if (fval)   //������ת��
    dval = fval + ival;     //  fval ��ת����int Ȼ������
    dval + ival * cval;     //  cvalת����int ��������ת����double ��dval����

    //4.33
    //someValue ���ж� ��Ϊ0������  x����1,y����1 Ϊ0������ x�ݼ�1 y�ݼ�1
    someValue ? ++x, ++y : --x, --y

    //4.32
    constexpr int size = 5;
    int ia[size] = {1,2,3,4,5};
    // ָ��ptrָ��ia[0],ixֵΪ0; ixֵ������sizeֵ �� ptr��ָԪ�ز����� ia��end();  ÿ�ٴ�ѭ�� ixֵ+1 ptrָ������һ��,
    for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size; ++ix, ++ptr)
    {   cout << 1 <<endl;
        }

    //4.31
    //ʹ�ú��ð汾��++ -- �Ǿͻ��һ��ѭ�� Ҫ����һѭ�������ȥ����鷳
    //���� ��Ҫѭ��6��  ��0 +6��1����ΪʲôҪ�� 1+5��1����6��?
    vector<int> ivec;
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 1; ix != ivec.size(); ix++, cnt-- ){
        ivec[ix] = cnt;
    }

    //4.30
    (sizeof x) + y
    sizeof ( (*p).mem[i] )
    (sizeof a ) < b
    sizeof ( f() )

    //4.29
    int x[10];
    int *p = x;
    cout  << sizeof(x) / sizeof (*x) << endl;
    // 40/4 ����10
    cout << sizeof(p) / sizeof(*p) <<endl;
    //  pָ��ռ4 / 40 ��0 ���� ����Ϊ1 ������  sizeof(*p)����Ϊ4  ԭ���Ƿ���ʱ��ֻ�ҵ�int����û�в鿴x.

    //4.28
    string s;
    int i, *p;
    long long ll;
    //......
    cout << sizeof i << ' ' << sizeof ll << ' ' << sizeof p
        << ' ' << sizeof s << endl;

    //4.27
    unsigned long ua = 3, ub = 7;
    ua & ub;    //11 �� 111 �� 29��0 111
    ua | ub;    //11 �� 111 �� 30��0 11
    ua && ub;   // true
    ua || ub    // true

    //4.26
    unsigned int qu = 0;
    qu |= 1UL << 27;
    bool bo = qu & (1UL << 27);
    cout << bo << endl;
    //�ᷢ��qu & (1UL << 27) ֵ��Ϊ0����� ����ԭ������������Ƕ�������д��ʽ��ͬ.

   //4.25
    'q' << 6 ���ص�ֵ ������Ϊ:00000000 00000000 00011100 01000000
    ʮ����Ϊ: 2^12 + 2^11 + 2^10 + 2^6 = 7232

    //4.24
    int grade = 55;
    //������Ͼͱ������  �Ķ�����������
    cout << ( (grade <60) ?
             ( (grade <=75) ?
              ( (grade <=90) ? "low pass" : "high pass" )
              : "pass" )
             : "fail" ) << endl;

    //4.23
    string s = "word";
    string p1 = ( s +s[s.size() - 1] == "s" ) ? "" : "s" ;
    //���� Ҫ������ Ȼ�� s��string �������жϵĲ�����'s'

    //4.22
    cout << ( (grade > 90) ?
             "high pass" : (grade > 75) ?
             "low pass" : (grade >= 60) ?
             "pass" : "fail" ) << endl;


    if (grade > 90){
        cout << "high pass";
    } else {
        if (grade > 75){
            cout << "low pass";
        } else{
            if (grade >= 60){
                cout << "pass";
            } else {
                cout << "fail";
            }
        }
    }
    cout << endl;
    //�ϻ��϶���һ���ð�. �ڶ���if else if else ����ͷ�����?

    //4.21
    vector<int> ints = {1,2,3,4,5,6};
    for (auto i = ints.begin(); i != ints.end(); ++i)
        (*i)%2 ? *i =*i * 2 : ' ';
    cout << ints[0] << endl;

    //4.20
    vector<string>::iterator iter;      //=. =����p137������Ҫ��97ҳ����. �񾭲���!!
    *iter++;    //�Ϸ� iterָ������һ���Ԫ�ط���
    (*iter)++;  //���Ϸ� ����iter��һ��Ԫ�� Ȼ��+1 char���Ͳ�������
    *iter.empty();  //���Ϸ�  iterָ��û��empty��Ա
    iter->empty();      //�Ϸ� �ҵ�iter������Ԫ�ز��ҵ�empty��Ա����
    ++*iter;        //���Ϸ� ��(*iter)++ һ�� char���Ͳ��������
    iter++->empty();      //�Ϸ���˼�� iterָ������һ��Ȼ����Ԫ�ص�smpty��Ա����

    //4.19
    int i,ival;
    int *ptr = &i;
    vector<int> vec;
    ptr != 0 && *ptr++; //����ȷ����ptr��intָ���޷�����һ��
    ptr != 0 && (*ptr)++
    ival++ && ival; // ����ȷ ��Ϊ�������ȵ��� ival++ ����ival ��δ֪
    ival +1 && ival;
    vec[ival++] <= vec[ival];   //����һ�� ival++ ��ival�Ǹ�������δ֪ �Ⱥ�˳��ͬ�����ͬ.
    vec[ival +1] <= vec[ival];

    //4.18
    //while �������ﲻ�����ǰ������� ��{}�����

    //4.17
    //ǰ������ �Ǽ�1 ��1֮�󷵻ظ�ĳֵ ������������ �ȷ��غ�+1-1

    //4.16
    if ( (p = getPtr()) != 0)
    if ( i == 1024)

    //4.15
    double dval;
    int ival;
    int *pi;
    //pi�ǵ�ַ ��Ҫ��*
    dval = ival = *pi = 0;

    //4.14
    //��һ��if ���� ��Ϊi�޷���42��ֵ
    // �ڶ���ֻҪ 42��ֵ����i ������

    //4.13
    int i;
    double d;
    d = i = 3.5;
    // d =3, i = 3
    i = d = 3.5;
    //i = 3, d = 3.5

    //4.12
    // i!=j<k  ���ж�j �Ƿ����k ���� ��� Ȼ�� i ������ �� ����

    //4.11
    int a = 5, b = 10, c = 15, d = 20;
    if (a > b && b > c && c > d)
        cout << "��ȷ"  << endl;

    //4.10
    int i;
    cin >> i;
    while (i != 42){
        cout << i << endl;
        cin >> i;
    }

    //4.9
    const char *cp = "Hello Word";
    if (cp && *cp)
    //cp�ĵ�ַ�������� cpָ����ָԪ�ز��ǿ�

    //4.8
    //���ȼ���ȵı��ʽ ��������ֵ˳��Ϊ��������.

    //4.7
    short i = 0;
    i += 40000;
    cout << i << endl;

    //4.6
    int i;
    while (cin>> i)
        if (i%2 == 0)
            cout << "���������ż��" << endl;
        else
            cout << "�������������" << endl;
    return 0;

    //4.5
    //  -30 * 3 + 21 / 5 =  -90+4=-86
    //  -30 + 3 * 21 / 5 =  -30 + 63/5= -30+12 = -18
    //  30 / 3 * 21 % 5 =  10 *21 % 5 = 210 % 5 =0
    //  -30 / 3 * 21 % 4 = -10 *21 %4 = -210 %4 = -2
    int i = -30 / 3 * 21 % 4;
	cout << i << endl;

    //4.4
    //  (12/3*4) + (5*15) + (24%4/2) = 16 + 75 + 0 = 91
    int i = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
	cout << i << endl;

    //4.3
    //�ɽ�����Ϊ ��ס����Ĭ�Ϲ��������˸���ݵı��ʽ��д.

    //4.2
    // (* ((vec.begin) () ) )
    // (* ( ((vec.begin) () ) ) + 1 ))

    //4.1
    cout << 5+10*20/2 << endl;
    //105
*/
