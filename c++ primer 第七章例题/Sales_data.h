#include <iostream>
#include <string>

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
    inline
    double avg_price() const { return quantity ? fee/quantity : 0;}
    std::string name ;
    int quantity = 0;
    double price = 0.0;
    double fee = 0.0;
};

//����cin �� ��ʵ�� д��ʵ������ ����cin
bool read( Sales_data &item)
{
    double sum = 0;
    std::cout << "��������:";
    std::cin >> item.name;
    std::cout << "������������:";
    std::cin >> item.quantity;
    std::cout << "���뵥��:";
    std::cin >> item.price;
    item.fee = item.price *  item.quantity;
    //д��booknoʡ����.
    return 1;
    }

//��ʵ��1���ݸ� ��3 Ȼ�����2���ݺ���3���ݵ���
Sales_data add(const Sales_data &book1, const Sales_data &book2)
{
    Sales_data book3 = book1;
    book3.combine(book2);
    return book3;
}

//��� ��ʵ������Ϣ
void print( const Sales_data &item)
{
    std::cout<< "���������:" << item.name
        << "\n����������:" << item.quantity
        << "\n�۸�:"  << item.price
        << "\n�������۽��:" << item.fee;
}


