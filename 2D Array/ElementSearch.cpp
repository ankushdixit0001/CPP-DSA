#include<iostream>
using namespace std;

void TravSearch(int mat[][3] , int n , int key){
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<n;j++){
            if(mat[i][j]==key){
                cout<<"row = "<<i+1<<"column = "<<j+1;
            }
        }
    }
}

bool StairSearch( int mat[][3] , int n , int m , int key){
    int i=0 , j=n-1;

    while (i<n&&j>=0)
    {
        if (mat[i][j]==key)
        {
            cout<<"found at cell ("<<i<<","<<j<<")\n";
            return true;
        } else if(mat[i][j]>key){

            j--;
        }
        else{

            i++;
        }
    }
    cout<<"key not found\n";
    return false;
}


int main() {
    int mat[3][3]={{10,20,30},
                 {15,25,35},
                 {27,33,39}};
    StairSearch(mat,3,3 ,27);
    return 0;
}
