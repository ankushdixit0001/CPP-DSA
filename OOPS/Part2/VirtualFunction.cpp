#include<iostream>
using namespace std;
// A virtual func is a member func that you to be redefined in derived classess. 
class parent {
    public:
    void show(){
        cout<<"parent class.";
    } 
    //define virtual class
    virtual void hello(){
        cout<<" parent hello";
    }
};
class child : public parent {
    public:
    void show(){
        cout<<"child class";
    }
    //redefine virtual class
    void hello(){
        cout<<" child hello";
    }
};
int main() {
    child ch;
    parent *ptr;
    ptr = &ch;
    ptr->hello();
    return 0;
}