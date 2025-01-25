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
void insertAtHead(Node* &head, Node* &tail , int data){

    // head==NULL
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{
    Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;        
    }

}
void insertAtTail(Node* &tail, Node* &head , int data){
    // head==NULL
    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        head=temp;
    }
    else{
    Node* temp=new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}
void insertAtPosition(Node* &tail,Node* &head, int position, int data){
    if(position==1){//at starting
        insertAtHead(head,tail,data);
        return;
    }
    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){//at last
        insertAtTail(tail,head,data);
        return;
    }
    //creating node
    Node* nodeToInsert= new Node(data);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
}
void print(Node* &head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main() {
    // Node* node1=new Node(10);
    Node* head=NULL;//node1;
    Node* tail=NULL;//node1;
    insertAtHead(head,tail,9);
    insertAtHead(head,tail,8); 
    insertAtTail(tail,head,12);
    insertAtPosition(tail,head,4,11); 
    print(head);
    insertAtPosition(tail,head,1,7); 
    print(head);
    insertAtPosition(tail,head,6,13); 
    print(head);
    cout<<"head data = "<<head->data<<endl;
    cout<<"tail data = "<<tail->data<<endl;
    insertAtPosition(tail,head,7,16); 
    print(head);
    return 0;
}

