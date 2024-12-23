/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minSwaps(vector<int>& arr) {
        
        vector<pair<int,int>>v;
        for(int i=0; i<arr.size(); i++)
            v.push_back({arr[i],i}); // {value,index}
        
        sort(v.begin(), v.end());
        int swaps = 0;
        
        for(int i=0; i<arr.size(); i++){
            
            pair<int,int>p = v[i];
            int index = p.second;
            
            while(i != index){
                
                swaps++;
                swap(v[i], v[index]);
                index = v[i].second;
                
            }
        }
        
        return swaps;
    }


    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*>qu;
        qu.push(root);

        int ans = 0;
        vector<int>levelOrder;

        while(!qu.empty()){

            levelOrder.clear();
            int n = qu.size();
            for(int i=0; i<n; i++){

                TreeNode* temp = qu.front();
                qu.pop();
                levelOrder.push_back(temp->val);

                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
            }

            int minimumSwaps = minSwaps(levelOrder);
            ans += minimumSwaps;
        }

        return ans;
    }
};