#include <iostream>
#include <cstdio>
#include "Sales_item.h"

using namespace std;

int main()
{   //1.25 抄一遍
    Sales_item book, book1;
    if (std::cin >> book){
        while (std::cin >> book1){
            if (book.isbn() == book1.isbn()){
                book += book1;
            }else{
                cin << book << endl;
                book = book1;
            }
        }
        cin << book << endl;
    }
}
/*{
    //练习1.23 1.24
    //第一章节 所学东西太少 只能写暴力的if else 本人这方案前三记录必须不一样可以 添加if判定是否一样懒得再加 想着网上找
    //看一个博客写system() 和compareIsbn() 函数的笑出了声 感觉就像初中生写小学生数学作业 为了证明啥? 关键复制跑了一遍还两个错误 我肚子疼定义都没定义.... https://blog.csdn.net/weixin_37870514/article/details/78139248?locationNum=6&fps=1
    //另一个博客.写了个排序计数遇到新记录输出之前记录数目 然后覆盖掉 顺序一乱记不了数 答案不是多好.关键是抄了1.6章节的例子嗯.......还行23333  https://blog.csdn.net/u011392050/article/details/55803208
    Sales_item book, book1, book2, book3;
    std::cin >> book1 >> book2 >> book3;
    int i1 = 1, i2 = 1, i3 = 1;
    while (cin >> book){
    if (book.isbn() == book1.isbn()){
        ++i1;
        cout << "book id:" << book1.isbn() << "\tnum:" << i1 << endl;
    }
    if (book.isbn() == book2.isbn()){
        ++i2;
        cout << "book id:" << book2.isbn() << "\tnum:" << i2 << endl;
    }
    if (book.isbn() == book3.isbn()){
        ++i3;
        cout << "book id:" << book3.isbn() << "\tnum:" << i3 << endl;
    }
    }
    //练习1.22
    Sales_item book,book2,book3;
    std::cin >> book;
    book3 += book;
    while (cin >> book2){
        if (book == book2)
            book3 += book2;
    }
    std::cout << book3 << endl;
    return 0;
    //练习1.21
    Sales_item book;
    Sales_item book2;
    std::cin >> book;
    while (cin >> book2){
        if (book == book2)
            std::cout << book + book2 << endl;
    }
    return 0;
    //练习1.20
    Sales_item book;
    while (cin >> book)
        std::cout << book << endl;
    return 0;
    练习1.19
    int sum = 0, v1 = 0, v2 = 0;
    std:;cin >> v1 >> v2;
    if (v1 > v2)
        cout << "no" << endl;
    else {
        while (v1 <= v2){
            sum += v1;
            ++v1;
        }
    std::cout << sum << endl;
	}
	return 0;
    //例1.4.4
    int int1 = 0, int2 = 0;
    if (cin >> int1){
        int len = 1;
        while (cin >> int2){
            if (int1 == int2)
                ++len;
            else {
                cout << "out:" << int1 << "no" << len << endl;
                int1 = int2;
                len = 1;
            }
        }
        cout << "out:" << int1 << "no" << len << endl;
    }
    return 0;
    例1.4.3
    int sum = 0, value = 0;
    while (std::cin >> value)
        sum += value;
    std::cout << "out:" << sum << endl;
    return 0;
    例1.4.2
    int sum = 0;
    int val = 0, vmax = 0;
    for (cin >> val >> vmax;val <= vmax; ++val)
        sum += val;
    std::cout << "Êä³öÖµ" << sum << endl;
	return 0;
    int sum = 0, v1 = 0, v2 = 0;
    std:;cin >> v1 >> v2;
	while (v1 <= v2){
		sum += v1;
		++v1;
	}
	std::cout << sum << endl;
	return 0;
    std::cout << "Hello world!" << endl;
    int a = 0, b = 0;
    std::cout << "lala " << a
        << "and" << b
        << "is" << a*b << std::endl;
    return 0;
}
*/
