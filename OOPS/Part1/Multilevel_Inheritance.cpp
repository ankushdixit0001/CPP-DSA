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
        bloodtype = "worm";
    }
};
class dog : public mamal{
    public:
    void tailwing(){
        cout<<"a dog wing its tail.\n";
    }
};
int main() { 
    dog d1;
    d1.eat();
    d1.tailwing();
    cout<<d1.bloodtype;
    return 0;
}
