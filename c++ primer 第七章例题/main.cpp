#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //����������ĸ�����жϺ���   ����isalnum()�����ж����ֻ��Ǳ���ַ�����
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����

#include "Sales_data.h"
//#include "Person.h"
//#include "Screen.h"

using namespace std;    //���������ռ䶼���ص�Ĭ�Ϲؼ����� ��������������ر��Ƽ�

int main{

};



/*
typedef string Type;    //string�������˱���Type
Type initVal();         //����string���ص�initval����
class Exercise{
public:
    typedef double Type;    //double�������˱���Type;
    Type setVal(Type);      //����double�������͵ĺ��� setVal�β�double
    Type initVal();         //����double�������͵ĺ��� initVal;
private:
    int val;
};
//���������� ���巵�صĺ������Ͳ�һ��,       �β�����Ҳ��һ��
Exercise::Type Exercise::setVal(Exercise::Type parm){
    val = parm + initVal(); //�������ԱinitValʱ ����δ����   ����val��int���� ��parm��initVal���ض��Ǹ����� ���������ʧ
    return val;
}
Exercise::Type Exercise::initVal(){ return 3.14;}   //���Ϻ���
*/





/*
class Windows_mgr{
public:
    void clear(){}
};
class Screen{
public:
    typedef std::string::size_type pos;
    friend void Windows_mgr::clear();
    pos size() const;
    pos height, width, cursor;
};
Screen::pos Screen::size() const{ return height * width;}
*/




    //Acc ac;
    //int ii=10;
    //cout << ac.dummy(ii) <<endl;
    /*
    Sales_data book1, book2;
    if (read(book1)){
        while(read(book2)){
            if (book1.isbn() == book2.isbn()){  //�ж��鱾�ı���Ƿ�һ��
                book1.combine(book2);
                print(book1);
            }else{
                cout << "�ϱ����¼:" << endl;
                print(book1);
                cout << "\n �����¼�Ѹ����ϱ���ļ�¼" << endl;
                book1 = book2;

            }
        }
        print(book1);
    }else{
        cerr << "����û������" << endl;
    }
    */


