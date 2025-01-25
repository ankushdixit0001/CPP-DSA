#include<iostream>
using namespace std;
class animal{
    public:
    void eat(){
        cout<<"eats\n";
    }
    void breath(){
        cout<<"breath\n";
    }
};
class bird : public animal{
    public:
    void fly(){
    cout<<"fly";
    }
};
class Fish : public animal{
    public:
    void swim(){
        cout<<"swim\n";
    }
};
int main() {
    bird b1;
    Fish f1;
    b1.eat();
    f1.breath();

    return 0;
}
