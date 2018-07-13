#include <iostream>

using namespace std;
int main()
{
    //2.30

    cout << " " << endl;
    return 0;
}

/*
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
