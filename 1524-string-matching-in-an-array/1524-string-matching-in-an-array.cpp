class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        // sort(words.begin(), words.end(), [](const string &a, const string &b) {
        //     return a.length() < b.length();
        // });

        vector<string> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int k = 0;
                bool flag = true;
                for (int l = 0; l < words[j].length(); l++) {
                    if (words[i][k] == words[j][l])
                        k++;
                    else {
                        if (k > 0)
                            l -= k;
                        k = 0;
                    }

                    if (k == words[i].length()) {
                        ans.push_back(words[i]);
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
        }

        return ans;
    }
};