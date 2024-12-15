class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
         // Lambda to calculate impact: the change in pass ratio by adding one student
        auto calculateImpact = [](int pass, long total) {
            double oldRatio = double(pass) / total;
            double newRatio = double(pass + 1) / (total + 1);
            return newRatio - oldRatio;
        };

        priority_queue<pair<double, int>> maxHeap;

        // Initialize the heap with the impact values of all classes
        for (int i = 0; i < classes.size(); i++) {
            int pass = classes[i][0];
            int total = classes[i][1];
            double impact = calculateImpact(pass, total);
            maxHeap.push({impact, i});
        }

        // Assign extra students to the classes with the highest impact
        while (extraStudents > 0) {
            auto [impact, classIndex] = maxHeap.top();
            maxHeap.pop();
            
            // Update the class: add one more student
            classes[classIndex][0] += 1;
            classes[classIndex][1] += 1;

            // Recalculate the impact after adding a student
            int pass = classes[classIndex][0];
            int total = classes[classIndex][1];
            double newImpact = calculateImpact(pass, total);

            // Push the updated impact back into the heap
            maxHeap.push({newImpact, classIndex});

            // Decrease the number of extra students
            extraStudents--;
        }

        // Calculate the total pass ratio after all students are assigned
        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [_, classIndex] = maxHeap.top();
            maxHeap.pop();
            totalRatio += double(classes[classIndex][0]) / classes[classIndex][1];
        }

        // Return the average pass ratio
        return totalRatio / classes.size();
    }
};