class Solution {
public:
    int strStr(string haystack, string needle) {
        // if (needle.length() > haystack.length()) return -1;
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[0]) {
                if (haystack.length() - i >= needle.length()) {
                    bool flag = false;
                    for (int j = 0; j < needle.length(); j++) {
                        if (needle[j] == haystack[i+j]) {
                            // cout << "found match of " << needle[j] << " with index " << i+j << endl;
                            continue;
                        } else {
                            // cout << "broken at " << j << " from " << needle[j] << endl;
                            flag = true;
                            break;
                        }
                    }
                    // cout << "reached return " << endl;
                    if (!flag) return i;
                } else return -1;
            }
        }
        return -1;
    }
};