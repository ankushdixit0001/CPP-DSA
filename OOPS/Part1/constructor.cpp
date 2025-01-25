#include<iostream>
#include<string>
using namespace std;

class car{
    string name="ankush" ; 
    string color;

    public:
    //this is constructor . it calls only one. this is also use to asign val
    // car(string nameval , string colorval){
    //     cout<<"constructor is called. object being created ..";
    //     name=nameval;
    //     color=colorval;
    // }
    void start(){
        cout << "car started";
    }
    void stop(){
        cout<<"car has stopped";
    }
    string getname(){
        return name;
    }

};

int main() {
    car c1;//asign val by construstor
    c1.start();
    return 0;
}
