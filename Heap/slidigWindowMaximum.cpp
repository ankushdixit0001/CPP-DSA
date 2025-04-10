#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void slidingWindowMax(vector<int> arr,int k){
    priority_queue<pair<int,int>> pq;

    //ist window
    for(int i=0;i<k;i++){
        pq.push(make_pair(arr[i],i));
    }
    cout<<"output : "<<pq.top().first<<" ";
    for(int i=k;i<arr.size();i++){
        while(!pq.empty()&&pq.top().second<=(i-k)){
            pq.pop();
        }
        pq.push(make_pair(arr[i],i));
        cout<<pq.top().first<<" ";
    }
}

int main() {
    vector<int> arr={2,1,3,5,4,6,4,8,9};
    slidingWindowMax(arr,3);
    return 0;
}
