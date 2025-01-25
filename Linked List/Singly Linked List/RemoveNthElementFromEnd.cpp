#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void push_back(Node* &tail, int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}
void print(Node* &head){
    Node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void removeNth(Node* &head, int n) {
    if (!head) return; // If the list is empty

    // Calculate the size of the list
    int size = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        size++;
    }

    // If the list has only one node
    if (size == 1) {
        delete head;
        head = NULL;
        cout << "NULL";
        return;
    }

    // If the node to be removed is the head
    if (size == n) {
        Node* newHead = head->next;
        delete head;
        head = newHead;
        return;
    }

    // Traverse to the node before the one to be removed
    Node* prev = head;
    for (int i = 1; i < (size - n); i++) {
        prev = prev->next;
    }

    // Remove the nth node from the end
    Node* todel = prev->next;
    prev->next = prev->next->next;
    delete todel;
}

int main() {
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    // push_back(tail,11);
    // push_back(tail,12);
    // push_back(tail,13);
    // push_back(tail,14);
    print(head);
    removeNth(head,1);
    print(head);
    return 0;
}
