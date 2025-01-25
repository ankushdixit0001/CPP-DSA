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
void insert(Node* &tail, int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}
void printnode(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void removeCycle(Node* &head){
    //detect cycle
    Node* slow=head;
    Node* fast=head;
    bool iscycle=false;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            iscycle=true;
            cout<<"Cycle detect\n";
            break;
        }
    }
    if(!iscycle){
        cout<<"Cycle doesn't detect\n";
        return;
    }
    slow=head;
    if(slow==fast){
        //special case
        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next=NULL;//removing cycle
    }
    else{
        Node* prev=fast;
        while(slow!=fast){
            slow=slow->next;
            prev=fast;
            fast=fast->next;
        }
        fast->next=NULL;
    }
}
int main() {
    Node* node1=new Node(1);
    Node* head=node1;
    Node* tail=node1;
    insert(tail,2);
    insert(tail,3);
    insert(tail,4);
    insert(tail,5);
    tail->next=head;
    removeCycle(head);
    printnode(head);
    return 0;
}
