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
void InsertAtTail(Node* &tail, int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}
void Print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main() {
    Node* node1= new Node(10);
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(tail,12);
    InsertAtTail(tail,15);
    Print(head);
    return 0;
}
