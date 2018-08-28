class Screen{
public:
    Screen() = default;
    Screen(std::string::size_type h, std::string::size_type w) : height(h), width(w), contents("aaaaaaaaaabbbbbbbbbbcccccccccc") {}
    Screen(std::string::size_type h, std::string::size_type w, std::string s)
            : height(h), width(w){}
    Screen(std::string::size_type h, std::string::size_type w, char s,std::string ss)
            : height(h), width(w), st(s), contents(ss){}

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

