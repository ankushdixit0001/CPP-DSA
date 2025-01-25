#include<iostream>
using namespace std;
// when properties & member functions of base class are passed on to the derived class.

//this is also single level inheritance.

class Animal{
    public:
    string color;
    void eat() {
        cout<<"eats\n";
    }
    void breath(){
        cout<<"breath\n";
    }
};
class Fish : public Animal{
    public:
    int fins;
    void swim(){
        cout<<"swim\n";
    }
};
int main() {
    Fish f1;
    f1.fins=3;
    cout<<f1.fins<<endl;
    f1.swim();
    f1.breath();
    return 0;
}
