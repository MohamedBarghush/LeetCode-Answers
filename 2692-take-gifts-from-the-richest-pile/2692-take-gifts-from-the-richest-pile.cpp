class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap;
        long long extra = 0;
        for (int a : gifts) {
            maxHeap.push(a);
            extra += a;
        }

        for (int i = 0; i < k; i++) {
            int top = maxHeap.top();
            int remain = sqrt(maxHeap.top());
            extra -= top;
            extra += remain;
            maxHeap.pop();
            maxHeap.push(remain);
        }

        return extra;
    }
};