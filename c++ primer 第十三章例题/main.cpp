#include <iostream> 		//���������
#include <string>   		//�ַ����ļ�
#include <cctype>   		//�����ַ��ж�(�Ƿ��Ƿ��� ���� ��� ��ĸ�� ʲô��.)�����Ŀ�
#include <vector>   		//���ɶ�������� �׳��б�
#include <cstring>  		//�ṩC���Ա�׼���һЩ����
#include <fstream>  		//�ļ�IO
#include <sstream>  		//strIO
#include <list>     		// ˫���� ����
#include <forward_list> 	//����������
#include <deque>    		// ˫��vector����
#include <array>    		//�̶����� array
#include <stack>    		//ջ������stack
#include <queue>    		//���������� ����: priority_queue �� queue;
#include <algorithm>    	//�󲿷��㷨�ļ�
#include <iterator> 		//���ֵ�����  ��������� ��������;���������;�ƶ�������;
#include <functional>   	//��bind����;  ref(os) ����һ������ɿ�������   cref(os)��������ɿ���const���� ��Ҫ�����޷���ֵ����
#include <map>  			//��Ӧֵ����
#include <set>  			//�ؼ�������
#include <unordered_map>    //�����Ӧֵ����
#include <unordered_set>    //����ؼ�������
#include <cxxabi.h>         //��typeid(������).name() ʱ�õ��İ���gcc��ʾ��������
#include <utility>          //ʹ��pairһ�Ա�������
#include <ctime>            //c�ĳ����ʱ���
#include <memory>           //����ָ��, allocator��


using namespace std;

class StrVec{
public:
    StrVec():elements(nullptr), first_free(nullptr),cap(nullptr){}
    StrVec(const initializer_list<string> &s){
        auto newdata = alloc_n_copy(s.begin(),s.end());
        elements = newdata.first;
        cap = first_free = newdata.second;
    }
    StrVec(const StrVec&s){            //�������캯��
        auto newdata = alloc_n_copy(s.begin(),s.end());
        elements = newdata.first;
        cap = first_free = newdata.second;
    }
    StrVec& operator=(const StrVec&s){    //������ֵ�����;
        auto newdata = alloc_n_copy(s.begin(), s.end());    //�����µ��ڴ洴������
        free();                             //ɾ����ǰ
        elements = newdata.first;
        cap = first_free = newdata.second;
        return *this;
    }
    ~StrVec(){  free();}

    void push_back(const string&s){
        chk_n_alloc();
        alloc.construct(first_free++,s);
    }
    void reserve(const int &n){ //���¹����ܱ���nԪ�صķ����ڴ�;
        if( n > capacity()){
            auto newcapacity = n;   //��0Ԫ�ط������ܴ�����!
            auto newdata = alloc.allocate(newcapacity); //�������ڴ�
            auto dest = newdata;
            auto elem = elements;
            for (size_t i = 0; i != size(); ++i)
                alloc.construct(dest++, std::move(*elem++));
            free();
            elements = newdata;
            first_free = dest;
            cap = elements + newcapacity;
        }
    }
    void resize(int ls,string s = string("")){
        if (ls > size() ){
            auto newcapacity = ls;   //��0Ԫ�ط������ܴ�����!
            auto newdata = alloc.allocate(newcapacity); //�������ڴ�
            auto dest = newdata;
            auto elem = elements;
            for (size_t i = 0; i != size(); ++i)
                alloc.construct(dest++, std::move(*elem++));
            for (size_t i = 0; i != newcapacity- size(); ++i)
                alloc.construct(dest++, s);
            free();
            elements = newdata;
            first_free = dest;
            cap = elements + newcapacity;
        }  else if (ls < size() && ls>= 0){
            auto p = first_free;
            for(auto i= 0; i != size()-ls;++i)
                alloc.destroy(--p);
        }
    }
    size_t size() const{ return first_free - elements;} //��ǰʹ��Ԫ��
    size_t capacity() const {return cap-elements;}  //����ʹ��Ԫ��;
    string* begin() const {return elements;}
    string* end() const {return first_free;}

private:
    static std::allocator<string> alloc; //��̬����
    string *elements;   //��
    string *first_free; //����
    string *cap;        //β��

