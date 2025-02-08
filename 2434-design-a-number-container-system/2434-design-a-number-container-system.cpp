class NumberContainers {
public:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numsToIdx;
    unordered_map<int, int> idxToNums;

    NumberContainers() {
    }
    
    void change(int index, int number) {
        idxToNums[index] = number;

        numsToIdx[number].push(index);
    }
    
    int find(int number) {
        if (numsToIdx.count(number) == 0) return -1;

        auto& minHeap = numsToIdx[number];

        while(!minHeap.empty()) {
            int idx = minHeap.top();

            if (idxToNums[idx] == number) return idx;

            minHeap.pop();
        }

        return -1;
    }

    // void expand(int expandBy = 10) {
    //     int* newArr = new int[size+expandBy+1]{0};
    //     for (int i = 0; i < size; i++) {
    //         newArr[i] = nums[i];
    //     }
    //     delete[] nums;
    //     nums = newArr;
    //     size += expandBy;
    // }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */