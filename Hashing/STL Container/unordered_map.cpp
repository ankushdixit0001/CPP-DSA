#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> m;

    // Insert elements into the unordered_map (O(1) average, O(n) worst case)
    m["china"] = 150;
    m["india"] = 150;
    m["us"] = 50;
    m["nepal"] = 10;

    // Access elements using key lookup (O(1) average, O(n) worst case)
    cout << "Population of India: " << m["india"] << endl;

    // Iterate through the map and print all elements (O(n))
    cout << "\nCountry-wise Population Data:\n";
    for (const auto& country : m) {
        cout << country.first << " -> " << country.second << endl;
    }

    // Check if a key exists using count() (O(1) average, O(n) worst case)
    cout << "\nDoes 'india' exist in the map? " << (m.count("india") ? "Yes" : "No") << endl;

    // Update the value of an existing key (O(1) average, O(n) worst case)
    m["india"] = 140;
    cout << "Updated population of India: " << m["india"] << endl;

    // Delete an element from the map using erase() (O(1) average, O(n) worst case)
    m.erase("india");

    // Print the map after deletion
    cout << "\nMap after erasing 'india':\n";
    for (const auto& country : m) {
        cout << country.first << " -> " << country.second << endl;
    }

    return 0;
}