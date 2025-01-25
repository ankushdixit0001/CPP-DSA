#include<iostream>
using namespace std;
class A{
    string secret ="secret data";
    friend class B;
    friend void revealsec(A &obj);
};
class B{
    public:
    void showsecret(A &obj){
        cout<<obj.secret<<endl;
    }
};
void revealsec(A &obj){
    cout<<obj.secret<<endl;

} 
int main() {
    A a1;
    B b1;
    b1.showsecret(a1);
    revealsec(a1);
    return 0;
}
