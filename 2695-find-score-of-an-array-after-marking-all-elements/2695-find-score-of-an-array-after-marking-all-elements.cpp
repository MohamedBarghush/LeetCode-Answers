class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        std::vector<std::pair<int, int>> elements; // Pair of (value, index)

        // Store values and their indices
        for (int i = 0; i < n; i++) {
            elements.emplace_back(nums[i], i);
        }

        // Sort by value first, and by index second
        std::sort(elements.begin(), elements.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second; // If values are equal, sort by index
            }
            return a.first < b.first; // Otherwise, sort by value
        });

        std::vector<bool> marked(n, false); // To track marked elements
        long long score = 0;

        // Process each element in sorted order
        for (const auto& [value, index] : elements) {
            if (!marked[index]) { // If the element is not marked
                score += value;  // Add its value to the score

                // Mark the element and its adjacent elements
                marked[index] = true;
                if (index > 0) {
                    marked[index - 1] = true;
                }
                if (index < n - 1) {
                    marked[index + 1] = true;
                }
            }
        }

        return score;
    }
};