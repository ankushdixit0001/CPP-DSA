#include<iostream>
#include<vector>
using namespace std;

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        if(n==0){
            return matrix;
        }
        int top=0;
        int left=0;
        int right=n-1;
        int bottom=n-1;
        int count=1;
        while(left<=right&& top<=bottom){
            for(int i=left;i<=right;i++){
                matrix[top][i]=count;
                count++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                matrix[i][right]=count;
                count++;
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    matrix[bottom][i]=count;
                    count++;
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    matrix[i][left]=count;
                    count++;
                }
                left++;
            }
        }

    for (int i = 0; i <matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

        return matrix;
    }

int main() {
    generateMatrix(3);
    return 0;
}
