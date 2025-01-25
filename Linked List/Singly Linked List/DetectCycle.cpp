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
    // don't print cycle list
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
bool iscycle(Node* &head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;//+1
        fast=fast->next->next;//+2
        if(slow == fast){
            cout<<"cycle exist.";
            return true;
        }
    }
    cout<<"cycle doesn't exist.";
    return false;
}
int main() {
    Node* node1= new Node(10);
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(tail,11);
    InsertAtTail(tail,12);
    InsertAtTail(tail,13);
    tail->next=head;
    // Print(head);   //if u print this u stuck in infinite loop
    iscycle(head);
    return 0;
}
