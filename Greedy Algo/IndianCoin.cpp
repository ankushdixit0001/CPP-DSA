#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getMinChange(vector<int> coins,int V){
    int ans=0;
    int n=coins.size();
    sort(coins.begin(),coins.end());
    for(int i=n-1;i>=0&&V>0;i--){
        if(V>=coins[i]){
            ans+=V/coins[i];
            V=V%coins[i];
        }
    }
    if(V!=0){
        cout<<" not possible";
        return -1;
    }
    cout<<"Min coin for change = "<<ans<<endl;
    return ans;
}
int main() {
    vector<int> coins={1,2,5,10,20,50,100,500,2000};
    int V=1099;
    getMinChange(coins,V);
    return 0;
}
