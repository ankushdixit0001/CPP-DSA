#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Node{
    public:
    unordered_map<char,Node*>children;
    bool endOfWord;

    Node(){
        endOfWord=false;
    }
};
class Trie{
    Node* root;

    public:
    Trie(){
        root=new Node();
    }

    void insert(string key){//O(L)
        Node* temp=root;

        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();
            }
            temp=temp->children[key[i]];
        }
        temp->endOfWord=true;
    }

    bool search(string key){//O(L)
        Node* temp=root;

        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            } else {
                return false;
            }
        }
        return temp->endOfWord;
    }
};
int main() {
    vector<string> words={"the","a","there","their","any","thee"};
    Trie trie;

    for(const auto word:words){
        trie.insert(word);
    }

    cout<<trie.search("a")<<endl;
    return 0;
}
