class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<float,int> base;
        for (int i = 0; i < arr.size(); i++) {
            if (base.count(arr[i]*2) || base.count(float(arr[i])/2.0f))
                return true;
            base[arr[i]]++;
        }
        return false;
    }
};