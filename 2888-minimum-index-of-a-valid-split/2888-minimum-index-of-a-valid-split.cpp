class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> firstMap, secondMap;
        for (int num : nums) {
            secondMap[num]++;
        }

        int i = 0;
        for (int num : nums) {
            firstMap[num]++;
            secondMap[num]--;

            if (firstMap[num]*2 > (i+1) && secondMap[num]*2 > (nums.size() - i - 1)) return i;

            i++;
        }

        return -1;
    }
};