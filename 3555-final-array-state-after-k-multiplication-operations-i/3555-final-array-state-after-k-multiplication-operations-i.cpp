class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first)
                return a.second > b.second; // Smaller index has higher priority
            return a.first > b.first; // Smaller number has higher priority
        }
    };
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap;

        for (int i = 0; i < nums.size(); i++) {
            heap.push({nums[i], i});
        }

        while (k > 0) {
            auto [_, idx] = heap.top();
            heap.pop();
            nums[idx] *= multiplier;
            heap.push({nums[idx], idx});
            k--;
        }

        return nums;
    }
};