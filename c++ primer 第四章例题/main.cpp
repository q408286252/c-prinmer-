#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //����������ĸ�����жϺ���   ����isalnum()�����ж����ֻ��Ǳ���ַ�����
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����

//#include "Sales_data.h" //���ر����������ļ�

using namespace std;    //���������ռ䶼���ص�Ĭ�Ϲؼ����� ��������������ر��Ƽ�

int main()
{
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


}


/*
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
