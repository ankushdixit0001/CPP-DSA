#include<iostream>
using namespace std;

class user{
    private:
    int id;
    string password;
    public:
    string username;

    user(int id){
        cout<<"Enter the id : ";
        this->id=id;
    }
    string getpass() {
        return password;
    }
    void setpass(string passwordval){
        password=passwordval;
    }
};

int main() {
    int n;
    user m1(n);
    cin>>n;
    m1.username="ankush";
    m1.setpass("a2ka4 ");
    cout<<"Name : "<<m1.username<<endl;
    cout<<"Password : "<<m1.getpass();
    return 0;
}
