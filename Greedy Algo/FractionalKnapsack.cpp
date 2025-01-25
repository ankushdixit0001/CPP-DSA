#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<double,int> p1,pair<double,int>p2){
    return p1.first>p2.first;
}
int fractionalKnapsack(vector<int> val, vector<int> wt, int w){
    int n=val.size();
    vector<pair<double, int>>ratio(n,make_pair(0.0,0));
    for(int i=0;i<n;i++){
        double r=val[i]/(double)wt[i];
        ratio[i]=make_pair(r,i);
    }
    sort(ratio.begin(),ratio.end(),compare);
    int ans=0;
    for(int i=0;i<n;i++){
        int idx=ratio[i].second;
        if(wt[idx]<=w){
            ans+=val[idx];
            w-=wt[idx];
        }
        else{
            ans+=ratio[i].first*w;
            w=0;
            break;
        }
    }
    cout<<ans;
    return ans;
}
int main() {
    vector<int> val={60,100,120};
    vector<int> wt={10,20,30};
    int w=50;
    fractionalKnapsack(val,wt,w);
    return 0;
}
 