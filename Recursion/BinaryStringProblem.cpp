#include<iostream>
#include<string>
using namespace std;
void binstr(int n,string ans){
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    if(ans[ans.size()-1]!='1'){
        binstr(n-1,ans+'0');
        binstr(n-1,ans+'1');
    }
    else{
        binstr(n-1,ans+'0');
    }
}
int main() {
    string ans="";
    binstr(100,ans);
    return 0;
}
