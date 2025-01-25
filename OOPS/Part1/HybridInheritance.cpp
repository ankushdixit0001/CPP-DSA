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
class mamal : public animal{
    public:
    string bloodtype;
    mamal(){
        bloodtype = "worm\n";
    }
};
class dog : public mamal{
    public:
    void tailwing(){
        cout<<"a dog wing its tail.\n";
    }
};
class bird : public animal{
    public:
    void fly(){
    cout<<"fly\n";
    }
};
int main() {
    dog d1;
    d1.eat();
    d1.tailwing();
    cout<<d1.bloodtype; 
    bird f1;
    f1.fly();
    f1.breath();
    return 0;
}
