#include<iostream>
using namespace std;
class car {
    public:
    string name ; 
    string color;
    car(string nameval , string colorval) {
        name=nameval;
        color=colorval;
    }
    car(car &original) { //copy cons. its make shallow copy of pointers. to make deep copy of pointer variable (pointervariablename = new int)
        cout<<"copy"<<endl;
        name = original.name;
        color=original.color;
    }
};
int main() {
    car c1("maruti 800" , "white");
    car c2(c1); //this is copy constructor. copy c1 in c2
    cout<<c2.name<<endl;
    cout<<c2.color<<endl;
    return 0;
}