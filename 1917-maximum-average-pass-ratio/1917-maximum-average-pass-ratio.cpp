class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto calculateImpact = [](int pass, long total) {
            double oldRatio = double(pass) / total;
            double newRatio = double(pass + 1) / (total + 1);
            return newRatio - oldRatio;
        };

        priority_queue<pair<double, pair<int, int>>> maxHeap;

        for (auto& cls : classes) {
            int pass = cls[0];
            int total = cls[1];
            double impact = calculateImpact(pass, total);
            maxHeap.push({impact, {pass, total}});
        }

        while (extraStudents > 0) {
            auto [impact, classer] = maxHeap.top();
            maxHeap.pop();
            impact = calculateImpact(classer.first + 1, classer.second + 1);
            maxHeap.push({impact, {classer.first + 1, classer.second + 1}});
            extraStudents--;
        }

        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [_, cls] = maxHeap.top();
            maxHeap.pop();
            totalRatio += double(cls.first) / cls.second;
        }

        return totalRatio / classes.size();
    }
};