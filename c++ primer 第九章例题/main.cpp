#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //�����ַ��ж�(�Ƿ��Ƿ��� ���� ��� ��ĸ�� ʲô��.)�����Ŀ�
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����
#include <fstream>  //�ļ�IO
#include <sstream>  //strIO
#include <list>     // ��������
#include <deque>    // ˫��vector

using namespace std;

vector<int>::iterator  cha(vector<int> &ints,const int &inta)
{
    for (auto ip = ints.begin(); ip != ints.end(); ++ip)
        if (*ip == inta)
            return ip;
}

int main()
{

    list<int> lst1;
    list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
    //while (iter1 < iter2) /* */     //���� ָ��ȴ�С ��end��ָ�����޷���
    while (iter1 != iter2) /* */
}

/*
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
