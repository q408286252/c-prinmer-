#include <iostream>

using namespace std;
int i = 42;
int main()
{
    //2.12
   int i, &ri = i;
   i = 5; ri = 10;
    cout << i << " " << ri << endl;
    return 0;
}

/*
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
