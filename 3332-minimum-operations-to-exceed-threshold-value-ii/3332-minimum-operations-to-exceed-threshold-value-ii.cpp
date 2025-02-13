class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), badVals = 0, stopIdx = 0, ans = 0;
        priority_queue<long, std::vector<long>, std::greater<long>> pq;
        for (int num : nums)
            pq.push(num);

        while (pq.size() >= 2) {
            if (pq.top() >= k) break;
            long p1 = pq.top();
            pq.pop();
            long p2 = pq.top();
            pq.pop();

            pq.push(p1 * 2 + p2);
            ans++;
        }

        return ans;
    }
};