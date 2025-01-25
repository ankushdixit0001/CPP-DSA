#include<iostream>
#include<string.h>
using namespace std;

int main() {
    // char word[10];
    // cin>>word;
    char sentence[30];
    cin.getline(sentence,30);
    cout<<"your word : "<<sentence<<endl; 
    cout<<"length = " << strlen(sentence) <<endl;
    return 0;  
}
