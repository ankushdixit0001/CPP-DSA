#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        unordered_map<string, vector<string>> groupedAnagrams;
        // Group anagrams together using their sorted string as key 
        for (string s : arr) { 
            string sortedStr = s; 
            sort(sortedStr.begin(), sortedStr.end()); 
            groupedAnagrams[sortedStr].push_back(s); 
            
        } 
        // Collect the groups and sort them lexicographically 
        vector<vector<string>> result; 
        for (auto& pair : groupedAnagrams) {
            vector<string> group = pair.second;
            result.push_back(group);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> arr = {"act", "god", "cat", "dog", "tac"};
    vector<vector<string>> result = solution.anagrams(arr);

    // Print the result
    for (const auto& group : result) {
        for (const auto& str : group) {
            printf("%s ", str.c_str());
        }
        printf("\n");
    }

    return 0;
}
