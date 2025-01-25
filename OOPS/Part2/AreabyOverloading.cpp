#include<iostream>
#include<math.h>
using namespace std;
double area(int l,int b){
    return l*b;
}
double area(int r){
    return 3.14*r*r;
}
double area(int a,int b,int c){
    double s;
    s=(a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main() {
    int r,l,b,x,y,z;
    double ca , ta;
    long ra;
    cout<<"Enter radius of a circle";
    cin>>r;
    ca=area(r);
    cout<<"Enter length and width of a rectangle";
    cin>>l>>b;
    ra=area(l,b);
    cout<<"Enter 3 sides of triangle";
    cin>>x>>y>>z;
    ta=area(x,y,z);
    cout<<"Area of circle ="<<ca<<endl;
    cout<<"Area of rectangle ="<<ra<<endl;
    cout<<"Area of triangle ="<<ta<<endl;
    return 0;
}
