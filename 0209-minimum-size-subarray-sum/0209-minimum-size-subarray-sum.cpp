class Solution {
public:
    int ans = -1;
    void binary_shit (vector<int>& nums, int l, int r,int target) {
        if (l > r){
            return;
        }
        int m = (l + r) / 2,sum{},l2{},r2{};
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
            binary_shit(nums,l,m - 1, target);
        }
        else{
             binary_shit(nums,m + 1,r, target);
        }
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum >= target) ans = nums.size();
         binary_shit(nums, 1, nums.size(), target);
         return ans == -1 ? 0:ans;
    }
};