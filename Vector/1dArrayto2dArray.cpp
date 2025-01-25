#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    int length = original.size();
    if(length!=m*n){
        return {};
    }
    vector<vector<int>> ans(m,vector<int> (n));
    int x=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=original[x++];
        }
    }
    for (int i = 0; i <ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    vector<int> original={1,2,3};
    int m = 1,n=3;
    construct2DArray(original,m,n);
    return 0;
}
