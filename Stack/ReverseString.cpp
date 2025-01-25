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
    Node* top;
public:
    Stack() {
        top = nullptr;
    }

    void push(char data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    char getTop() {
        if (top != nullptr) {
            return top->data;
        }
        return '\0'; // Return null character if stack is empty
    }

    bool empty() {
        return top == nullptr;
    }
};

string reverseString(string str) {
    string ans;
    Stack s;
    for(int i = 0; i < str.size(); i++) {
        s.push(str[i]);
    }
    while(!s.empty()) {
        char top = s.getTop();
        ans += top;
        s.pop();
    }
    return ans;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Reversed string: " << reverseString(str) << endl;
    return 0;
}