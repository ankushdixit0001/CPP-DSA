#include<iostream>
#include<string>
using namespace std;
void RemoveDub(string str, string ans,int i,int map[26]){
    if(i==str.size()){
        cout<<"ans : "<<ans;
    }
    int mapidx = (int)(str[i]-'a');
    if(map[mapidx]==true){
        RemoveDub(str,ans,i+1,map);
    }else{
        map[mapidx]=true;
        RemoveDub(str,ans+str[i],i+1,map);
    }
}
int main() {
    string str = "ankushdixit";
    string ans="";
    int map[26]={false};
    RemoveDub(str,ans,0,map);
    return 0;
}
