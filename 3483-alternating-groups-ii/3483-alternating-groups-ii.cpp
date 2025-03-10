class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0, p1 = 0, p2 = 1;

        // bit optimized
        while (p1 < n) {
            int val = p2 % n;
            if (colors[val] != colors[(val+1) % n]) {
                if (p2 - p1 < k - 1) {
                    p2++;
                } else {
                    p1++;
                    p2++;
                    ans++;
                }
            } else {
                p1 = p2;
                p2++;
            }
        }

        return ans;
    }
};