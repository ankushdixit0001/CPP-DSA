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
void push_back(Node* &tail, int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}
void print(Node* &head){
    Node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int searchRecur(Node* &head,int key){
    if(head==NULL){
        return -1;
    }
    if(head->data==key){
        return 0;
    }
    int idx=searchRecur(head->next,key);
    if(idx==-1){
        return -1;
    }
    return idx+1;
}
int main() {
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    push_back(tail,11);
    push_back(tail,12);
    push_back(tail,13);
    push_back(tail,14);
    print(head);
    cout<<searchRecur(head,14);
    return 0;
}
