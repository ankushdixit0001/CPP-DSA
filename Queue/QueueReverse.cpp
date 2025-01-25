#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverse(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}
int main() {
    queue<int> org;
    for(int i=1;i<=5;i++){
        org.push(i);
    }
    reverse(org);
    for(int i=1;i<=5;i++){
        cout<<org.front()<<" ";
        org.pop();
    }
    return 0;
}
