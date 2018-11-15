#include <iostream> //输入输出流
#include <string>   //字符串文件
#include <vector>   //容纳对象的容器 俗称列表


using namespace std;    //所有命名空间都加载到默认关键字里 个人懒这个不是特别推荐

int main()
{

}

/*  //2.6.2
        Sales_data data1, data2;
    double price = 0;
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    std:;cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;
    if ( data1.bookNo == data2.bookNo){
        std::cout << data1.revenue + data2.revenue << endl;
    } else {
        std::cout << "书的ID不一致" << endl;
    }

    //2.40
    struct lala{
        std::string balabala;
        int bana = 0;
        char boom = "1";
    };

    //2.38
    int a =3, &b = a;
    const int c = a;
    decltype(c) e = c;  //和 auto e = c; 不一样
    e= 5;
    cout << a << endl;
    return 0;

    //2.36
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;
    cout << a<<b<< c<<d << endl;

    //2.33
    int i = 0, &r = i;
    const int ci = i, &cr = ci;
    auto a = r;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;

    //2.32
     不合法
     int null = 0, *p = &null;

    //2.31
    int i = 0;              //i变量 v2常量 v1变量
    const int v2 = 0;       //p1指针指向变量  p2指针指向常量 p3定值指针指向定值i=3
    int v1 = v2;            //r1变量  r2常量
    int *p1 = &v1, &r1 = v1;
    const int *p2 = &v2, *const p3 = &i, &r2 = v2;
    r1 =v2;         //对
    p1 = p2;        //错普通指针不可指向常量
    p2 = p1;        //对 指向定死,但内容可覆盖
    p1 = p3;        //错 p3内容 指向都定死 必须p1也为常量指针
    p2 = p3;        //对 p2指向定死 p3内容 指向定死

    //2.29
			int i;
			const int ic = 5;
			int *pl;
			int *const p2 = &i;
			const int *const p3 = &i;
			i = ic;
			p1 = p3;    	//错 p3为常量指引也是常量内容 不可被非常量指针指引
			p1 = &ic;		//错 常量变量 不可以被 非常量指针指引
			p3 = &ic;		//错 p3内容和指针都固定死无法赋予新值
			p2 = p1;		//错 p2内容固定死了  无法赋予新值
			ic = *p3;		//错 ic为定值 无法赋予新值
    cout << " " << endl;
    return 0;

    //2.20
    int i = 42;
    int *p = &i;
    *p = *p * *p;
    cout << i << endl;
    return 0;

    //2.9
    int i;
    std::cin >> i ;
    int ii = {3.14};
    double s = 3.14, b = s;
    int iii = 3.14;
    return 0;

    //2.8
    cout << "2M\n" << endl;
    cout << "2\tM\n" << endl;
    return 0;

    //2.6
    int i = 09; //´íÎó
    return 0;

    //2.3
    unsigned u = 10, u2 = 42;
    int i = 10, i2 =42;
    std::cout << i - u << endl;
    std::cout << u - i << endl;
    return 0;
*/
