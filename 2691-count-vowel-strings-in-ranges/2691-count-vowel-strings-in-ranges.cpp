class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        vector<int> prefix (words.size(), 0);
        if (vowels.count(words[0][0]) && vowels.count(words[0].back())) prefix[0] = 1;
        for (int i = 1; i < words.size(); i++)
            prefix[i] = prefix[i - 1] + ((vowels.count(words[i][0]) && vowels.count(words[i].back())) ? 1 : 0);

        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++)
            ans[i] = prefix[queries[i][1]] - (queries[i][0] > 0 ? prefix[queries[i][0]-1] : 0);

        
        return ans;
    }
};
