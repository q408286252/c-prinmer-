class Example{
public:
    Example() : vec(10){};
    //static double rate = 6.5;   //���� ��Ϊ�������治��const constexpr�Ⱦ�ֱ�Ӷ���ֵ;
    static double rate;
    static const int vecSize = 20;
    //static vector<double> vec(vecSize); //����vector ��Ҫ�����������ܷ���
    //static constexpr std::vector<double> vec(50); ��������Ҳ����
    std::vector<double> vec;  //��������д��������ȷ....
};
