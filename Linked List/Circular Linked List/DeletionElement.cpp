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
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for val = "<<val<<endl;
    }
};
void insertNode(Node* &tail, int element, int data){
    //firat case is empty list

    if(tail==NULL){
        Node* newnode= new Node(data);
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        //list is non- empty 
        //assuming hat element is present
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        //element found, curr is represent element
        Node* temp=new Node(data);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void deleteNode(Node* &tail, int val){
    //empty list
    if(tail==NULL){
        cout<<"list is empty"<<endl;
    }
    else{
        //non-empty
        //assuming val is present in LL
        Node* prev = tail;
        Node* curr=prev->next;
        while(curr->data!=val){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(curr==prev){
            tail=NULL;//1 node
        }
        else if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}
void print(Node* &tail){
    if(tail==NULL){
        cout<<"empty list"<<endl;
    }
    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    } while(tail!=temp);
    cout<<endl;
}
int main() {
    Node* tail=NULL;
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,4);
    print(tail);    
    insertNode(tail,4,5);
    print(tail);
    deleteNode(tail,5);
    print(tail);
    return 0;
}
