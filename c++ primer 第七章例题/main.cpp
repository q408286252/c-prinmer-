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

/*
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
