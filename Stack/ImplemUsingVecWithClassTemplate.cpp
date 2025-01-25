#include<iostream>
#include<vector>
using namespace std;
//template
template<class T>
class Stack{
    vector<T> vec;
    public:
    void push(T val){
        //O(1) 
        vec.push_back(val);
    }
    void pop(){
        if(isEmpty()){
            cout<<"stack is empty.";
            return;
        }
        vec.pop_back();
    }
    T top(){
        if(isEmpty()){
            cout<<"stack is empty.";
            return -1;
        }
        int lastIdx=vec.size()-1;
        return vec[lastIdx];
    }
    bool isEmpty(){
        return vec.size()==0;
    }
};
int main() {
    Stack<char> s; //define here type of data
    s.push('a');
    s.push('b');
    s.push('c');
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
