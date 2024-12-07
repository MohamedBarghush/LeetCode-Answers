class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lowest = 1, highest = 1e9;
        while (lowest < highest) {
            int mid = lowest + (highest - lowest) / 2;
            int ops = 0;
            for (int n : nums) {
                ops += (n-1) / mid;
                if (ops > maxOperations) 
                    break;
            }
            if (ops <= maxOperations) 
                highest = mid;
            else 
                lowest = mid + 1;
        }
        return highest;
    }
};
