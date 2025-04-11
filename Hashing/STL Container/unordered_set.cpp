#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> s;

    // Insert elements into the unordered_set (O(1) average, O(n) worst case)
    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(2);

    // Print the size of the set
    cout << "Size of set: " << s.size() << endl;

    // Try inserting a duplicate element (won't be added)
    s.insert(2);
    cout << "Size after inserting duplicate '2': " << s.size() << endl;

    // Check if an element exists in the set using find() (O(1) average, O(n) worst case)
    if (s.find(3) != s.end()) {
        cout << "3 exists in the set\n";
    } else {
        cout << "3 doesn't exist in the set\n";
    }

    // Delete an element from the set using erase() (O(1) average, O(n) worst case)
    s.erase(3);

    // Iterate through the set and print all elements
    // unordered_set **does not maintain any order**
    cout << "Elements in the set:\n";
    for (const auto& el : s) {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}