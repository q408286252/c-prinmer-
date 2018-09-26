#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //�����ַ��ж�(�Ƿ��Ƿ��� ���� ��� ��ĸ�� ʲô��.)�����Ŀ�
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����
#include <fstream>  //�ļ�IO
#include <sstream>  //stringIO

#include "Sales_data.h"

using namespace std;

struct PersonInfo{
    string name;
    vector<string> phones;
};

int main()
{
    //�������������ݲ�������? ����Ҫ��ʱ��ջ���
    ifstream in("in.txt");
    string strl;
    while (getline(in, &strl)){
        ostringstream strout, strcerr;
        for (const auto &str : strl){
            strout << str;
        }
        if (strout.str().empty())
            cout << strout.str() << endl;
        else
            cerr << strout.str() << endl;
    }

}


/*



    //8.14
    ʲôô���� ���� auto ����
    ���ó�������Ϊ ������ѭ�������ò����޸�.
    ���ò�����п�����ʡ�ڴ�
    ����Ϊʲô��auto ��ʡд����ʱ���..


    //8.13
        //�������������ݲ�������? ����Ҫ��ʱ��ջ���
    ifstream in("in.txt");
    string strl;
    while (getline(in, strl)){
        ostringstream strout, strcerr;
        for (const auto &str : strl){
            strout << str;
        }
        if (strout.str().empty())
            cout << strout.str() << endl;
        else
            cerr << strout.str() << endl;
    }


    //8.12
    ����һ���򵥵���, ���ĳ�ʼֵ������Ҫ�������� û��ָ�����õȲ���Ϊ�ճ�Ա.


    //8.11
    //�������������ݲ�������? ����Ҫ��ʱ��ջ���
    ifstream in("data.txt");
    string line, word;
    istringstream record;
    vector<PersonInfo> people;	//����ʵ��Ҳ���� ͨѶ¼
    while (getline(in, line)){		//����ÿ�и�line
        PersonInfo info;			//ͨѶ��ʵ��info
        record.str(line);
        record >> info.name;		//��string�������һ��string
        while (record >> word)	//���string�����ܴ��������
            cout << word;	//��֮��ĵ绰string����ӵ�phones������
        people.push_back(info);	//�ѵ�ǰͨѶ�˱��浽������.
        record.clear();
    }


    //8.10
    string stra;
    vector<string> strs;
    ifstream in("data.txt");
    while (getline(in, stra)){
        strs.push_back(stra);
    }
    for (auto p= strs.begin(); p != strs.end(); ++p){
        istringstream instr(*p);
        instr >> stra;  //����һ�²���ֱ�������������Խ�..
        cout << stra;
        instr.clear();
    }


    //8.9
istream &print(istream &in){
    string stra, strb;
    while (getline(in, stra)){
        istringstream strin(stra);
        while (strin >> strb)
            cout << strb;
        strin.clear();
    }
    in.clear();
    return in;
}

int main()
{

    print(cin);

}


    //8.7  8.8
    ifstream in("data.txt");
    ofstream out("out.txt", ofstream::app);
    Sales_data book1, book2;
    if ( in.good() ){
        book1.read(in);
        while ( in.good() ){
            book2.read(in);
            in.close();
            if (book1.name == book2.name){
                book1.quantity += book2.quantity;
                out << "���μ�¼��֮ǰ���ۼ�¼�ϲ�" << endl;
            }else{
                out << "ǰһ����Ϊ:"<< book1.name <<"ǰһ��������Ϊ��:" << book1.quantity << endl;
                book1.name = book2.name;
                book1.quantity = book2.quantity;
            }
        }
        out << "���һ��������Ϊ:"  << book1.quantity << endl;
    }else{
        cerr << "����û������" << endl;
    }


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
    while (in){
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
