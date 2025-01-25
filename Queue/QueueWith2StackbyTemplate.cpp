#include <iostream>
#include<stdexcept>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class Stack {
private:
    Node<T>* Top;
public:
    Stack() {
        Top = nullptr;
    }

    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = Top;
        Top = newNode;
    }

    void pop() {
        if (Top != nullptr) {
            Node<T>* temp = Top;
            Top = Top->next;
            delete temp;
        }
    }

    T top() {
        if (Top != nullptr) {
            return Top->data;
        }
        throw runtime_error("Stack is empty");
    }

    bool empty() {
        return Top == nullptr;
    }
};

template <typename T>
class Queue {
    Stack<T> s1;
    Stack<T> s2;

    void transferStacks() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    void push(T data) {
        s1.push(data);
    }

    void pop() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout<<"Queue is empty";
                return;
            }
            transferStacks();
        }
        s2.pop();
    }

    T front() {
        if (s2.empty()) {
            if (s1.empty()) {
                throw runtime_error("Queue is empty");
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
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    // cout << q.front() << endl; // Should print 1
    // q.pop();
    // cout << q.front() << endl; // Should print 2
    // q.pop();
    // cout << q.front() << endl; // Should print 3
    // q.pop();
    // cout << q.front() << endl; // Should print 4
    // q.pop();
    // // cout << q.empty() << endl; // Should print 1 (true)

    return 0;
}
