class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // lambda function to calculate the impact
        auto calculateImpact = [](int pass, long total) {
            double oldRatio = double(pass) / total;
            double newRatio = double(pass + 1) / (total + 1);
            return newRatio - oldRatio;
        };

        priority_queue<pair<double, int>> maxHeap;

        for (int i = 0; i < classes.size(); i++) {
            int pass = classes[i][0];
            int total = classes[i][1];
            double impact = calculateImpact(pass, total);
            maxHeap.push({impact, i});
        }

        while (extraStudents > 0) {
            auto [impact, classIndex] = maxHeap.top();
            maxHeap.pop();
            
            classes[classIndex][0] += 1;
            classes[classIndex][1] += 1;

            double newImpact = calculateImpact(classes[classIndex][0], classes[classIndex][1]);

            maxHeap.push({newImpact, classIndex});

            extraStudents--;
        }

        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [_, classIndex] = maxHeap.top();
            maxHeap.pop();
            totalRatio += double(classes[classIndex][0]) / classes[classIndex][1];
        }

        return totalRatio / classes.size();
    }
};