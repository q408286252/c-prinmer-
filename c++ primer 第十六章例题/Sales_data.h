#include <iostream>
#include <string>

class Sales_data{
friend Sales_data add(const Sales_data&, const Sales_data&);
friend void print(const Sales_data&);
friend bool read(Sales_data&);
public:
    Sales_data(std::string s, int n, double p)
			:name(s), quantity(n), price(p), fee(p*n){}
    Sales_data(): Sales_data("",0,0.0){}
    Sales_data(std::string s): Sales_data(s,0,0){}
    Sales_data(std::istream &is):Sales_data("",0,0){ read(*this);}
    Sales_data(double p) : Sales_data("",0,p){}
    Sales_data(int n) : Sales_data("",n,0) {}

    Sales_data &combine(const Sales_data &ip)
    {
        quantity += ip.quantity;
        fee += ip.fee;
        return *this;
    }

    std::string isbn() const{return name;}

private:
    inline
    double avg_price() const { return quantity ? fee/quantity : 0;}

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



