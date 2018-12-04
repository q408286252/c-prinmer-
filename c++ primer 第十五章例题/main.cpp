#include <iostream>

using namespace std;
class A{
public:
    virtual print(){
        cout << "运行了A";
    }
};
class B :public A{
public:
    print(){
        cout << "运行了B";
    }
};

void f(A &a){
    a.print();
}

int main(){
    A a;
    B b;
    f(b);

}
