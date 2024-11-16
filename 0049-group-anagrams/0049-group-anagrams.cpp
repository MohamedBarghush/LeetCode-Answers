class Solution {
public:
    long long primeHashMod(const std::string& word, long long mod) {
        std::unordered_map<char, long long> primeMap = {
            {'a', 2}, {'b', 3}, {'c', 5}, {'d', 7}, {'e', 11},
            {'f', 13}, {'g', 17}, {'h', 19}, {'i', 23}, {'j', 29},
            {'k', 31}, {'l', 37}, {'m', 41}, {'n', 43}, {'o', 47},
            {'p', 53}, {'q', 59}, {'r', 61}, {'s', 67}, {'t', 71},
            {'u', 73}, {'v', 79}, {'w', 83}, {'x', 89}, {'y', 97}, {'z', 101}
        };

        long long hash = 1;

        for (char c : word) {
            hash = (hash * primeMap[c]) % mod;
        }

        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
    
        for (string& str : strs) {
            string sortedStr = str;  // Make a copy of the string
            sort(sortedStr.begin(), sortedStr.end());  // Sort the string
            
            // Use the sorted string as the key to group anagrams
            anagramGroups[sortedStr].push_back(str);
        }
        
        vector<vector<string>> result;
        // Collect all groups of anagrams
        for (auto& entry : anagramGroups) {
            result.push_back(entry.second);
        }
        
        return result;
    }
};