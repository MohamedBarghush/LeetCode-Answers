class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int curr = 101;
        int p1 = 0, p2 = k-1, n = blocks.length();
        while (p2 < n) {
            int swaps = 0;
            for (int i = p1; i <= p2; i++)
                if (blocks[i] == 'W') swaps++;
            curr = min(swaps, curr);
            p1++;
            p2++;
        }

        return curr;
    }
};