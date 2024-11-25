class MinStack {
public:
    vector<int> theStack;
    vector<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        theStack.push_back(val);
        if (minStack.empty() || val <= minStack.back())
            minStack.push_back(val);
    }
    
    void pop() {
        if (!theStack.empty()) {
            if (theStack.back() == minStack.back())
                minStack.pop_back();
            theStack.pop_back();
        }
    }
    
    int top() {
        if (!theStack.empty())
            return theStack.back();
        throw runtime_error("Stack is empty");
    }
    
    int getMin() {
        if (!minStack.empty())
            return minStack.back();
        throw runtime_error("Stack is empty");
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */