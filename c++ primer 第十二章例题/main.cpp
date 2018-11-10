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

using namespace std;


class StrBlob{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob(): data(make_shared<vector<string>>()){}
    StrBlob(std::initializer_list<std::string> il): data(make_shared<vector<string>>(il)){}
    size_type size() const {return data->empty();}
    void push_back(const std::string &t){data ->push_back(t);}
    void pop_back();
    std::string& front();
    std::string& back();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};


void StrBlob::check(size_type i, const std::string &msg) const{
    if (i >= data->size())  //����lenֵ���С�ڵ��� ����iֵ0�� �״���;
        throw out_of_range(msg);
}
//ͬ����front() back() pop_back()����; ÿ�����������и�check(0,"������ʾ");
template <typename T>
class BoBo{
public:
    BoBo(): data(make_shared<vector<T>>){}
    BoBo(initializer_list<T> il): data(make_shared<vector<T>>(il)){}
    typename vector<T>::size_type  size()const{
        return data->size();
    }
    void  push_back(const T &v1) const{
        check(0,"����δ�ղ���ɾ��");
        data->push_back(v1);
    }
    void  pop_back();
    T  front(){
        check(0,"����δ�ղ���ȡ��");
        return data->front();
    }
    T  back(){
        check(0,"����δ�ղ���ȡ��");
        return data->back();
    }
private:
    shared_ptr<vector<string>> data;
    void check(const int &i,string &s){ //�ж��Ƿ�� ������;
        if (i >= data->size())
            throw out_of_range(s);
    }
};
int main()
{
    vector<string> aa = {"a","b"};
    StrBlob a(aa);

}
/*
//12.3


//12.2
template <typename T>
class BoBo{
public:
    BoBo(): data(make_shared<vector<T>>){}
    BoBo(initializer_list<T> il): data(make_shared<vector<T>>(il)){}
    typename vector<T>::size_type  size()const{
        return data->size();
    }
    void  push_back(const T &v1) const{
        check(0,"����δ�ղ���ɾ��");
        data->push_back(v1);
    }
    void  pop_back();
    T  front(){
        check(0,"����δ�ղ���ȡ��");
        return data->front();
    }
    T  back(){
        check(0,"����δ�ղ���ȡ��");
        return data->back();
    }
private:
    shared_ptr<vector<string>> data;
    void check(const int &i,string &s){ //�ж��Ƿ�� ������;
        if (i >= data->size())
            throw out_of_range(s);
    }
};


//12.1
b1����3��Ԫ�� b2������

*/
