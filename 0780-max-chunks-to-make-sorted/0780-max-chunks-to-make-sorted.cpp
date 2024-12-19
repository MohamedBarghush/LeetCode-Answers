class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxYet = 0;
        int chunks = 0;
        for (int i = 0; i < arr.size(); i++) {
            maxYet = max(maxYet, arr[i]);
            if (maxYet == i)
                chunks++;
        }
        return chunks;  
    }
};