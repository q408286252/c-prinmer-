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
#include "Sales_data.h"

using namespace std;

template <typename T,typename T2>
int compare(const T&v1, const T2&v2){
    auto i = find(v1.begin(),v1.end(),v2);
    return *i;
}

template <typename T,size_t T2>
void print(array<T, T2> &arr){
    for (auto value: arr)
        cout << value << endl;
}
template <typename T,size_t T2>
T* begin(array<T, T2> &arr){
    T* i =&arr[0];
    return i;
}
template <typename T,size_t T2>
T* end(array<T, T2> &arr){
    T* i =&arr[T2-1];
    i++;
    return i;
}

template <typename T,size_t N>
constexpr size_t co(array<T, N> &arr){
    return N;
}
int main(){
    //vector<int> vec = {1,2,3};
    //cout << compare(vec,3);
    array<string, 5> a = {"a","b","c","d","e"};
    //print(a);
    cout << co(a);

}
/*
//16.8
��Ϊc++ �е����������� �������ڼ���ȫ������������. �����������㷽ʽ�� == �� !=
�� <= < > >= ��Щ������ܲ�û��ʵ��. ���Ա��뻻��< > ;


//16.7
template <typename T,size_t N>
constexpr size_t co(array<T, N> &arr){
    return N;
}
int main(){
    array<string, 5> a = {"a","b","c","d","e"};
    cout << co(a);
}

//16.6
template <typename T,size_t T2>
T* begin(array<T, T2> &arr){
    T* i =&arr[0];
    return i;
}
template <typename T,size_t T2>
T* end(array<T, T2> &arr){
    T* i =&arr[T2-1];
    i++;
    return i;
}
//end ���Ӧ���Ǵ���һ����̬�ڴ�ƴ���������β��. ���������������д��.
//���������++ -- +n -n���㶼ûʵ��.


//16.5
template <typename T,size_t T2>
void print(array<T, T2> &arr){
    for (auto value: arr)
        cout << value << endl;
}

int main(){
    array<string, 5> a = {"a","b","c","d","e"};
    print(a);
}

//16.4
template <typename T,typename T2>
int compare(const T&v1, const T2&v2){
    auto i = find(v1.begin(),v1.end(),v2);
    return *i;
}
int main(){
    vector<int> vec = {1,2,3};
    cout << compare(vec,3);

}


//16.3
template <typename T>
T co(const T&v1, const T&v2){
    add(v1,v2);
    return add(v1,v2);
}
int main(){
    Sales_data a(10), b(20);
    a = co(a,b);
    print(a);
}


//16.2
template <typename T>
int co(const T&v1, const T&v2){
    return v1+v2;
int main()
{
   cout << co(1,2);
}



//16.1
ʵ�����Ķ���:���ݴ��������ģ��������� ���Զ������ͽ���auto���Ƶı�� ��дһ���ض��汾�ĺ���.��������ʵ��;


*/
