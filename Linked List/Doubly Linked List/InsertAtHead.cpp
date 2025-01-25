#include<iostream>
using namespace std;
class Node{
    public:
    int data ;
    Node* next;
    Node* prev;
    //constructor
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};
void insertAtHead(Node* &head , int data){
    Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void getLength(Node* &head){
    Node* temp= head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    cout<<"Length = "<<count<<endl;
}
void print(Node* &head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main() {
    Node* node1=new Node(10);
    Node* head=node1;
    insertAtHead(head,9);
    insertAtHead(head,8);
    getLength(head);
    print(head);
    return 0;
}
