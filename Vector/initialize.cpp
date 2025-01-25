#include<iostream>
#include<vector>
using namespace std;

    int main() {
    // vector<int> vec1={1,1,23,3};
    vector<int> vec1(10,2);
    cout<<vec1.size()<<"\n";

    for(int i=0;i<vec1.size();i++){
         cout<< vec1[i]<< " ";
    }
    return 0;
}
