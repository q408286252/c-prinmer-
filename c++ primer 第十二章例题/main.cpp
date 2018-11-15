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

shared_ptr< vector<int> > fun(){
    shared_ptr< vector<int> > p = make_shared< vector<int>>();
    return p;
}
shared_ptr< vector<int> >  fun2(initializer_list<int> &la){
    shared_ptr< vector<int> > p = fun();
    for(auto iter = la.begin(); iter != la.end(); ++iter)
        p->push_back(*iter);
    return p;
}
void fun3(shared_ptr< vector<int> > p){
    for(auto iter = p->begin(); iter != p->end(); ++iter)
        cout << *iter;
}

void pro(shared_ptr<int> p){
    cout << *p;
}

int main()
{
    shared_ptr<int> p(new int(9));
    pro(shared_ptr<int>(p.get()));
}
/*

//12.11




//12.10
    ����ȷ; ��Ϊ���β��Ǵ�p����ָ�� ���Ǵ���һ��pͬ�����ڴ������ָ�뿽��;
    �Ѳ���shared_ptr<int>(p) ��Ϊp����.


//12.9
    int *q= new int(42), *r = new int(100);
    r = q;  // new int(100) ռ���ڴ���Զ�޷�delete
    auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
    r2 = q2;  //make_shared<int>(100) ռ���ڴ��Զ�ɾ��;


//12.8
bool b(){
    int *p = new int;
    //...
    return p;
}
=. = bool ��Ϊ int*�Ŷ԰�;
��Ȼ���������� ��pָ���Ϊbool ���õĶ�̬�ڴ���ôɾ?


//12.7
shared_ptr< vector<int> > fun(){
    shared_ptr< vector<int> > p = make_shared< vector<int>>();
    return p;
}
shared_ptr< vector<int> >  fun2(initializer_list<int> &la){
    shared_ptr< vector<int> > p = fun();
    for(auto iter = la.begin(); iter != la.end(); ++iter)
        p->push_back(*iter);
    return p;
}
void fun3(shared_ptr< vector<int> > p){
    for(auto iter = p->begin(); iter != p->end(); ++iter)
        cout << *iter;
}
int main()
{
    initializer_list<int> la = {1,2,3};
    fun3( fun2(la) );
}


//12.6
vector<int>* fun(){
    return new vector<int>{};
}
vector<int> * fun2(initializer_list<int> &la){
    vector<int> *ptrvec = fun();
    for(auto iter = la.begin(); iter != la.end(); ++iter)
        ptrvec->push_back(*iter);
    return ptrvec;
}
void fun3(vector<int> *ptrvec){
    for(auto iter = ptrvec->begin(); iter != ptrvec->end(); ++iter)
        cout << *iter;
    delete ptrvec;
}
int main()
{
    initializer_list<int> la = {1,2,3};
    fun3( fun2(la) );
}


//12.5
    �ŵ� ��ʹ��֧�������͵Ĵ���
    explicit ûд��ȱ����: ��������,���������Ҫʵ��ʱ��û��ʵ������ܻ�Ѵ���Ĳ���ʵ����,������ԭ����˼�벻һ����������;

//12.4
    ΪʲôҪ���i�Ƿ� ����0?  Ҫ���Ҳ�Ǽ���Ƿ���ڵ���0,�״�����Ҫ���ǿ��Ƿ�Ϊ�հ�.

//12.3
    ����Ҫ.push_back��pop_back ���������ݲ������ ɾ����ĩβֵ,��Υ����cont �������Ҫ�󲻸ı����


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
