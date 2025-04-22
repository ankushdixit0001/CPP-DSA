#include <iostream>
#include <unordered_map>
#include <queue>
#include <fstream>
#include <algorithm> // For case conversion
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
    int wordCount;

public:
    Trie() {
        root = new TrieNode('\0');
        wordCount = 0;
    }

    ~Trie() {
        delete root;
    }

    string toLowerCase(string word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        return word;
    }

    void insertWord(string word) {
        word = toLowerCase(word);
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
        wordCount++;
        cout << "'" << word << "' inserted successfully.\n";
    }

    bool searchWord(string word) {
        word = toLowerCase(word);
        if (word.empty()) {
            cout << "Cannot search for an empty word.\n";
            return false;
        }
        if (wordCount == 0) {
            cout << "Trie is empty. No words to search.\n";
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
        word = toLowerCase(word);
        if (word.empty()) {
            cout << "Cannot remove an empty word.\n";
            return;
        }
        if (wordCount == 0) {
            cout << "Trie is empty. No words to remove.\n";
            return;
        }

        if (removeWordHelper(root, word, 0)) {
            wordCount--;
            cout << "'" << word << "' removed successfully.\n";
        } else {
            cout << "Word '" << word << "' not found.\n";
        }
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
        prefix = toLowerCase(prefix);
        if (prefix.empty()) {
            cout << "Cannot check an empty prefix.\n";
            return false;
        }
        if (wordCount == 0) {
            cout << "Trie is empty. No prefixes available.\n";
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

    void printTrieDFS(TrieNode* node, string prefix) {
        if (node->isTerminal) {
            cout << prefix << endl;
        }
        for (auto child : node->children) {
            printTrieDFS(child.second, prefix + child.first);
        }
    }

    void printAllWords() {
        if (wordCount == 0) {
            cout << "Trie is empty. No words to display.\n";
            return;
        }
        cout << "Words in Trie (DFS Traversal):\n";
        printTrieDFS(root, "");
    }

    void printLevelOrder() {
        if (wordCount == 0) {
            cout << "Trie is empty. No words to display.\n";
            return;
        }
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

    void autocomplete(string prefix) {
        prefix = toLowerCase(prefix);
        TrieNode* temp = root;
        for (char ch : prefix) {
            if (temp->children.count(ch) == 0) {
                cout << "No words found for prefix '" << prefix << "'.\n";
                return;
            }
            temp = temp->children[ch];
        }
        printTrieDFS(temp, prefix);
    }

    // Save all words to a file
    void saveToFile(string filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for saving!\n";
            return;
        }
        
        // Recursively write words from Trie
        saveTrieHelper(root, "", file);
        file.close();
        cout << "Trie successfully saved to '" << filename << "'.\n";
    }

    void saveTrieHelper(TrieNode* node, string word, ofstream &file) {
        if (node->isTerminal) {
            file << word << endl;
        }
        
        for (auto child : node->children) {
            saveTrieHelper(child.second, word + child.first, file);
        }
    }

    // Load words from a file into Trie
    void loadFromFile(string filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file for loading!\n";
            return;
        }

        string word;
        while (file >> word) {
            insertWord(word);
        }

        file.close();
        cout << "Trie successfully loaded from '" << filename << "'.\n";
    }

    void searchPatternHelper(TrieNode* node, string pattern, int index, string currentWord) {
        if (index == pattern.size()) {
            if (node->isTerminal) {
                cout << currentWord << endl;
            }
            return;
        }

        char ch = pattern[index];
        
        if (ch == '*') { 
            for (auto child : node->children) {
                searchPatternHelper(child.second, pattern, index + 1, currentWord + child.first);
                searchPatternHelper(child.second, pattern, index, currentWord + child.first);
            }
        } else {
            if (node->children.count(ch) == 0) return;
            searchPatternHelper(node->children[ch], pattern, index + 1, currentWord + ch);
        }
    }

    void searchPattern(string pattern) {
        cout << "Matching words for pattern '" << pattern << "':\n";
        searchPatternHelper(root, pattern, 0, "");
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
        cout << "7. Autocomplete Prefix\n";
        cout << "8. Save Trie to File\n";
        cout << "9. Load Trie from File\n";
        cout << "10. Search with Wildcard\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter word to insert: "; cin >> word; trie->insertWord(word); break;
            case 2: cout << "Enter word to search: "; cin >> word; cout << (trie->searchWord(word) ? "Found" : "Not Found") << endl; break;
            case 3: cout << "Enter word to remove: "; cin >> word; trie->removeWord(word); break;
            case 4: cout << "Enter prefix: "; cin >> word; cout << (trie->startsWith(word) ? "Exists" : "Does not exist") << endl; break;
            case 5: trie->printAllWords(); break;
            case 6: trie->printLevelOrder(); break;
            case 7: cout << "Enter prefix for autocomplete: "; cin >> word; trie->autocomplete(word); break;
            case 8: trie->saveToFile("trie.txt"); break;
            case 9: trie->loadFromFile("trie.txt"); break;
            case 10: cout << "Enter wildcard pattern: "; cin >> word; trie->searchPattern(word); break;
            case 11: delete trie; cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}