/*
    //7.40
    Book�� ��Ҫ ��� ���� �ο��� ������� ����ۼ� ���� �������۶�
    Book(int i,std::string s, double is, std::string n, double isz, unsigned cnt, double f)
            :bookno(i), name(s), fee(is), date(n), price(isz), sales(cnt), amount(f){}

    //7.39
    ���Ϸ�
    ��Ϊ���캯��������Ĭ��ʵ�ξͶ������Ĭ�Ϲ��캯��
    ����Ĭ�Ϲ��캯���϶�һ��������ô�����ĸ���Ĭ�Ϲ��캯��?


    //7.38
Sales_data(istream &in= std::cin){}


    //7.37
Sales_data first_item(cin); //������Sales_data(std::istream &is){ read(*this);} �����޸� Ȼ��Ĭ�ϵ�����read��Ա����
int main(){
    Sales_data next;    //������ Sales_data(std::string s=""): name(s){}
    Sales_data last("9-999-99999-9"); //������Sales_data(std::string s=""): name(s){} ��s��ֵ���޸ĳ�"9-999-99999-9"


    //7.36
struct X{
    X(int i, int j):base(i), rem(i %j){} //���캯���ȳ�ʼ��rem ��base ����remδ��ʼ�� �޸�rem�ĳ�ʼֵ����
    int rem, base;
};


    //7.35
typedef string Type;    //string�������˱���Type
Type initVal();         //����string���ص�initval����
class Exercise{
public:
    typedef double Type;    //double�������˱���Type;
    Type setVal(Type);      //����double�������͵ĺ��� setVal�β�double
    Type initVal();         //����double�������͵ĺ��� initVal;
private:
    int val;
};
//���������� ���巵�صĺ������Ͳ�һ��,       �β�����Ҳ��һ��
Exercise::Type Exercise::setVal(Exercise::Type parm){
    val = parm + initVal(); //�������ԱinitValʱ ����δ����   ����val��int���� ��parm��initVal���ض��Ǹ����� ���������ʧ
    return val;
}
Exercise::Type Exercise::initVal(){ return 3.14;}   //���Ϻ���


    //7.34
    �ᱨ�� ��Ϊ����������Ŀǰ�ѱ����Աû�ҵ�pos ��ȫ��Ҳû�ҵ�.



    //7.33
class Windows_mgr{
public:
    void clear(){}
};
class Screen{
public:
    typedef std::string::size_type pos;
    friend void Windows_mgr::clear();
    pos size() const;
    pos height, width, cursor;
};
Screen::pos Screen::size() const{ return height * width;}
//���޸�  ������д���� �������ͱ���Ҫд������.

    //7.32
class Windows_mgr{
public:
    void clear(){}
};
class Screen{
public:
    friend void Windows_mgr::clear();
};


    //7.31
    class X{
    public:
        class Y;
        Y *ip;
    };
    class Y{
        public:
        class X;
        X *ip;
    };


    //7.30
    ������˼ά���Ӷ�? Ҫ����this ��Ҫ���Ǻ���ָ���ǲ��ǳ���  ������ú���һ������ָ��һ���ǳ������ᱨ��.
    �ŵ�,�����ĵ��������� ������ˮ ����Ҫ�ù�����������һ����˼.

    //7.29
    ��ȷ


    //7.28
    ���һ����������޸��˵�����
    �ڶ��б��ʽ�������δ�޸�ǰ��ʵ������


    //7.27
class Screen{
public:
    Screen() = default;
    Screen(std::string::size_type h, std::string::size_type w) : height(h), width(w), contents("aaaaaaaaaabbbbbbbbbbcccccccccc") {}
    Screen(std::string::size_type h, std::string::size_type w, std::string s)
            : height(h), width(w){}
    Screen(std::string::size_type h, std::string::size_type w, char s)
            : height(h), width(w), st(s){}

    inline
    char get(std::string::size_type h, std::string::size_type c);
    Screen &move(std::string::size_type r, std::string::size_type c);
    Screen &set(char ch);
    Screen &display(decltype(std::cout) &out);
private:
    std::string::size_type height, width, cursor;
    char st;
    std::string contents = "aaaaaaaaaabbbbbbbbbbcccccccccc";
};

inline
char Screen::get(std::string::size_type h, std::string::size_type c){
    return contents[h*width + c];
}

Screen &Screen::move(std::string::size_type h, std::string::size_type c){
    cursor = h*width +c;
    return *this;
}

Screen &Screen::set(char ch){
    contents[cursor] = ch;
    return *this;
}

Screen &Screen::display(decltype(std::cout) &out){
    out<<contents;
    return *this;
}


    //7.26
    inline
    double avg_price() const { return quantity ? fee/quantity : 0;}

    //7.25
    ����,��ΪĬ�ϵ��к� ����0;


    //7.23 7.24
    //��ڵ����ӷǳ�����. �Ҹ����� ��֮ǰ������ȫŪ����. ����֮ǰ���д����ø���..=.=
class Screen{
public:
    Screen() = default;
    Screen(std::string::size_type h, std::string::size_type w) : height(h), width(w), contents("                        ") {}
    Screen(std::string::size_type h, std::string::size_type w, std::string s)
            : height(h), width(w), contents(s){}

    inline
    char get(std::string::size_type h, std::string::size_type c);
    Screen &mo(std::string::size_type r, std::string::size_type c);
private:
    std::string::size_type height, width, s;
    std::string contents;
};

inline
char Screen::get(std::string::size_type h, std::string::size_type c){
    return contents[h*width + c];
}

Screen &Screen::mo(std::string::size_type h, std::string::size_type c){
    s = h*width +c;
    return *this;
}


    //7.22
class Person{
friend void read(Person &);
friend void print(const Person &);
public:
    Person() = default;
    Person(const std::string &s,const std::string &sa):name(s), address(s){}
private:
    std::string name;
    std::string address;
};


    //7.21
���޸�
//Sales_data.h
class Sales_data{
friend Sales_data add(const Sales_data&, const Sales_data&);
friend void print(const Sales_data&);
friend bool read(Sales_data&);
public:
    Sales_data() = default;
    Sales_data(const std::string &s) : name(s) {}
    Sales_data(int n) : quantity(n) {}
    Sales_data(double p) : price(p), fee(p){}
    Sales_data(const std::string &s, int n, double p)
			:name(s), quantity(n), price(p), fee(p){}

    Sales_data &combine(const Sales_data &ip)
    {
        quantity += ip.quantity;
        fee += ip.fee;
        return *this;
    }

    std::string isbn() const{return name;}

private:
    std::string name ;
    int quantity = 0;
    double price = 0.0;
    double fee = 0.0;
};

//����cin �� ��ʵ�� д��ʵ������ ����cin
bool read( Sales_data &item)
{
    double sum = 0;
    std::cout << "��������:";
    std::cin >> item.name;
    std::cout << "������������:";
    std::cin >> item.quantity;
    std::cout << "���뵥��:";
    std::cin >> item.price;
    item.fee = item.price *  item.quantity;
    //д��booknoʡ����.
    return 1;
    }

//��ʵ��1���ݸ� ��3 Ȼ�����2���ݺ���3���ݵ���
Sales_data add(const Sales_data &book1, const Sales_data &book2)
{
    Sales_data book3 = book1;
    book3.combine(book2);
    return book3;
}

//��� ��ʵ������Ϣ
void print( const Sales_data &item)
{
    std::cout<< "���������:" << item.name
        << "\n����������:" << item.quantity
        << "\n�۸�:"  << item.price
        << "\n�������۽��:" << item.fee;
}



    //7.20
    ��Ԫ�ܺõ����ⲿ�����ܹ����Ƶ�ʹ���޸���ʽ��Ա,
    �׶������Ա�������޷����� ����ĺ�����,


    //7.19
class Person{
public:
    Person() = default;
    Person(const std::string &s,const std::string &sa):name(s), addrees(s){}
private:
    std::string name;
    std::string addrees;
};
//�ɳ�Ա��һЩ��Ҫ��д�ı������ݷ�װ��, ��Ϊ�����Ҫ�޸Ŀ��Ե��ú���,������ֱ���ڳ�Ա���޸�,

    //7.18
    ��װ�������ز�����ʾ����.
    ��Щ�ؼ���Ա��������Ƶı���, ������ⲿ�޸��˺��������,
    �ܷ�װ������������ߺܴ�İ�ȫ��.


    //7.17
    ������,
    class���൱�� �����һ��д��private:
    struct���൱�� �����һ��д��public:


    //7.16
    ����û�� λ����ֻҪ�������ھ���,
    public֮����Ķ���Ҫ���ⲿ���õĳ�Ա
    private֮����Ķ���ֻ�����ڲ�ʹ�õĳ�Ա;


    //7.15
struct Person{
    Person() = default;
    Person(const std::string &s,const std::string &sa):name(s), addrees(s){}
    std::string name;
    std::string addrees;
};

    //7.14
    ˵ʵ��������ʾ�ĳ�ʼ���� ��ʽ�ĳ�ʼ��û�������
    Sales_data() = default;
    Sales_data(const std::string &s) : name(s) {}
    Sales_data(int n) : quantity(n) {}
    Sales_data(double p) : price(p), fee(p){}
    Sales_data(const std::string &s, int n, double p)
			:name(s), quantity(n), price(p), fee(p){}

    //7.13
int main()
{
    Sales_data book1, book2;
    if (book1.name != ""){
        goto beg;
        while(book2.read(book2)){
            beg:    //��Ϊ��һ��Ĭ������ʵ�����Զ�����read��������Ҫ�ٽ���һ��while �Ҿ�ʹ������ת.
            if (book1.isbn() == book2.isbn()){  //�ж��鱾�ı���Ƿ�һ��
                book1.combine(book2);
                print(book1);
            }else{
                cout << "�ϱ����¼:" << endl;
                print(book1);
                cout << "\n �����¼�Ѹ����ϱ���ļ�¼" << endl;
                book1.name = book2.name;
                book1.quantity = book2.quantity;
                book1.price = book2.price;

            }
        }
        print(book1);
    }else{
        cerr << "����û������" << endl;
    }


    //7.12
    ����������֮ǰ�����read�������� ����. ����Ҳûѧ�����������������⺯��.
    �ѵ�Ҫ�ں����β��ﴫָ��? �������read�����ƶ���������.
struct Sales_data{
    Sales_data()	//���Ʊ�������������ͬ, û�з������ͺͷ���ֵ
	{
        read( *this); //read�����������Ǵ�is�ж�ȡһ����Ϣ����this������.
	}

    std::string name ;
    std::string bookno;
    int quantity = 0;
    double price = 0.0;
    double fee = 0.0;


    bool read( Sales_data &item)
    {
        double sum = 0;
        std::cout << "��������:";
        std::cin >> item.name;
        std::cout << "������������:";
        std::cin >> item.quantity;
        std::cout << "���뵥��:";
        std::cin >> item.price;
        item.fee = item.price *  item.quantity;
        //д��booknoʡ����.
        return 1;
    }
};


    //7.11
//���ļ�
int main()
{
      Sales_data book1;
    cout<< book1.bookno << book1.fee << book1.name << book1.price << book1.quantity <<endl;
}
//Sales_data.h
struct Sales_data{
    Sales_data() = default;
    Sales_data(const std::string &s) : bookno(s) {}
    Sales_data(const std::string &s, int n, double p)
			:name(s), bookno(s), quantity(n), price(p), fee(p){}




    //7.10
    ��read��������cin��data1��ʵ�� ���ص����ݸ����read�����ĵ�һ���β� �ڶ����β� ����data2��ʵ�� ���鿴����������������Ƿ�Ϊ0���.

    //7.9
struct Person{
    std::string name;
    std::string addrees;
};

void read( Sales_data &item)
{
    double sum = 0;
    std::cout << "��������:";
    std::cin >> item.name;
    std::cout << "�����ַ:";
    std::cin >> item.address;
}

void print (Person &ip)
{
        std::cout << "\n������:" << ip.name
        << "\n��ַΪ:" << ip.addrees;
}

    //7.8
    ��Ϊprint ������ֻ�ǵ���Ȼ����ʾ, �����޸�����
    ��read Ҫд�����ݲ���ʹ��const;



    //7.7
int main()
{
    Sales_data book1, book2;
    if (read(book1)){
        while(read(book2)){
            if (book1.isbn() == book2.isbn()){  //�ж��鱾�ı���Ƿ�һ��
                book1.combine(book2);
                print(book1);
            }else{
                cout << "�ϱ����¼:" << endl;
                print(book1);
                cout << "\n �����¼�Ѹ����ϱ���ļ�¼" << endl;
                book1.name = book2.name;
                book1.bookno = book2.bookno;
                book1.quantity = book2.quantity;
                book1.price = book2.price;
            }
        }
        print(book1);
    }else{
        cerr << "����û������" << endl;
    }
}

    //7.6
    //����cin �� ��ʵ�� д��ʵ������ ����cin
bool read( Sales_data &item)
{
    double sum = 0;
    std::cout << "��������:";
    std::cin >> item.name;
    std::cout << "������������:";
    std::cin >> item.quantity;
    std::cout << "���뵥��:";
    std::cin >> item.price;
    item.fee = item.price *  item.quantity;
    return 1;
}

//��ʵ��1���ݸ� ��3 Ȼ�����2���ݺ���3���ݵ���
Sales_data &add(const Sales_data &book1, const Sales_data &book2)
{
    Sales_data book3 = book1;
    book3.combine(book2);
    return book3;
}

//��� ��ʵ������Ϣ
void print( const Sales_data &item)
{
    std::cout << "��ı��Ϊ:" << item.bookno
        << "\n���������:" << item.name
        << "\n����������:" << item.quantity
        << "\n�۸�:"  << item.price
        << "\n�������۽��:" << item.fee;
}


    //7.5
    std::string namedef() const {};
    std::string addressdef() {};    //������Ϊconst ����ַ��Ҫ����. ��ַ���ܻ�����������


    //7.4
struct Person{
    std::string name;
    std::string addrees;
};


    //7.3
int main()
{
    Sales_data book1;
    if (cin >> book1.name){
        cin >> book1.quantity;
        Sales_data book2;
        while(cin>> book2.name){
            if (book1.isbn() == book2.isbn()){
                book1.combine(book2);
            }else{
                cout << "ǰһ����Ϊ:"<< book1.name <<"ǰһ��������Ϊ��:" << book1.quantity << endl;
                book1.name = book2.name;
                book1.quantity = book2.quantity;
            }
        }
        cout << "ǰһ��������Ϊ:"  << book1.quantity << endl;
    }else{
        cerr << "����û������" << endl;
    }
}


    //7.2
#include <iostream>
#include <string>

struct Sales_data{
    std::string name;
    std::string bookno;
    int quantity = 0;
    double jiaqian = 0.0;

    Sales_data &combine(const Sales_data &ip)
    {
        quantity += ip.quantity;
        jiaqian += ip.jiaqian;
        return *this;
    }

    std::string isbn() const
    {
        cerr << "����û������" << endl;
    }

};


    //7.1
//�������ļ�����
#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //����������ĸ�����жϺ���   ����isalnum()�����ж����ֻ��Ǳ���ַ�����
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����

#include "Sales_data.h"

using namespace std;    //���������ռ䶼���ص�Ĭ�Ϲؼ����� ��������������ر��Ƽ�

int main()
{
    Sales_data book1;
    if (cin >> book1.name){
        cin >> book1.quantity;
        Sales_data book2;
        while (cin>> book2.name){
            cin >> book2.quantity;
            if (book1.name == book2.name){
                book1.quantity += book2.quantity;
                cout << "���μ�¼��֮ǰ���ۼ�¼�ϲ�" << endl;
            }else{
                cout << "ǰһ����Ϊ:"<< book1.name <<"ǰһ��������Ϊ��:" << book1.quantity << endl;
                book1.name = book2.name;
                book1.quantity = book2.quantity;
            }
        }
        cout << "ǰһ��������Ϊ:"  << book1.quantity << endl;
    }else{
        cerr << "����û������" << endl;
    }
}

//Sales_data.h �ļ�����
struct Sales_data{
    std::string name;
    int quantity = 0;
    double jiaqian = 0.0;
};
*/
