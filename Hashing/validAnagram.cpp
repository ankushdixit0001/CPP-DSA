#include <iostream>
#include <unordered_map>

using namespace std;

// Function to check if two strings are anagrams
bool isValidAnagram(const string& s, const string& t) {
    // Anagrams must be of the same length
    if (s.size() != t.size()) return false;

    unordered_map<char, int> freqMap;  // Stores character frequencies

    // Step 1: Count occurrences of each character in `s` (O(n))
    for (char ch : s) {
        freqMap[ch]++;
    }

    // Step 2: Decrease occurrences based on characters in `t` (O(n))
    for (char ch : t) {
        if (freqMap.count(ch)) { 
            freqMap[ch]--;
            if (freqMap[ch] == 0) {
                freqMap.erase(ch);  // Remove entry when count reaches zero
            }
        } else {
            return false;  // If any character is missing, not an anagram
        }
    }

    // If map is empty, `s` and `t` are anagrams
    return freqMap.empty();
}

int main() {
    // Multiple test cases to verify correctness
    string testCases[][2] = {
        {"race", "care"},     // Anagram
        {"listen", "silent"}, // Anagram
        {"hello", "world"},   // Not anagram
        {"abc", "abcd"},      // Different lengths
        {"", ""},             // Empty strings (valid anagram)
        {"aabb", "bbaa"},     // Anagram
        {"anagram", "nagaram"}, // Anagram
        {"rat", "car"}        // Not anagram
    };

    // Run test cases
    for (const auto& test : testCases) {
        cout << "Comparing: " << test[0] << " & " << test[1] << " -> ";
        if (isValidAnagram(test[0], test[1])) {
            cout << "Yes, they are anagrams!" << endl;
        } else {
            cout << "No, they are not anagrams!" << endl;
        }
    }

    return 0;
}