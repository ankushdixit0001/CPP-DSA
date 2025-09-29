#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// TC: O(n), SC: O(1)
int lengthOfList(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

// TC: O(1), SC: O(1)
void insertAtHead(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);
    if(!head){
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

// TC: O(1), SC: O(1)
void insertAtTail(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);
    if(!tail){
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// TC: O(pos), SC: O(1)
void insertAtPosition(Node* &head, Node* &tail, int pos, int data){
    if(pos == 1){
        insertAtHead(head, tail, data);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count < pos - 1 && temp != NULL){
        temp = temp->next;
        count++;
    }
    if(temp == NULL || temp->next == NULL){
        insertAtTail(head, tail, data);
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

// TC: O(1), SC: O(1)
void deleteAtHead(Node* &head, Node* &tail){
    if(!head) return;
    Node* temp = head;
    head = head->next;
    if(head)
        head->prev = NULL;
    else
        tail = NULL;
    delete temp;
}

// TC: O(1), SC: O(1)
void deleteFromTail(Node* &head, Node* &tail){
    if(!tail) return;
    Node* temp = tail;
    tail = tail->prev;
    if(tail)
        tail->next = NULL;
    else
        head = NULL;
    delete temp;
}

// TC: O(pos), SC: O(1)
void deleteAtPosition(Node* &head, Node* &tail, int pos){
    int len = lengthOfList(head);  // TC: O(n)
    if(pos <= 0 || pos > len){
        cout << "Position out of bounds.\n";
        return;
    }
    if(pos == 1){
        deleteAtHead(head, tail);
        return;
    } else if(pos == len){
        deleteFromTail(head, tail);
        return;
    } else {
        Node* temp = head;
        int count = 1;
        while(count < pos){
            temp = temp->next;
            count++;
        }
        Node* prevNode = temp->prev;
        Node* nextNode = temp->next;
        prevNode->next = nextNode;
        if(nextNode)
            nextNode->prev = prevNode;
        delete temp;
    }
}

// TC: O(n), SC: O(1)
void reverseList(Node* &head, Node* &tail){
    if(!head) return;
    Node* temp=head;
    Node* prev=NULL;
    while(temp){
        Node* nextNode=temp->next;
        temp->next=prev;
        temp->prev=nextNode;
        prev=temp;
        temp=nextNode;
    }
    tail=head;
    head=prev;
}

// TC: O(n), SC: O(1)
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// TC: O(n), SC: O(1)
void printListReverse(Node* tail){
    Node* temp = tail;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Test Case: Insertion
    insertAtHead(head, tail, 10);       // List: 10
    insertAtHead(head, tail, 5);        // List: 5 <-> 10
    insertAtTail(head, tail, 20);       // List: 5 <-> 10 <-> 20
    insertAtPosition(head, tail, 2, 7); // List: 5 <-> 7 <-> 10 <-> 20
    printList(head);

    // Test Case: Reverse the list
    reverseList(head, tail);            // Reverses the list
    cout << "Reversed List (Forward): ";
    printList(head);
    cout << "Reversed List (Backward): ";
    printListReverse(tail);

    // Test Case: Deletion
    deleteAtPosition(head, tail, 3);    // Deletes 7
    deleteAtPosition(head, tail, 1);    // Deletes 20
    deleteAtPosition(head, tail, lengthOfList(head)); // Deletes 5
    printList(head);

    deleteAtPosition(head, tail, 5);    // Out of bounds
    printList(head);

    return 0;
}