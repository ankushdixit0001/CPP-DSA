#include<iostream>
using namespace std;

void maxprofit( int prices[] , int n){
    int bestBuy[100000];
    bestBuy[0]=INT8_MAX; 
    cout<<bestBuy[0];
    for(int i=1;i<n;i++){
        bestBuy[i]=min(bestBuy[i-1],prices[i-1]);
        cout<<bestBuy[i]<<",";

    }
    cout<<endl;

    int maxprofit =0;
    for(int i=0; i<n;i++){
        int currprofit = prices[i]-bestBuy[i];
        maxprofit = max(maxprofit,currprofit);
    }
    cout<<"max profit = " <<maxprofit;
}

int main() {
      int prices[6]={7,1,5,3,6,4};
      int n = sizeof(prices)/sizeof(int);
    maxprofit(prices , n);

    return 0;
}
