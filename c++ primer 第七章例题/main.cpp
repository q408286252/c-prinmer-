#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //����������ĸ�����жϺ���   ����isalnum()�����ж����ֻ��Ǳ���ַ�����
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����

#include "Sales_data.h"
#include "Person.h"

using namespace std;    //���������ռ䶼���ص�Ĭ�Ϲؼ����� ��������������ر��Ƽ�

int main()
{
    /*
    Sales_data book1, book2;
    if (book1.read(book1)){
        while(book2.read(book2)){
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
*/

//    Sales_data book1;
//    cout<< book1.bookno << book1.fee << book1.name << book1.price << book1.quantity <<endl;
    Person ps;
}



/*
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
