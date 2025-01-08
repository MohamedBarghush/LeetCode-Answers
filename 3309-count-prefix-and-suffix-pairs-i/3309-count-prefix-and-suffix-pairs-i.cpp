class Solution {
public:
    bool isPrefixAndSuffix (string str1, string str2) {
        for (int i = 0; i < str1.length(); i++)
            if (str1[i] != str2[i] || str1[str1.length()-1-i] != str2[str2.length()-1-i]) 
            return false;
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for (int i = 0; i < words.size()-1; i++)
            for (int j = i+1; j < words.size(); j++)
                if (isPrefixAndSuffix(words[i], words[j]))
                    ans++;
        return ans;
    }
};