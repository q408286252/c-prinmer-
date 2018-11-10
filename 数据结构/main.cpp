#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define pi 3.14159

class base{
private:
    int x,y;
    static int aa;
public:
    base(int i,int j){x=i; y=j;}
    void get(){cout<<x << y;}
    void a(){cout << aa;};
};

int base::aa = 50;
int main(){
    int b =21,m=0;
    switch (int(1)){
        case 0: m++; break;
        case 1: m++;
                switch(b%3){
                    case 0:m;
                    case 1:m++;break;
                }
    }
    cout << m << endl;
}
