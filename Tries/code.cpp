#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class TrieNode{
    public:
    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char ch){
        data=ch;
        isTerminal=false;
    }

};
class Trie{
    private:
    TrieNode* root;
    public:
    Trie(){
        root=new TrieNode('\0');
    }

    void insert(string word){
        if(word.empty()){
            cout << "Cannot insert an empty word.\n";
            return;
        }

        TrieNode* temp=root;
        for(char ch:word){
            if(temp->children.count(ch)==0){
                temp->children[ch]=new TrieNode(ch);
            }
            temp=temp->children[ch];
        }
        temp->isTerminal=true;
    }
    bool search(string word){
        TrieNode* temp=root;
        for(char ch:word){
            if(temp->children.count(ch)==0){
                return false;
            }
            temp=temp->children[ch];
        }
        return temp->isTerminal;
    }
    void printHelper(TrieNode* root,string word){
        if(root->isTerminal){
            cout<<word<<" ";
        }
        for (auto child : root->children) {
            printHelper(child.second, word + child.first);
        }
    }
    void printTrie(){
        cout<<" the trie contains : ";
        printHelper(root,"");
    }
};
int main() {
    vector<string> words={"the","a","there","their","any","thee"};
    Trie trie;

    for(const auto word:words){
        trie.insert(word);
    }

    // cout<<trie.search("a")<<endl;
    trie.printTrie();
    return 0;
}
