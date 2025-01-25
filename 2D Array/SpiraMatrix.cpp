#include<iostream>
using namespace std;

void spiralmatrix(int matrix[][4] , int n , int m){
   int srow = 0 , scol = 0;
   int erow = n-1 , ecol = m-1;
   while (srow<=erow && scol<=ecol)
   {
    // top 
    for(int j=scol ; j<=ecol;j++){
        cout<<matrix[srow][j]<< " ";
    }
    // right 
    for(int i =srow+1 ; i<=erow;i++){
        cout<<matrix[i][ecol]<< " ";
    }
    // bottem 
    for(int j =ecol-1 ; j>=scol;j--){
        cout<<matrix[erow][j]<< " ";
    }
    // left 
    for(int i =erow-1 ; i>=srow+1;i--){
        cout<<matrix[i][scol]<< " ";
    }
    scol++;  srow++;
    ecol--;
    erow--;
   }
}

int main() {
    int matrix[3][4]={{22,33,55,4},
                    {64,56,34,5},
                    {34,67,23,7}};
    spiralmatrix(matrix , 3,4);
    return 0;
}
