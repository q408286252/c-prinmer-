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
    std::cout << "��������:";
    std::cin >> item.name;
    std::cout << "�����ַ:";
    std::cin >> item.address;
}

void print( const Person &item)
{
    std::cout<< "������:" << item.name
        << "\n��ַΪ:" << item.address;
}