    void chk_n_alloc(){     //���㵱ǰԪ���Ƿ���� ������Ԫ����;
        if(size() == capacity())
            reallocate();
    }
    //���� ����һ�������ڴ涯̬����,���� �׺�β�� ָ��;
    pair<string*,string*> alloc_n_copy(const string*s1,const string*s2){
        auto data = alloc.allocate(s2-s1);
        return { data, uninitialized_copy(s1,s2,data) };
    }
    void reallocate(){  //���·��䶯̬�ڴ�
        auto newcapacity = size() ? 2*size(): 1 ;   //��0Ԫ�ط������ܴ�����!
        auto newdata = alloc.allocate(newcapacity); //�������ڴ�
        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;
    }
    void free(){    //ɾ������
        if(elements){    //ʼָ�벻Ϊ����
            for(auto p = first_free; p != elements;)
                alloc.destroy(--p);
            alloc.deallocate(elements, cap-elements);
            //��һ��д��û��� for_each(first_free,elements, [first_free](const string &s){alloc.destroy(--first_free);});
        }
    }
};
std::allocator<string> StrVec::alloc;


void push_back(const int&a){
    cout << "������1";
}
void push_back(int&&a){
    cout << "������2";
}
int main(){
    push_back(12);
    int a = 12;
    push_back(a);
    push_back(std::move(a));
    const int b = 12;
    push_back(b);
}

