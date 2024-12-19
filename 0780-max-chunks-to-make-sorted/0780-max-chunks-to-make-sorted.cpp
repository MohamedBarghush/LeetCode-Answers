class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> myStack;

        for (int i = 0; i < arr.size(); i++) {
            if (myStack.empty() || arr[i] >= myStack.top()) {
                myStack.push(arr[i]);
            } else {
                int maxVal = myStack.top();
                myStack.pop();
                while (!myStack.empty() && myStack.top() > arr[i])
                    myStack.pop();
                myStack.push(maxVal);
            }
        }

        return myStack.size(); 
    }
};