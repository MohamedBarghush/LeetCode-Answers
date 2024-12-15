class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // lambda function to calculate impact
        auto calculateImpact = [](int pass, long total) {
            double oldRatio = double(pass) / total;
            double newRatio = double(pass + 1) / (total + 1);
            return newRatio - oldRatio;
        };

        priority_queue<pair<double, int>> maxHeap;

        for (int i = 0; i < classes.size(); i++) {
            double impact = calculateImpact(classes[i][0], classes[i][1]);
            maxHeap.push({impact, i});
        }

        while (extraStudents > 0) {
            auto [impact, classer] = maxHeap.top();
            maxHeap.pop();
            classes[classer][0] += 1;
            classes[classer][1] += 1;
            impact = calculateImpact(classes[classer][0], classes[classer][1]);
            maxHeap.push({impact, classer});
            extraStudents--;
        }

        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [_, cls] = maxHeap.top();
            maxHeap.pop();
            totalRatio += double(classes[cls][0]) / classes[cls][1];
        }

        return totalRatio / classes.size();
    }
};