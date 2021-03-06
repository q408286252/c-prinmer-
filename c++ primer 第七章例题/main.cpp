#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <cctype>   //单个字符判断(是否是符号 数字 标点 字母啊 什么的.)函数的库
#include <vector>   //容纳对象的容器 俗称列表
#include <cstring>  //提供C语言标准库的一些函数

//#include "Sales_item.h"
//#include "Sales_data.h"
//#include "Person.h"
//#include "Screen.h"
//#include "Account.h"
#include "example.h"

using namespace std;    //所有命名空间都加载到默认关键字里 个人懒这个不是特别推荐

int main()
{

}


/*
class Debug{
public:
    constexpr Debug(bool b = false):sz(b), io(b), of(b){}

    constexpr bool onoff() { return sz||io||of;}
    void set_sz(bool b){ sz = b;}
    void set_io(bool b){ io = b;}
    void set_of(bool b){ of = b;}
    bool sz,io,of;
};
*/

/*
class NoDefault{
public:
    NoDefault(int i):in(i){ cout<<"运行了No--";}
private:
    int in;
};
class C{
public:
    C(int i): obj1(i){ cout<<"运行了C--";}
    C():C(0){}
    NoDefault obj1;
};

struct Sales_data{
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
*/

/*
typedef string Type;    //string类型起了别名Type
Type initVal();         //声明string返回的initval函数
class Exercise{
public:
    typedef double Type;    //double类型起了别名Type;
    Type setVal(Type);      //声明double返回类型的函数 setVal形参double
    Type initVal();         //声明double返回类型的函数 initVal;
private:
    int val;
};
//错误声明与 定义返回的函数类型不一致,       形参类型也不一致
Exercise::Type Exercise::setVal(Exercise::Type parm){
    val = parm + initVal(); //调用类成员initVal时 发现未定义   还有val是int类型 而parm和initVal返回都是浮点型 运算会有损失
    return val;
}
Exercise::Type Exercise::initVal(){ return 3.14;}   //补上函数
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

    /*
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
                book1 = book2;

            }
        }
        print(book1);
    }else{
        cerr << "错误没有数据" << endl;
    }
    */












