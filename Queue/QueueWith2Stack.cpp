#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
private:
    Node* Top;
public:
    Stack() {
        Top = nullptr;
    }

    void push(int data) {
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

    int top() {
        if (Top != NULL) {
            return Top->data;
        }
                cout<<"Stack is empty";
    }

    bool empty() {
        return Top == NULL;
    }
};

class Queue {
    Stack s1;
    Stack s2;

    void transferStacks() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    void push(int data) {
        s1.push(data);
    }

    void pop() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout<<"Queue is empty";
            }
            transferStacks();
        }
        s2.pop();
    }

    int front() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout<<"Queue is empty";
            }
            transferStacks();
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
