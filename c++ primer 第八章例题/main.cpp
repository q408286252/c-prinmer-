#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //�����ַ��ж�(�Ƿ��Ƿ��� ���� ��� ��ĸ�� ʲô��.)�����Ŀ�
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����
#include <fstream>  //�ļ�IO

#include "Sales_data.h"

using namespace std;



int main()
{
    ifstream in("data.txt");
    Sales_data book1, book2;
    if ( in.good() ){
        book1.read(in);
        while ( in.good() ){
            book2.read(in);
            in.close();
            if (book1.name == book2.name){
                book1.quantity += book2.quantity;
                cout << "���μ�¼��֮ǰ���ۼ�¼�ϲ�" << endl;
            }else{
                cout << "ǰһ����Ϊ:"<< book1.name <<"ǰһ��������Ϊ��:" << book1.quantity << endl;
                book1.name = book2.name;
                book1.quantity = book2.quantity;
            }
        }
        cout << "���һ��������Ϊ:"  << book1.quantity << endl;
    }else{
        cerr << "����û������" << endl;
    }
}


/*

    //8.6
    ifstream in("data.txt");
    Sales_data book1, book2;
    if ( in.good() ){
        book1.read(in);
        while ( in.good() ){
            book2.read(in);
            in.close();
            if (book1.name == book2.name){
                book1.quantity += book2.quantity;
                cout << "���μ�¼��֮ǰ���ۼ�¼�ϲ�" << endl;
            }else{
                cout << "ǰһ����Ϊ:"<< book1.name <<"ǰһ��������Ϊ��:" << book1.quantity << endl;
                book1.name = book2.name;
                book1.quantity = book2.quantity;
            }
        }
        cout << "���һ��������Ϊ:"  << book1.quantity << endl;
    }else{
        cerr << "����û������" << endl;
    }
//Sales_data.h �ļ�����
struct Sales_data{
    std::string name;
    int quantity = 0;
    double jiaqian = 0.0;
    std::ifstream &read(std::ifstream &in){
        in >> name;
        in >> quantity;
        in >> jiaqian;
        return in;
    }
};



    //8.5
    ifstream in("data.txt");
    vector<string> strs;
    if (in){
        for(string stra;in >> stra;)
            strs.push_back(stra);
    }
    cout << strs[0] << strs[1] << strs[2] <<endl;


    //8.4
    ifstream in("data.txt");
    vector<string> strs;
    string stra;
    if (in){
        in >> stra;
        strs.push_back(stra);
    }
    cout << strs[0] <<endl;
    //�򿪸�ʽ��֪��utf����   ������������. �ǵü���ͷ�ļ�


    //8.3
    //�������ͺ�i���Ͳ�һ��ʱ, 2.�ļ�����ʱ.    3.ϵͳ����δ֪����ʱ.


    //8.1 8.2
istream &print(istream &in){
    string stra;
    while (getline(in, stra))
        cout << stra;
    in.clear();
    return in;
}
int main()
{
    print(cin);

}
*/