/*
class Example{
public:
    //static double rate = 6.5;   //错误 因为在类里面不加const constexpr等就直接定义值;
    static double rate;
    static const int vecSize = 20;
    std::vector<double> vec();
    //static vector<double> vec(vecSize); //错误vector 需要加载域名才能访问
    //static constexpr std::vector<double> vec(50); 很奇怪这个也报错
    std::vector<double> vec();  //容量数不写内容则正确....
};
#include "example.h"
    double Example::rate;
    //vector<double> Example::vec;  //没加std 且 之前声明过了重复声明

    //7.57
    //Account.h文件
class Account{
public:
    int read(int = bookno);
    int bookna = bookno;
private:
    static const int bookno = 30;
    //  static Bar book;  错误 很奇怪 我的编译器不支持 静态变量写成未定义类型.
};
int Account::read(int inta){
    return inta*inta;
}
主文件
#include "Account.h"
int main()
{
    Account acca;
    //cout << acca.read() << endl;
    cout << acca.bookna << endl;
    cout << acca.read() << endl;
}

    //7.56
    //类的静态成员是 在实例和调用完毕的过程中一直存在的变量.
    //优点:通用性; 不删除性; 易修改;
    //区别:普通成员调用实例时每次参数可能不一样, 而静态变量是保持一致的.
    如果不调用实例 是无法访问成员的 二静态变量可以随时访问它;


    //7.55
    不是,
    没有constexpr 函数,
    没有默认的构造函数,


    //7.54
    不能,因为 那些set开头的修改了 成员值 这在constexpr是不允许的 且 还没有返回.


    //7.53
class Debug{
public:
    constexpr Debug(bool b = false):sz(b), io(b), of(b){}

    constexpr bool onoff() { return sz||io||of;}
    void set_sz(bool b){ sz = b;}
    void set_io(bool b){ io = b;}
    void set_of(bool b){ of = b;}
    bool sz,io,of;
};



    //7.52
struct Sales_data{
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
Sales_data sa = {"978-0590353403",25,15.99};




    //7.51
    为什么容器是 而string不是很简单.
    容器的类型固定死了 在声明的时候就要输入类型. 如果变换了类型报错是肯定的.
    string不是 因为他本身的 保存对象是 字符串字符串本身就需要转换类型
    至于为什么const char*不行 因为他是常量啊!


    //7.50
    Person(const std::string &s,const std::string &sa):name(s), address(s){}
    Person():Person("",""){}
    explicit Person(const std::string &s):Person(s,""){}


    //7.49
    Sales_data item;
    string  s = "0";
    item.combine(s);
    print(item);
    //首先如果构造函数 Sales_data(std::string s): name(s){} 加入了explicit不管怎么改combine函数形参都是报错
    //如果是Sales_data &combine(Sales_data);会在函数里生成一个一模一样实例进行运算
    //Sales_data &combine(Sales_data &);这个我会报错因为我的add函数引用它运算 参数是常量,常量不能普通引用导致报错
    //Sales_data &combine(const Sales_data &ip); 和第一个声明结果一样. 但是他是常量更稳定些.


    //7.48
    string null_isbn("9-999-99999-9");
    Sales_data item1(null_isbn);    //创建item1实例name参数为9-999-99999-9
    Sales_data item2("9-999-99999-9");  //创建item2实例name参数为9-999-99999-9
    就算写了explicit还是能创建  我还以为字符串的不行呢....


    //7.47
    应该. 因为需要使用实例时 都是些完整的名称(形参)
    如果编写错误而被完美调用了. 那么说明此程序的运行和编译者的想法不一致...


    //7.46
    a 不正确, 构造函数可以没有.编译器会自己添加.
    b 错误 默认构造函数参数可以空也可以输入默认值,
    c 错  如果构造函数写了不设置默认的 你不输入参数就会报错.
    d 对


    //7.45
    合法. 因为C类有默认构造函数啊. 顺便说一下 这个容器一下子定义了10次C和10次Nodefault

    //7.44
    不合法 因为 容器默认初始化10个Nodefault类
    但Nodefault类没有默认构造函数. 会报错.
    给Nodefault类添加一行默认构造函数就行.
    NoDefault():NoDefault(0){}


    //7.43
class NoDefault{
public:
    NoDefault(int i):in(i){ cout<<"运行了No--";}
private:
    int in;
};
class C{
public:
    C(int i): obj1(i){ cout<<"运行了C--";}
    C():C(0){}
    NoDefault obj1;
};

int main()
{
    C c;
}


    //7.42
class Book{
public:
    Book(int i,std::string s, double is, std::string n, double isz, unsigned cnt, double f)
            :bookno(i), name(s), fee(is), date(n), price(isz), sales(cnt), amount(f){}
    Book():Book(0,"",0.0,"0000-00-00",0.0,0,0.0){}
private:
    int bookno;
    std::string name,date;
    unsigned sales;
    double fee,price,amount;
};
//又丑又长. 随叫你取了那么多变量..

    //7.41
    Sales_data(std::string s, int n, double p)
			:name(s), quantity(n), price(p), fee(p*n){ std::cout<<"完整构造--";}
    Sales_data(): Sales_data("",0,0.0){ std::cout<<"默认--";}
    Sales_data(std::string s): Sales_data(s,0,0){ std::cout<<"string--";}
    Sales_data(std::istream &is):Sales_data("",0,0){ std::cout<<"cout--"; read(*this);}
    Sales_data(double p) : Sales_data("",0,p){ std::cout<<"小数--";}
    Sales_data(int n) : Sales_data("",n,0) {std::cout<<"整数--";}
    //对构造函数进行了修改 注意默认函数不能再
    Sales_data s1;
    Sales_data s2("lala");
    Sales_data s3(3.14);
    Sales_data s5(40);
    Sales_data s4(std::cin);
    //测试的调用

    //7.40
    Book类 需要 编号 名称 参考价 出版年份 书店售价 销量 本书销售额
    Book(int i,std::string s, double is, std::string n, double isz, unsigned cnt, double f)
            :bookno(i), name(s), fee(is), date(n), price(isz), sales(cnt), amount(f){}

    //7.39
    不合法
    因为构造函数都设置默认实参就定义成了默认构造函数
    两个默认构造函数肯定一个不对那么到底哪个是默认构造函数?


    //7.38
Sales_data(istream &in= std::cin){}


    //7.37
Sales_data first_item(cin); //调用了Sales_data(std::istream &is){ read(*this);} 略有修改 然后默认调用了read成员函数
int main(){
    Sales_data next;    //调用了 Sales_data(std::string s=""): name(s){}
    Sales_data last("9-999-99999-9"); //调用了Sales_data(std::string s=""): name(s){} 但s的值被修改成"9-999-99999-9"


    //7.36
struct X{
    X(int i, int j):base(i), rem(i %j){} //构造函数先初始化rem 后base 导致rem未初始化 修改rem的初始值就行
    int rem, base;
};


    //7.35
typedef string Type;    //string类型起了别名Type
Type initVal();         //声明string返回的initval函数
class Exercise{
public:
    typedef double Type;    //double类型起了别名Type;
    Type setVal(Type);      //声明double返回类型的函数 setVal形参double
    Type initVal();         //声明double返回类型的函数 initVal;
private:
    int val;
};
//错误声明与 定义返回的函数类型不一致,       形参类型也不一致
Exercise::Type Exercise::setVal(Exercise::Type parm){
    val = parm + initVal(); //调用类成员initVal时 发现未定义   还有val是int类型 而parm和initVal返回都是浮点型 运算会有损失
    return val;
}
Exercise::Type Exercise::initVal(){ return 3.14;}   //补上函数


    //7.34
    会报错 因为编译器在类目前已编译成员没找到pos 在全局也没找到.



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
//已修改  例题书写错误 返回类型必须要写作用域.

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
    增加了思维复杂度? 要考虑this 还要考虑函数指针是不是常量  如果调用函数一个常量指针一个非常量还会报错.
    优点,连续的调用在理解后 行云流水 不需要用过多的行来表达一个意思.

    //7.29
    正确


    //7.28
    答第一行输出的是修改了的内容
    第二行表达式输出的是未修改前的实例内容


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
    不能,因为默认的行和 宽是0;


    //7.23 7.24
    //这节的例子非常经典. 我给满分 吧之前不懂的全弄懂了. 可能之前的有错懒得改了..=.=
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
已修改
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
    //写入bookno省略了.
    return 1;
    }

//类实例1数据给 例3 然后把例2数据和例3数据叠加
Sales_data add(const Sales_data &book1, const Sales_data &book2)
{
    Sales_data book3 = book1;
    book3.combine(book2);
    return book3;
}

//输出 类实例的信息
void print( const Sales_data &item)
{
    std::cout<< "书的名字是:" << item.name
        << "\n已销售数量:" << item.quantity
        << "\n价格:"  << item.price
        << "\n本书销售金额:" << item.fee;
}



    //7.20
    友元很好的让外部函数能够控制的使用修改隐式成员,
    弊端有类成员里面是无法调用 定义的函数的,


    //7.19
class Person{
public:
    Person() = default;
    Person(const std::string &s,const std::string &sa):name(s), addrees(s){}
private:
    std::string name;
    std::string addrees;
};
//吧成员的一些需要编写的保存内容封装了, 因为如果需要修改可以调用函数,而不是直接在成员上修改,

    //7.18
    封装就是隐藏不可显示内容.
    有些关键成员作用域控制的变量, 如果被外部修改了后果很严重,
    能封装不对外调用有者很大的安全性.


    //7.17
    有区别,
    class类相当于 类体第一行写了private:
    struct类相当于 类体第一行写了public:


    //7.16
    次数没有 位置有只要在类以内就行,
    public之后定义的都是要被外部调用的成员
    private之后定义的都是只在类内部使用的成员;


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
