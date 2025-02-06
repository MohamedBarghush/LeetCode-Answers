class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, unsigned char> daMap;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                daMap[nums[i]*nums[j]]++;
            }
        }

        int ans = 0;
        for (auto& [_, key] : daMap) {
            int count = key;
            if (count > 1) {
                ans += 4 * (count * (count - 1));
            }
        }

        return ans;
    }
};