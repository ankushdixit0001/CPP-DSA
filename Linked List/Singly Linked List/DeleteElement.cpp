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
void deleteNode(int pos, Node* &head, Node* &tail){
    //delete first
    if(pos==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr->next;
            count++;
        }
        if(curr->next==NULL){
            tail=prev;//tail garbadge problem
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
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
    deleteNode(5,head,tail);
    deleteNode(4,head,tail);
    print(head);
    cout<<"head = "<<head->data<<endl;
    cout<<"tail = "<<tail->data;
    // tail garbadge problem solved
    return 0;
}
