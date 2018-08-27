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

void read( Person &item)
{
    std::cout << "输入姓名:";
    std::cin >> item.name;
    std::cout << "输入地址:";
    std::cin >> item.address;
}

void print( const Person &item)
{
    std::cout<< "名字是:" << item.name
        << "\n地址为:" << item.address;
}
