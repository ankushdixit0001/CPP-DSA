#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isDublicate(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch!=')'){
            //non closing
            s.push(ch);
        }
        else{
            //closing
            if(s.top()=='('){
                return true;
            }
            while(s.top()!='('){
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}
int main() {
    string str1="(x+y)";
    string str2="((x+y)+((x)))";
    cout<<isDublicate(str2);
    return 0;
}
