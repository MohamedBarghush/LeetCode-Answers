class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>lst;
        int id =1;
        for(auto n : nums){
            if(lst.count(n)){
                if(id-lst[n]<=k)return true;
            }
            lst[n]=id++;
        }
        return false;
    }
};