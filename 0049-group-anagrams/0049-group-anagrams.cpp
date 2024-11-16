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
        vector<vector<string>> output;
        unordered_map<int, vector<int>> hash_maps; // <val, indices>

        int mod = 1000000007;

        for (int i = 0; i < strs.size(); i++) {
            int val = primeHashMod(strs[i], mod);
            hash_maps[val].push_back(i);
        }

        int i = 0;
        for (const auto& [key, value] : hash_maps) {
            vector<string> result;
            for (int v : value) {
                result.push_back(strs[v]);
            }
            i++;
            output.push_back(result);
        }

        return output;
    }
};