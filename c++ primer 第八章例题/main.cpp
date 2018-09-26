#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //单个字符判断(是否是符号 数字 标点 字母啊 什么的.)函数的库
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数
#include <fstream>  //文件IO
#include <sstream>  //stringIO

#include "Sales_data.h"

using namespace std;

struct PersonInfo{
    string name;
    vector<string> phones;
};

int main()
{
    //定义后在添加内容不就完了? 对了要及时清空缓存
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
    什么么设置 常量 auto 引用
    设置常量是因为 引用在循环中引用不会修改.
    引用不会进行拷贝节省内存
    至于为什么是auto 节省写类型时间把..


    //8.13
        //定义后在添加内容不就完了? 对了要及时清空缓存
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
    这是一个简单的类, 他的初始值都是需要进行输入 没有指针引用等不能为空成员.


    //8.11
    //定义后在添加内容不就完了? 对了要及时清空缓存
    ifstream in("data.txt");
    string line, word;
    istringstream record;
    vector<PersonInfo> people;	//保存实例也就是 通讯录
    while (getline(in, line)){		//输入每行给line
        PersonInfo info;			//通讯人实例info
        record.str(line);
        record >> info.name;		//用string流传入第一个string
        while (record >> word)	//如果string流还能传递则继续
            cout << word;	//把之后的电话string都添加到phones容器里
        people.push_back(info);	//把当前通讯人保存到容器里.
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
        instr >> stra;  //试了一下不能直接输入和输出流对接..
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
                out << "本次记录和之前销售记录合并" << endl;
            }else{
                out << "前一本名为:"<< book1.name <<"前一本销售量为共:" << book1.quantity << endl;
                book1.name = book2.name;
                book1.quantity = book2.quantity;
            }
        }
        out << "最后一本销售量为:"  << book1.quantity << endl;
    }else{
        cerr << "错误没有数据" << endl;
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
