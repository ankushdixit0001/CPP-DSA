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
void insertAtTail(Node* &tail, int data){
    //new node creation
    Node* temp= new Node(data);
    tail->next=temp;
    tail=temp;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void Reverse(Node* &head, Node* &tail){
    Node* curr=head;
    Node* prev=NULL;
    while(curr!=NULL){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    tail=head;
    head=prev;
}
int main() {
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtTail(tail,13);
    insertAtTail(tail,14);
    cout<<"Original list :";
    print(head);
    Reverse(head,tail);
    cout<<"After Reverse :";
    print(head);
    cout<<"head "<<head->data;
    cout<<" tail "<<tail->data;
    return 0;
}
