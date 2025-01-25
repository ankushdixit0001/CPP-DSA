#include <iostream>
#include <vector>
using namespace std;
void merge(int arr[], int si, int mid, int ei)//O(n)
{
    vector<int> temp;
    int i = si;
    int j = mid + 1;

    while (i <= mid && j <= ei)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    // if array complete
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= ei)
    {
        temp.push_back(arr[j++]);
    }
    // copy to prg
    for (int idx = si, x = 0; idx <= ei; idx++)
    {
        arr[idx] = temp[x++];
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void mergeSort(int arr[], int si, int ei)//O(log n)
{
    if (si >= ei)
    {
        return;
    }
    int mid = (si + ei) / 2;

    mergeSort(arr, si, mid);     // left
    mergeSort(arr, mid + 1, ei); // right

    merge(arr, si, mid, ei); // conquer
}
int main()
{
    int arr[] = {6, 3, 7, 5, 2, 4};
    int n = 6;
    mergeSort(arr, 0, n - 1);
    print(arr, n);
    return 0;
}