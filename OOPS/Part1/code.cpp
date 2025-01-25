#include<iostream>
#include<string>
using namespace std;

// classes = group of entities . 
//objects = entities in real world .student and its property 
 
//Encap sulation is wrapping up of data & member 
//functions(methods) i single unit.it is also implements data hiding.

class Student {
    // ..properties
    private://access modifiers
    string name;
    float cgpa;
    public://access modifiers
    
    int rollno;

    //method
    void getPercentage(){
        cout<<(cgpa*10)<<"%\n";
    }
    //setter
    void setName(string nameval){
        name = nameval;
    }
    void setcgpa(float cgpaval){
        cgpa= cgpaval;
    }
    //getter
    string getname(){
        return name;
    }
    float getcgpa(){
        return cgpa;
    }
};

int main() {
    Student s1; //obj
    s1.setName("Ankush");
    s1.setcgpa(9.1);
    cout<<s1.getname()<<endl;
    s1.getPercentage();
    cout<<s1.getcgpa();
    return 0;
}
