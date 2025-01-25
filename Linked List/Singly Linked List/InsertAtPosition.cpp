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
void insertAtHead(Node* &head, int data){
    //creating new node
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertElement(Node* &tail, int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}
void insertAtPosition(Node* &tail,Node* &head, int position, int data){
    if(position==1){//at starting
        insertAtHead(head,data);
        return;
    }
    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){//at last
        insertElement(tail,data);
        return;
    }
    //creating node
    Node* nodeToInsert= new Node(data);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}

int main() {
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    insertElement(tail,12);
    insertElement(tail,16);
    insertElement(tail,18);
    print(head);
    insertAtPosition(tail,head,3,14);
    insertAtPosition(tail,head,1,8);
    insertAtPosition(tail,head,7,20);
    print(head);
    cout<<"head = "<<head->data<<endl;
    cout<<"tail = "<<tail->data;
    return 0;
}
