#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //单个字符判断(是否是符号 数字 标点 字母啊 什么的.)函数的库
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数
#include <fstream>  //文件IO

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
                cout << "本次记录和之前销售记录合并" << endl;
            }else{
                cout << "前一本名为:"<< book1.name <<"前一本销售量为共:" << book1.quantity << endl;
                book1.name = book2.name;
                book1.quantity = book2.quantity;
            }
        }
        cout << "最后一本销售量为:"  << book1.quantity << endl;
    }else{
        cerr << "错误没有数据" << endl;
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
                cout << "本次记录和之前销售记录合并" << endl;
            }else{
                cout << "前一本名为:"<< book1.name <<"前一本销售量为共:" << book1.quantity << endl;
                book1.name = book2.name;
                book1.quantity = book2.quantity;
            }
        }
        cout << "最后一本销售量为:"  << book1.quantity << endl;
    }else{
        cerr << "错误没有数据" << endl;
    }
//Sales_data.h 文件内容
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
    //打开格式不知道utf在哪   导致中文乱码. 记得加载头文件


    //8.3
    //输入类型和i类型不一致时, 2.文件结束时.    3.系统级别未知错误时.


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
