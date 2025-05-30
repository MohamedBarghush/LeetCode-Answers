class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0, p1 = 0, p2 = 1;

        while (p1 < n) {
            if (colors[p2 % n] != colors[(p2+1) % n]) {
                if (p2 - p1 >= k - 1) {
                    p1++;
                    ans++;
                }
            } else {
                p1 = p2;
            }
            p2++;
        }

        return ans;
    }
};