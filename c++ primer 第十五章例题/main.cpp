#include <iostream>

using namespace std;
class A{
public:
    virtual print(){
        cout << "������A";
    }
};
class B :public A{
public:
    print(){
        cout << "������B";
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
