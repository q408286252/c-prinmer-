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


class A{
public:
    A(const string &s = string()): ps(new string(s)), i(0), use(new size_t(1)) {}
    A(const A& p): ps(p.ps), i(p.i), use(p.use){ ++*p.use; }
    A& operator=(const A& p){
        ++*p.use;
        if (--*use ==0){
            delete use;
            delete ps;
        }
        ps = p.ps;
        i = p.i;
        use = p.use;
        return *this;
    };
    ~A(){
        if (--*use ==0){
            delete use;
            delete ps;
        }
    }

private:
    string *ps;
    int i;
    size_t *use;
};


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


/*

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
