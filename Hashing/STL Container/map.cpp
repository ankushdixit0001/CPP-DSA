#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> m;

    // Insert elements into the map (O(log n))
    m["china"] = 150;
    m["india"] = 150;
    m["us"] = 50;
    m["nepal"] = 10;

    // Access elements using key lookup (O(log n))
    cout << "Population of India: " << m["india"] << endl;

    // Iterate through the map and print all elements (O(n))
    // map stores elements in **sorted order** by default
    cout << "\nCountry-wise Population Data (Sorted by Key):\n";
    for (const auto& country : m) {
        cout << country.first << " -> " << country.second << endl;
    }

    // Check if a key exists using count() (O(log n))
    cout << "\nDoes 'india' exist in the map? " << (m.count("india") ? "Yes" : "No") << endl;

    // Update the value of an existing key (O(log n))
    m["india"] = 140;
    cout << "Updated population of India: " << m["india"] << endl;

    // Delete an element from the map using erase() (O(log n))
    m.erase("india");

    // Print the map after deletion
    cout << "\nMap after erasing 'india' (Still Sorted):\n";
    for (const auto& country : m) {
        cout << country.first << " -> " << country.second << endl;
    }

    return 0;
}