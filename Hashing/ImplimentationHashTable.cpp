#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
    }
};

class HashTable {
    int totalSize;
    int currSize;
    Node** table;

    int hashFunction(string key) {
        int idx = 0;
        for (int i = 0; i < key.size(); i++) {
            idx = (idx + key[i] * key[i]) % totalSize;
        }
        return idx % totalSize;
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = totalSize;

        totalSize = 2 * totalSize;
        currSize = 0;
        table = new Node*[totalSize];

        for (int i = 0; i < totalSize; i++) {
            table[i] = NULL;
        }

        // Copy old values
        for (int i = 0; i < oldSize; i++) { // Use oldSize instead of totalSize
            Node* temp = oldTable[i];
            while (temp != NULL) {
                insert(temp->key, temp->val);
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete; // Free memory for old nodes
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int size = 5) {
        totalSize = size;
        currSize = 0;

        table = new Node*[totalSize];
        for (int i = 0; i < totalSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) {
        int idx = hashFunction(key);
        Node* newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;
        currSize++;

        double lambda = currSize / (double)totalSize;
        if (lambda > 1) {
            rehash(); // O(n)
        }
    }

    bool exists(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) { // Found
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int search(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) { // Found
                return temp->val;
            }
            temp = temp->next;
        }
        return -1; // Not found
    }

    void erase(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->key == key) {
                if (prev == NULL) {
                    table[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp; // Free memory for the deleted node
                currSize--;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void print() {
        for (int i = 0; i < totalSize; i++) {
            cout << "idx" << i << " -> ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << "(" << temp->key << " , " << temp->val << ") -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    ~HashTable() {
        for (int i = 0; i < totalSize; i++) {
            Node* temp = table[i];
            while (temp != NULL) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] table;
    }
};

int main() {
    HashTable ht;
    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);
    ht.print();
    cout << endl;

    ht.erase("China");
    ht.print();
    cout << endl;

    ht.erase("Nepal");
    ht.print();
    return 0;
}