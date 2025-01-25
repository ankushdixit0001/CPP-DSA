#include<iostream>
#include<vector>
using namespace std;
int maxActivities(vector<int> start, vector<int> end){
    //sort on endtime
    //A0 select
    cout<<"seleted activity : A0"<<endl;
    int count=1;
    int currEndTime=end[0];

    for(int i=1;i<start.size();i++){
        if(start[i]>=currEndTime){//non-overlapping
            cout<<"seleted activity : A"<<i<<endl;
            count++;
            currEndTime=end[i];
        }
    }
    return count;
}
int main() {
    vector<int> start={10,12,20};
    vector<int> end={20,25,30};
    cout<<maxActivities(start,end);
    return 0;
}
