class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>lst;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(lst.count(nums[i])){
                if(i-lst[nums[i]]<=k)return true;
            }
            lst[nums[i]]=i;
        }
        return false;
    }
};