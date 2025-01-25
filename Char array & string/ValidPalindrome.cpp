#include<iostream>
#include<string.h>
using namespace std;
bool isvalidP( char world[] , int n){
    int start=0, end=n-1;
    while(start<end){
        if(world[start] != world[end]){
            cout<<"not valid palindrome"<<endl;
            return false;
        }
        start++;
        end--;
    }
     cout<<"valid palindrome"<<endl;
    return true;
 }

int main() {
    char word[20];
    cin.getline(word , 20);
    isvalidP(word , strlen(word));
    return 0;
}
