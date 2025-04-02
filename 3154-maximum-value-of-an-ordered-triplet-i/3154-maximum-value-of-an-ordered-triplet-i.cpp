class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        short n = nums.size();
        long long ans=0;
        for (short i = 0; i < n; i++) {
            for (short j = i+1; j < n; j++) {
                for (short k = j+1; k < n; k++) {
                    long long val=(long long)(nums[i]-nums[j])*nums[k];
                    // val += ;
                    ans = max(ans, val);
                }
            }
        }

        return ans;
    }
};