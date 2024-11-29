class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 0;
        int l=0,r = nums.size(),m;
        // binary search on the size of the array
        while(l <= r){
            m = (l + r) / 2;
            int sum{};
            for(int i = 0; i < m ; i++){
                sum += nums[i];
            }
            bool ch = sum >=target;
            for(int i = m; i < nums.size() ; i++){
                sum -= nums[i-m];
                sum += nums[i];
                if(sum >= target){
                    ch = 1;
                    break;
                }
            }
            if(ch){
                ans = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return ans;
    }
};
