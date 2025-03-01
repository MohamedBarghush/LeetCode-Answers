class Solution {
public:
    int climbStairs(int n) {
        int prev=1, curr=1;
        for(short i = 2; i <= n; i++) {
            int temp = curr + prev;
            prev = curr;
            curr = temp;
        }

        return curr;
    }
};