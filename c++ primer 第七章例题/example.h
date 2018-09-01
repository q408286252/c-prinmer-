class Example{
public:
    Example() : vec(10){};
    //static double rate = 6.5;   //错误 因为在类里面不加const constexpr等就直接定义值;
    static double rate;
    static const int vecSize = 20;
    //static vector<double> vec(vecSize); //错误vector 需要加载域名才能访问
    //static constexpr std::vector<double> vec(50); 很奇怪这个也报错
    std::vector<double> vec;  //容量数不写内容则正确....
};
