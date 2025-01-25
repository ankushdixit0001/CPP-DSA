#include<iostream>
#include<queue>
using namespace std;
void firstNonRepeat(string str){
    queue<char> q;
    int freq[26]={0};

    for(int i=0;i<str.size();i++){
        char ch=str[i];
        q.push(ch);
        freq[ch-'a']++;
        while(!q.empty()&& freq[q.front()-'a']>1){
            q.pop();
        }
        if(q.empty()){
            cout<<"-1"<<endl;
        }
        else{
            cout<<q.front()<<"\n";
        }
    }
}
int main() {
    string str="abhb";
    firstNonRepeat(str);
    return 0;
}
