#include<iostream>
#include<vector>
using namespace std;
int countNegatives(vector<vector<int>>& grid) {
    int count = 0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]<0){
                count++;
            }
        }
    }
    cout<<count;
    return count;
}
int main() {
    vector<vector<int>> grid={{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    countNegatives(grid);
    return 0;
}
