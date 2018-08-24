#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //包含单个字母数字判断函数   就是isalnum()这类判断数字还是标点字符来着
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数

#include "Sales_data.h"

using namespace std;    //所有命名空间都加载到默认关键字里 个人懒这个不是特别推荐


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
                cout << "前一本名为:"<< book1.name <<"前一本销售量为共:" << book1.quantity << endl;
                book1.name = book2.name;
                book1.quantity = book2.quantity;
            }
        }
        cout << "前一本销售量为:"  << book1.quantity << endl;
    }else{
        cerr << "错误没有数据" << endl;
    }
}

/*
    //7.5
    std::string namedef() const {};
    std::string addressdef() {};    //姓名改为const 而地址不要常量. 地址可能会变而姓名不会


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
                cout << "前一本名为:"<< book1.name <<"前一本销售量为共:" << book1.quantity << endl;
                book1.name = book2.name;
                book1.quantity = book2.quantity;
            }
        }
        cout << "前一本销售量为:"  << book1.quantity << endl;
    }else{
        cerr << "错误没有数据" << endl;
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
        cerr << "错误没有数据" << endl;
    }

};


    //7.1
//主运行文件内容
#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //包含单个字母数字判断函数   就是isalnum()这类判断数字还是标点字符来着
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数

#include "Sales_data.h"

using namespace std;    //所有命名空间都加载到默认关键字里 个人懒这个不是特别推荐

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
                cout << "本次记录和之前销售记录合并" << endl;
            }else{
                cout << "前一本名为:"<< book1.name <<"前一本销售量为共:" << book1.quantity << endl;
                book1.name = book2.name;
                book1.quantity = book2.quantity;
            }
        }
        cout << "前一本销售量为:"  << book1.quantity << endl;
    }else{
        cerr << "错误没有数据" << endl;
    }
}

//Sales_data.h 文件内容
struct Sales_data{
    std::string name;
    int quantity = 0;
    double jiaqian = 0.0;
};
*/
