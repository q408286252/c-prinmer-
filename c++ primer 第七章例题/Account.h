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

