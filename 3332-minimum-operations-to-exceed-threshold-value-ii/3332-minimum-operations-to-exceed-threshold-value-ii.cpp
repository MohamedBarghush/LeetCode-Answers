class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long> ms(nums.begin(), nums.end());
        int ans = 0;
        while (ms.size() > 1 && *ms.begin() < k) {
            auto it = ms.begin();
            long p1 = *it;
            ms.erase(it);
            it = ms.begin();
            long p2 = *it;
            ms.erase(it);
            
            ms.insert(2 * p1 + p2);
            ++ans;
        }
        return ans;
    }
};