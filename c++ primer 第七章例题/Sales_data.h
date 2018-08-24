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
        return bookno;
    }

};


struct Person{
    std::string name;
    std::string addrees;
    std::string namedef() const {};
    std::string addressdef() {};
};
