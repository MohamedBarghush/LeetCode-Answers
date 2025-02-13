class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        priority_queue<long, std::vector<long>, std::greater<long>> pq(nums.begin(), nums.end());

        while (pq.size() > 1 && pq.top() < k) {
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