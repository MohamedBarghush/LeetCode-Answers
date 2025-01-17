class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xori = 0;
        for (int e : derived)
            xori = xori ^ e;

        return xori == 0;
    }
};