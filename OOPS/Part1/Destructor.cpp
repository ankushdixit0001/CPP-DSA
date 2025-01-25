#include<iostream>
using namespace std;
class car {
    public:
    string name ; 
    string color;
    int *mileage;
    car(string nameval , string colorval) { //contructor
        name=nameval;
        color=colorval;
        mileage = new int;
        *mileage =12;
    }
    car(car &original) { //copy constructor
        cout<<"copy..."<<endl;
        name = original.name; 
        color=original.color;
        mileage = new int;
        *mileage =*original.mileage;
    }
    ~car() { // destructor
        cout<<"deleting obj....";
        if(mileage!=NULL){
            delete mileage;
            mileage = NULL;
        }
    }
};
int main() {
    car c1("maruti 800" , "white");
    cout<<c1.name<<endl;
    cout<<c1.color<<endl;
    cout<<*c1.mileage<<endl;
    return 0;
}