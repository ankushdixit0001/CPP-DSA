#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class TrieNode {
public:
    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
    }

    ~TrieNode() {
        for (auto child : children) {
            delete child.second;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode('\0');
    }

    ~Trie() {
        delete root;
    }

    void insertWord(string word) {
        if (word.empty()) {
            cout << "Cannot insert an empty word.\n";
            return;
        }

        TrieNode* temp = root;
        for (char ch : word) {
            if (temp->children.count(ch) == 0) {
                temp->children[ch] = new TrieNode(ch);
            }
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
    }

    bool searchWord(string word) {
        if (word.empty()) {
            cout << "Cannot search for an empty word.\n";
            return false;
        }

        TrieNode* temp = root;
        for (char ch : word) {
            if (temp->children.count(ch) == 0) {
                return false;
            }
            temp = temp->children[ch];
        }
        return temp->isTerminal;
    }

    void removeWord(string word) {
        if (word.empty()) {
            cout << "Cannot remove an empty word.\n";
            return;
        }

        removeWordHelper(root, word, 0);
    }

private:
    bool removeWordHelper(TrieNode* node, string word, int index) {
        if (index == word.size()) {
            if (!node->isTerminal) return false;

            node->isTerminal = false;
            return node->children.empty();
        }

        char ch = word[index];
        if (node->children.count(ch) == 0) return false;

        bool shouldDeleteChild = removeWordHelper(node->children[ch], word, index + 1);

        if (shouldDeleteChild) {
            delete node->children[ch];
            node->children.erase(ch);
            return node->children.empty() && !node->isTerminal;
        }

        return false;
    }

public:
    bool startsWith(string prefix) {
        if (prefix.empty()) {
            cout << "Cannot check an empty prefix.\n";
            return false;
        }

        TrieNode* temp = root;
        for (char ch : prefix) {
            if (temp->children.count(ch) == 0) {
                return false;
            }
            temp = temp->children[ch];
        }
        return true;
    }

    // DFS-based Printing: Print all stored words recursively
    void printTrieDFS(TrieNode* node, string prefix) {
        if (node->isTerminal) {
            cout << prefix << endl;
        }

        for (auto child : node->children) {
            printTrieDFS(child.second, prefix + child.first);
        }
    }

    void printAllWords() {
        cout << "Words in Trie (DFS Traversal):\n";
        printTrieDFS(root, "");
    }

    // BFS-based Printing: Print elements level-by-level using a queue
    void printLevelOrder() {
        if (!root) return;

        queue<TrieNode*> q;
        q.push(root);

        cout << "Level Order Traversal of Trie:\n";
        while (!q.empty()) {
            TrieNode* current = q.front();
            q.pop();

            if (current->data != '\0') {
                cout << current->data << " ";
            }

            for (auto child : current->children) {
                q.push(child.second);
            }
        }
        cout << endl;
    }
};

int main() {
    Trie* trie = new Trie();
    int choice;
    string word;

    while (true) {
        cout << "\nTrie Operations:\n";
        cout << "1. Insert Word\n";
        cout << "2. Search Word\n";
        cout << "3. Remove Word\n";
        cout << "4. Check Prefix\n";
        cout << "5. Print All Words (DFS)\n";
        cout << "6. Print Level Order Traversal (BFS)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter word to insert: ";
                cin >> word;
                trie->insertWord(word);
                cout << "'" << word << "' inserted successfully.\n";
                break;
            case 2:
                cout << "Enter word to search: ";
                cin >> word;
                cout << "Search result: " << (trie->searchWord(word) ? "Found" : "Not Found") << endl;
                break;
            case 3:
                cout << "Enter word to remove: ";
                cin >> word;
                trie->removeWord(word);
                cout << "'" << word << "' removed successfully.\n";
                break;
            case 4:
                cout << "Enter prefix to check: ";
                cin >> word;
                cout << "Prefix check result: " << (trie->startsWith(word) ? "Exists" : "Does not exist") << endl;
                break;
            case 5:
                trie->printAllWords();
                break;
            case 6:
                trie->printLevelOrder();
                break;
            case 7:
                delete trie;
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}