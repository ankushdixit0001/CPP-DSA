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
    Node(int data) : data(data), next(NULL) {}
};

// Traversal
void printList(Node* head) {
    // Time: O(n), Space: O(1)
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Length
int lengthOfList(Node* head) {
    // Time: O(n), Space: O(1)
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Search
int searchNodePosition(Node* head, int val) {
    // Time: O(n), Space: O(1)
    int pos = 1;
    while (head) {
        if (head->data == val) return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

// Insertion
void insertAtHead(Node*& head, Node*& tail, int data) {
    // Time: O(1), Space: O(1)
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node*& head, Node*& tail, int data) {
    // Time: O(1), Space: O(1)
    Node* newNode = new Node(data);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(Node*& head, Node*& tail, int data, int position) {
    // Time: O(n), Space: O(1)
    if (position <= 1) {
        insertAtHead(head, tail, data);
        return;
    }

    int len = lengthOfList(head);
    if (position > len) {
        insertAtTail(head, tail, data);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp; i++) {
        temp = temp->next;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Deletion
void deleteFromHead(Node*& head, Node*& tail) {
    // Time: O(1), Space: O(1)
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (!head) tail = NULL;
    delete temp;
}

void deleteFromTail(Node*& head, Node*& tail) {
    // Time: O(n), Space: O(1)
    if (!head) return;
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = NULL;
}

void deleteAtPosition(Node*& head, Node*& tail, int pos) {
    // Time: O(n), Space: O(1)
    int len = lengthOfList(head);
    if (pos <= 0 || pos > len) {
        cout << "Invalid position to delete." << endl;
        return;
    }
    if (pos == 1) {
        deleteFromHead(head, tail);
    } else if (pos == len) {
        deleteFromTail(head, tail);
    } else {
        Node* prev = NULL;
        Node* curr = head;
        for (int i = 1; i < pos; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
    }
}

// Reverse
void reverseList(Node*& head, Node*& tail) {
    // Time: O(n), Space: O(1)
    Node* prev = NULL;
    Node* curr = head;
    tail = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// Delete entire list
void deleteList(Node*& head, Node*& tail) {
    // Time: O(n), Space: O(1)
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
}

// Cycle detection
bool isCycle(Node* head) {
    // Time: O(n), Space: O(1)
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            cout << "Cycle exists." << endl;
            return true;
        }
    }
    cout << "No cycle detected." << endl;
    return false;
}

// Cycle removal
void removeCycle(Node*& head) {
    // Time: O(n), Space: O(1)
    Node* slow=head;
    Node* fast=head;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            break;
        }
    }

    if(slow!=fast){
        cout<<"cycle not exist."<<endl;
        return;
    }

    cout<<"cycle exist."<<endl;

    slow=head;
    if(slow==fast){
        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next=NULL;
    } else {
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }

    cout<<"cycle successfully removed.";
}

// Main
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Basic insertions
    insertAtTail(head, tail, 11);
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 1);
    insertAtTail(head, tail, 99);
    insertAtPosition(head, tail, 77, 3);
    insertAtPosition(head, tail, 100, 100); // Insert beyond length

    printList(head);
    cout << "Length: " << lengthOfList(head) << endl;

    // Search tests
    cout << "Position of 77: " << searchNodePosition(head, 77) << endl;
    cout << "Position of 500 (not found): " << searchNodePosition(head, 500) << endl;

    // Deletion tests
    deleteFromHead(head, tail);
    deleteFromTail(head, tail);
    deleteAtPosition(head, tail, 2);
    deleteAtPosition(head, tail, 100); // Invalid position
    printList(head);

    // Reverse tests
    reverseList(head, tail);
    printList(head);

    // Reverse empty list
    deleteList(head, tail);
    reverseList(head, tail); // Should handle gracefully
    printList(head);

    // Insert single node and reverse
    insertAtHead(head, tail, 42);
    reverseList(head, tail);
    printList(head);

    // Cycle creation and detection
    insertAtTail(head, tail, 43);
    insertAtTail(head, tail, 44);
    tail->next = head->next; // Create cycle
    isCycle(head);
    removeCycle(head);
    isCycle(head);

    // Final cleanup
    deleteList(head, tail);
    printList(head);

    return 0;
}