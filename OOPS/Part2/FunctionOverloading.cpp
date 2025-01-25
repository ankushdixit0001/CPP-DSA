#include<iostream>
using namespace std;
class Print{
    public:
    void show(int x){
        cout<<"int x: "<<x<<endl;
    }
    void show(string x){
        cout<<"string x: "<<x<<endl;
    }
};
int main() {
    Print obj1;
    obj1.show(25);
    obj1.show("hllo");
    return 0;
}
