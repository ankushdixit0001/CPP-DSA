// travers
// searching
//length
//insertion - head tail location
// deletion - head, tail, location
// modify 
//reverse

#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position) {
    if (position == 1) {
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    int count = 1;
    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    // Insert at tail if position is greater than current length
    if (temp == NULL || temp->next == NULL) {
        insertAtTail(tail, data);
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int lengthOfList(Node* head){
    if(head==NULL){
        return 0;
    }
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
int searchNodePosition(Node* head,int val){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(temp->data==val){
            return count;
        }
        temp=temp->next;
    }
    return -1;
}
void deleteFromHead(Node* &head){
    if(!head){
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
}
void deleteFromTail(Node* &head,Node* &tail){
    if(!head){
        return;
    }
    if(head==tail){
        delete head;
        head=tail=NULL;
        return;
    }
    Node* temp=head;
    while(temp->next!=tail){
        temp=temp->next;
    }
    delete tail;
    temp->next=NULL;
    tail=temp;
}
void deleteAtPosition(Node* &head,Node* &tail,int pos){
    int length=lengthOfList(head);
    if(pos==1){
        deleteFromHead(head);
    } else if(pos>length){
        cout<<"can't have node at the position."<<endl;
    } else if(pos==length){
        deleteFromTail(head,tail);
    } else {
        int count=1;
        Node* temp=head;
        Node* prev=temp;
        while(count<pos){
            prev=temp;
            temp=temp->next;
            count++;
        }
        prev->next=temp->next;
        delete temp;
    }
}
void deleteList(Node* &head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    Node* node1 = new Node(11);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 10);
    insertAtHead(head, 1);
    insertAtHead(head, 20);
    insertAtHead(head, 30);

    printList(head);

    insertAtTail(tail, 99);
    printList(head);

    insertAtPosition(head, tail, 77, 3); // Insert at position 3
    printList(head);

    insertAtPosition(head, tail, 100, 100); // Insert at position beyond length (at tail)
    printList(head);

    cout<<"Length of list:"<<lengthOfList(head)<<endl;
    
    cout<<"Node position:"<<searchNodePosition(head,77)<<endl;
    deleteFromHead(head);
    printList(head);
    cout<<"Length of list:"<<lengthOfList(head)<<endl;
    deleteFromTail(head,tail);
    printList(head);
    cout<<"Length of list:"<<lengthOfList(head)<<endl;
    deleteAtPosition(head,tail,2);
    printList(head);
    cout<<"Length of list:"<<lengthOfList(head)<<endl;
    deleteList(head);
    return 0;
}