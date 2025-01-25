#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void pushAtBottom(stack<int> &s, int temp){//O(n)
    if(s.empty()){
        s.push(temp);
        return;
    }
    int top=s.top();
    s.pop();
    pushAtBottom(s,temp);
    s.push(top);//backtracking
}
void reverse(stack<int> &s){//O(n)
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s,temp);
}
void printstack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main() {
    stack<int> st;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    printstack(st);
    reverse(st);
    printstack(st);
    return 0;
}
