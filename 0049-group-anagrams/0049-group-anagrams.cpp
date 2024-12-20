class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> letter_groups;
    
        for (string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            
            letter_groups[sortedStr].push_back(str);
        }
        
        vector<vector<string>> output;
        for (auto& entry : letter_groups) {
            output.push_back(entry.second);
        }
        
        return output;
    }
};