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
