class Solution {
public:
    int sum_of_digits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        // unordered_map<int, int> num_map;
        vector<int> num_map(82, 0);
        int max_sum = -1;

        for (int num : nums) {
            int digit_sum = sum_of_digits(num);
            if (num_map[digit_sum] != 0)
                max_sum = max(max_sum, num + num_map[digit_sum]);
            num_map[digit_sum] = max(num, num_map[digit_sum]);
        }

        return max_sum;
    }
};