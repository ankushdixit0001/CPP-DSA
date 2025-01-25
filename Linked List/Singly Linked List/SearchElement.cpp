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
int searchKey(Node* &head, int key){
    Node* temp=head;
    int index=0;
    while(temp!=NULL){
        if(temp->data==key){
            return index;
        }
        temp=temp->next;
        index++;
    }
    return -1;
}
int main() {
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtTail(tail,13);
    insertAtTail(tail,14);
    print(head);
    int key=13;
    cout<<"Index = "<<searchKey(head,key);
    return 0;
}
