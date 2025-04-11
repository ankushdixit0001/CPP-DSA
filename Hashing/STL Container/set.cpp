#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s;

    // Insert elements into the set (O(log n))
    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(2);

    // Print the size of the set
    cout << "Size of set: " << s.size() << endl;

    // Try inserting a duplicate element (won't be added)
    s.insert(2); 
    cout << "Size after inserting duplicate '2': " << s.size() << endl;

    // Check if an element exists using find() (O(log n))
    if (s.find(3) != s.end()) {
        cout << "3 exists in the set\n";
    } else {
        cout << "3 doesn't exist in the set\n";
    }

    // Delete an element from the set using erase() (O(log n))
    s.erase(3);

    // Iterate through the set and print all elements
    // **set maintains sorted order**
    cout << "Elements in the set (Sorted):\n";
    for (const auto& el : s) {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}