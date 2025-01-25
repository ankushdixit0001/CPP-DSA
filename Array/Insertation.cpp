#include<iostream>
using namespace std;

int main() {
    // Initial array with one extra space for the new element
    int arr[8] = {1, 2, 3, 5, 6, 7, 8};
    int n = 7; // Current number of elements in the array
    int pos = 4; // Position where new element will be inserted
    int x = 5; // New element to be inserted

    // Display original array
    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Shift elements to the right to make space for new element
    for(int i=n; i>pos;i--) {
        arr[i]=arr[i-1];
    }

    // Insert new element at the specified position
    arr[pos]=x;
    n++; // Increase the size of the array

    // Display updated array
    cout << "Updated array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "n = " << n << endl;

    return 0;
}
