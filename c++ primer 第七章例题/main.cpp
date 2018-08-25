#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //包含单个字母数字判断函数   就是isalnum()这类判断数字还是标点字符来着
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数

#include "Sales_data.h"
#include "Person.h"

using namespace std;    //所有命名空间都加载到默认关键字里 个人懒这个不是特别推荐

int main()
{
    /*
    Sales_data book1, book2;
    if (book1.read(book1)){
        while(book2.read(book2)){
            if (book1.isbn() == book2.isbn()){  //判断书本的编号是否一样
                book1.combine(book2);
                print(book1);
            }else{
                cout << "上本书记录:" << endl;
                print(book1);
                cout << "\n 新书记录已覆盖上本书的记录" << endl;
                book1.name = book2.name;
                book1.quantity = book2.quantity;
                book1.price = book2.price;

            }
        }
        print(book1);
    }else{
        cerr << "错误没有数据" << endl;
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
    说实话本书显示的初始化和 隐式的初始化没解释清楚
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
            beg:    //因为第一次默认输入实例会自动调用read函数不需要再进行一次while 我就使用了跳转.
            if (book1.isbn() == book2.isbn()){  //判断书本的编号是否一样
                book1.combine(book2);
                print(book1);
            }else{
                cout << "上本书记录:" << endl;
                print(book1);
                cout << "\n 新书记录已覆盖上本书的记录" << endl;
                book1.name = book2.name;
                book1.quantity = book2.quantity;
                book1.price = book2.price;

            }
        }
        print(book1);
    }else{
        cerr << "错误没有数据" << endl;
    }


    //7.12
    这题有问题之前定义的read函数是在 类外. 现在也没学如何在类里面调用类外函数.
    难道要在函数形参里传指针? 我这里吧read函数移动到类里了.
struct Sales_data{
    Sales_data()	//名称必须与类名称相同, 没有返回类型和返回值
	{
        read( *this); //read函数的作用是从is中读取一条信息放入this对象中.
	}

    std::string name ;
    std::string bookno;
    int quantity = 0;
    double price = 0.0;
    double fee = 0.0;


    bool read( Sales_data &item)
    {
        double sum = 0;
        std::cout << "输入书名:";
        std::cin >> item.name;
        std::cout << "输入销售数量:";
        std::cin >> item.quantity;
        std::cout << "输入单价:";
        std::cin >> item.price;
        item.fee = item.price *  item.quantity;
        //写入bookno省略了.
        return 1;
    }
};


    //7.11
//主文件
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
    给read函数传入cin和data1类实例 返回的内容给外层read函数的第一个形参 第二个形参 传入data2类实例 最后查看这个函数返回内容是否为0或空.

    //7.9
struct Person{
    std::string name;
    std::string addrees;
};

void read( Sales_data &item)
{
    double sum = 0;
    std::cout << "输入姓名:";
    std::cin >> item.name;
    std::cout << "输入地址:";
    std::cin >> item.address;
}

void print (Person &ip)
{
        std::cout << "\n名字是:" << ip.name
        << "\n地址为:" << ip.addrees;
}

    //7.8
    因为print 函数是只是调用然后显示, 并不修改内容
    而read 要写入内容不能使用const;



    //7.7
int main()
{
    Sales_data book1, book2;
    if (read(book1)){
        while(read(book2)){
            if (book1.isbn() == book2.isbn()){  //判断书本的编号是否一样
                book1.combine(book2);
                print(book1);
            }else{
                cout << "上本书记录:" << endl;
                print(book1);
                cout << "\n 新书记录已覆盖上本书的记录" << endl;
                book1.name = book2.name;
                book1.bookno = book2.bookno;
                book1.quantity = book2.quantity;
                book1.price = book2.price;
            }
        }
        print(book1);
    }else{
        cerr << "错误没有数据" << endl;
    }
}

    //7.6
    //传入cin 和 类实例 写入实例数据 返回cin
bool read( Sales_data &item)
{
    double sum = 0;
    std::cout << "输入书名:";
    std::cin >> item.name;
    std::cout << "输入销售数量:";
    std::cin >> item.quantity;
    std::cout << "输入单价:";
    std::cin >> item.price;
    item.fee = item.price *  item.quantity;
    return 1;
}

//类实例1数据给 例3 然后把例2数据和例3数据叠加
Sales_data &add(const Sales_data &book1, const Sales_data &book2)
{
    Sales_data book3 = book1;
    book3.combine(book2);
    return book3;
}

//输出 类实例的信息
void print( const Sales_data &item)
{
    std::cout << "书的编号为:" << item.bookno
        << "\n书的名字是:" << item.name
        << "\n已销售数量:" << item.quantity
        << "\n价格:"  << item.price
        << "\n本书销售金额:" << item.fee;
}


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
