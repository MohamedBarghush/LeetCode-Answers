class Solution {
public:
    bool isValid(string s) {
        stack<char> ourStack;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') ourStack.push(ch);
            else {
                if (ourStack.size() == 0) return false;
                if (ch == ')' && ourStack.top() == '(') ourStack.pop();
                else if (ch == ']' && ourStack.top() == '[') ourStack.pop();
                else if (ch == '}' && ourStack.top() == '{') ourStack.pop();
                else return false;
            }
        }

        return ourStack.size() == 0;
    }
};