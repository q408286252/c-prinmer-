#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //����������ĸ�����жϺ���   ����isalnum()�����ж����ֻ��Ǳ���ַ�����
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����

using namespace std;    //���������ռ䶼���ص�Ĭ�Ϲؼ����� ��������������ر��Ƽ�

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

/*
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
