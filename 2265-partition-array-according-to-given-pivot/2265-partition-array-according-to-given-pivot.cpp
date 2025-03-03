class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int pivotCount = 0, n = nums.size();
        vector<int> ans(n, 0);
        int j = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans[j] = nums[i];
                j++;
            } else if (nums[i] == pivot) {
                pivotCount++;
            }
        }
        for (int i = 0; i < pivotCount; i++) {
            ans[j] = pivot;
            j++;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > pivot){
                ans[j] = nums[i];
                j++;
            }
        }
        
        return ans;
    }
};