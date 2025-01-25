#include<iostream>
#include<vector>
using namespace std;

int main() {
    //we can make diff size of row and col 
    vector <vector<int>> matrix = {{1,2,3},{4,5},{7,8,9 ,3,4}};

    for (int i = 0; i <matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
