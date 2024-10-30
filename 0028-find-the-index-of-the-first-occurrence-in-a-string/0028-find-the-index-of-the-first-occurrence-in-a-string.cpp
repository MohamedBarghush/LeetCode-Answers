class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[0]) {
                if (haystack.length() - i >= needle.length()) {
                    bool flag = false;
                    for (int j = 0; j < needle.length(); j++) {
                        if (needle[j] == haystack[i+j]) {
                            continue;
                        } else {
                            flag = true;
                            break;
                        }
                    }
                    if (!flag) return i;
                } else return -1;
            }
        }
        return -1;
    }
};