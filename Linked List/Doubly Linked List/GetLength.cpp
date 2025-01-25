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
void getLength(Node* &head){
    Node* temp= head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    cout<<"Length = "<<count;
}
int main() {
    Node* node1=new Node(10);
    Node* head=node1;
    getLength(head);
    return 0;
}
