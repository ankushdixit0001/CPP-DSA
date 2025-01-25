#include<iostream>
using namespace std;
class Teacher{
    public:
    int salary;
    string subject;
};
class student{
    public:
    int rollno;
    float cgpa;
};
class TA : public Teacher , public student{
    public:
    string name; 
};
int main() {
    TA ta1;
    ta1.name="ankush";
    ta1.subject="cpp";
    ta1.cgpa=7.5;
    cout<<ta1.name<<endl;
    cout<<ta1.subject<<endl;
    cout<<ta1.cgpa<<endl;
    return 0;
}
