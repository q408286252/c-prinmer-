//Sales_data.h ÎÄ¼şÄÚÈİ
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

