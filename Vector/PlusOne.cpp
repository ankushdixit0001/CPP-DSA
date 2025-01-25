#include<iostream>
#include<vector>
#include<algorithm>
// #include<deque>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                digits[i]++;
            }
            if (digits[i] == 10) {
                digits[i] = 0;
                if (i != 0) {
                    digits[i - 1]++;
                } else {
                    digits.push_back(0);
                    digits[i] = 1;
                }
            }
        }  
    return digits;
}
int main() {
    vector<int> digits = {9,9};
    plusOne(digits);
    for(int i=0;i<digits.size();i++){
        cout<<digits[i]<<" ";
    }
    return 0;
}
