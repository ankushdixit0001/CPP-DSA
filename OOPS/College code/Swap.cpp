#include<iostream>
using namespace std;
void swap(int a, int b){
    int t=a;
    a=b;
    b=t;
}
void exchange(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void change(int &a, int &b){
    int t=a;
    a=b;
    b=t;
}
int main() {
    int x=6, y=10;
    cout<<x<<" "<<y<<endl;
    swap(x,y);
    cout<<"after swap ="<<x<<" "<<y<<endl; 
    exchange(&x,&y);
    cout<<"after exchange = "<<x<<" "<<y<<endl;
    change(x,y);
    cout<<"after change ="<<x<<" "<<y<<endl;
    return 0;
}
