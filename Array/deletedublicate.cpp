#include<iostream>
using namespace std;
int removeDuplicates(int* nums, int numsSize) {
    int k=0;
    for(int i = 0; i<numsSize;i++){
        for(int j = i+1; j<numsSize; j++){
            if(nums[i]==nums[j]){
                k++;
               while(j<numsSize){
                nums[j]=nums[j+1];
                j++;
               }
               numsSize--;
            }
        }
    }
    for(int i=0;i<numsSize;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<k;
    return 0;
}

int removeDuplicates2(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int k = 1 ; // Start with the first element being unique
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl << k;
    return k;
}

int main() {
    int nums[] = {1,2,2,3,4,5,4,4,6,6};
    int numsSize = sizeof(nums)/sizeof(int);
    removeDuplicates2(nums , numsSize);
    return 0;
}