/*
//13.49



//13.47  13.48
    emmmmm

//13.46
    //int f();
    vector<int> vi(100);
    //int &r1 = f();   //����
    //int r1 = f();      //����
    //const int &r1 = f();    //����
    //int &&r1 = f();   //����
    //���е���. Ȼ���ְ���������int f();��һ������������. �ɱ�. �Ǿ������������
    int f(5);
    int &r1 = f;
    int &r2 = vi[0];
    int &r3 = r1;
    int &&r4 = vi[0] * f;


//13.45
��ֵ����  ��һ�� ���û�����, Ψһ, ��ʱ����ʱ��ɾ������ֵ
��ֵ����  ��һ������������� ���������const



//13.44  42 ..
emmmm����.

//13.43
for_each(first_free,elements, [first_free](const string &s){alloc.destroy(--first_free);});
���������. forѭ�����������. �������ܷ���ò��û�����?


//13.41
д��Ԫ��= �ڴ����Ԫ��ʱ �ᳬ�ڴ�.
��һ��Ԫ��λ����Զ����
����Ԫ��ʱ����; ɾ���ڴ�Ҳ�����

//13.39 -40
class StrVec{
public:
    StrVec():elements(nullptr), first_free(nullptr),cap(nullptr){}
    StrVec(const initializer_list<string> &s){
        auto newdata = alloc_n_copy(s.begin(),s.end());
        elements = newdata.first;
        cap = first_free = newdata.second;
    }
    StrVec(const StrVec&s){            //�������캯��
        auto newdata = alloc_n_copy(s.begin(),s.end());
        elements = newdata.first;
        cap = first_free = newdata.second;
    }
    StrVec& operator=(const StrVec&s){    //������ֵ�����;
        auto newdata = alloc_n_copy(s.begin(), s.end());    //�����µ��ڴ洴������
        free();                             //ɾ����ǰ
        elements = newdata.first;
        cap = first_free = newdata.second;
        return *this;
    }
    ~StrVec(){  free();}

    void push_back(const string&s){
        chk_n_alloc();
        alloc.construct(first_free++,s);
    }
    void reserve(const int &n){ //���¹����ܱ���nԪ�صķ����ڴ�;
        if( n > capacity()){
            auto newcapacity = n;   //��0Ԫ�ط������ܴ�����!
            auto newdata = alloc.allocate(newcapacity); //�������ڴ�
            auto dest = newdata;
            auto elem = elements;
            for (size_t i = 0; i != size(); ++i)
                alloc.construct(dest++, std::move(*elem++));
            free();
            elements = newdata;
            first_free = dest;
            cap = elements + newcapacity;
        }
    }
    void resize(int ls,string s = string("")){
        if (ls > size() ){
            auto newcapacity = ls;   //��0Ԫ�ط������ܴ�����!
            auto newdata = alloc.allocate(newcapacity); //�������ڴ�
            auto dest = newdata;
            auto elem = elements;
            for (size_t i = 0; i != size(); ++i)
                alloc.construct(dest++, std::move(*elem++));
            for (size_t i = 0; i != newcapacity- size(); ++i)
                alloc.construct(dest++, s);
            free();
            elements = newdata;
            first_free = dest;
            cap = elements + newcapacity;
        }  else if (ls < size() && ls>= 0){
            auto p = first_free;
            for(auto i= 0; i != size()-ls;++i)
                alloc.destroy(--p);
        }
    }
    size_t size() const{ return first_free - elements;} //��ǰʹ��Ԫ��
    size_t capacity() const {return cap-elements;}  //����ʹ��Ԫ��;
    string* begin() const {return elements;}
    string* end() const {return first_free;}

private:
    static std::allocator<string> alloc; //��̬����
    string *elements;   //��
    string *first_free; //����
    string *cap;        //β��

    void chk_n_alloc(){     //���㵱ǰԪ���Ƿ���� ������Ԫ����;
        if(size() == capacity())
            reallocate();
    }
    //���� ����һ�������ڴ涯̬����,���� �׺�β�� ָ��;
    pair<string*,string*> alloc_n_copy(const string*s1,const string*s2){
        auto data = alloc.allocate(s2-s1);
        return { data, uninitialized_copy(s1,s2,data) };
    }
    void reallocate(){  //���·��䶯̬�ڴ�
        auto newcapacity = size() ? 2*size(): 1 ;   //��0Ԫ�ط������ܴ�����!
        auto newdata = alloc.allocate(newcapacity); //�������ڴ�
        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;
    }
    void free(){    //ɾ������
        if(elements){    //ʼָ�벻Ϊ����
            for(auto p = first_free; p != elements;)
                alloc.destroy(--p);
            alloc.deallocate(elements, cap-elements);
        }
    }
};
std::allocator<string> StrVec::alloc;
int main(){
    StrVec li;
    StrVec l2({"a","b","c"});
    cout << li.capacity()<< "\n" << l2.capacity() << "\n";
    li.push_back("aa");
    cout << li.capacity() << "\n";
    li.reserve(10);
    cout << li.capacity() << "\n";
    li.resize(20,"a");
    cout << *(li.begin() +11) << li.capacity() << "\n";
    StrVec l3 = li;
    cout << l3.capacity() << "\n";
}

//13.33 ~13.38
class Message;

class Folder{
public:
    friend class Message;
    void remMsg(Message *ptr){
        set_Message.erase(ptr);
    }
    void addMsg(Message *ptr){
        set_Message.insert(ptr);
    }
    void save(Message &f){
        set_Message.insert(&f);
    }
    void remove(Message &f){
        set_Message.erase(&f);
    }
private:
    set<Message*> set_Message;
};

class Message{
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
public:
    explicit Message(const std::string &str = ""): contents(str) {} //��ʼ��stringֵ
    //����������캯�� string �� Fʵ��ָ��ļ��� ����  ���� ������m�ļ���ÿ��ʵ��ָ�����Msg
    Message(const Message &m):contents(m.contents), folders(m.folders) { add_to_Folders(m);}
    //������ֵ�����
    Message& operator=(const Message &rhs){
        //��ǰʵ���ļ��� ÿ��Ԫ�ص���remMsgһ��
        remove_from_Folders();
        contents = rhs.contents;
        folders = rhs.folders;
        //���ε�ʵ������ ÿ��Ԫ�ص���addMsgһ��
        add_to_Folders(rhs);
        return *this;
    }
    ~Message(){
        //��ǰʵ���ļ��� ÿ��Ԫ�ص��� remMsgһ��;
        remove_from_Folders();
    }

    void save(Folder &f){
        folders.insert(&f);
        f.addMsg(this);
    }
    void remove(Folder &f){
        folders.erase(&f);
        f.remMsg(this);
    }
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message &m){
        for(auto f: m.folders)
            f->addMsg(this);
    }
    void remove_from_Folders(){
        for(auto f: folders)
            f->remMsg(this);
    }
};

void swap(Message &lhs, Message &rhs){
    using std::swap;
    for(auto f: lhs.folders)
        f->remMsg(&lhs);
    for(auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for(auto f: lhs.folders)
        f->addMsg(&lhs);
    for(auto f: rhs.folders)
        f->addMsg(&rhs);
}

int main(){
    Message m1("xingxiuyan"),m2("lindaiyu"),m3("xuebaochai");
	Folder f1, f2, f3, f4, f5;
	m1.save(f1);
	f1.save(m2);
}

//13.5
HasPtr(const HasPtr &a): ps(new string(*a.ps)), i(a.i) {cout << "��������Ŷ";}

//13.4
����ʱ��;
Point local = arg; ʱ��;
Point pa[4] ��ʱ��
����ʱ��;

//13.3
ֻҪ���࿽������ ���ÿ������캯����;

//13.2
������캯���Ƿǳ����ش����; Sales_data rhsҪ�������뿽������ Ȼ��Ҫ������ �������������� �ݹ���


//13.1
�������캯������ ���������ڷ����õ��β� ����ֵ ��=  {}��ֵʱ��� ���õĹ��캯��;
ֻ���������β���Ҫ �������캯���Զ��任��ʵ�δ��ݸ���;


*/
