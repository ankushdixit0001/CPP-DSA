#include<iostream>
#include<string>
using namespace std;
class Node {
public:
    char data;
    Node* next;
    Node(char data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
private:
    Node* Top;
public:
    Stack() {
        this->Top = NULL;
    }

    void push(char data) {
        Node* newNode = new Node(data);
        newNode->next = Top;
        Top = newNode;
    }

    void pop() {
        if (Top != nullptr) {
            Node* temp = Top;
            Top = Top->next;
            delete temp;
        }
    }

    char top() {
        if (Top != nullptr) {
            return Top->data;
        }
        return '\0'; // Return null character if stack is empty
    }

    bool empty() {
        return Top == nullptr;
    }
};
bool isValid(string str){
    Stack s;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch=='('||ch=='{'||ch=='['){
            s.push(ch);
        }
        else{
            if(s.empty()){
                return false;
            }
            int Top=s.top();
            if((Top=='('&&ch==')')||(Top=='['&&ch==']')||(Top=='{'&&ch=='}')){
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    return s.empty();
}
int main() {
    string str1="({[]})";
    string str2="([{}])";
    cout<<isValid(str1);
    return 0;
}
