
class Solution {
    public:
        long long min(long long a,long long b){
            return a<b?a:b;
        }
        long long ana(long long l,long long r,int k){
            if(l+r-1<=k)
                return l*r;
            l = min(l,k);
            r = min(r,k);
            long long output=0;
            output += (k-r+1)*r;
            output+=(r+k-l)*(l+r-k-1)/2;
            return output;
        }
    
        long long minMaxSubarraySum(vector<int>& nums, int k) {
            int n = nums.size();
            long long output=0;
            vector<int> stack;
            stack.push_back(-1);
            nums.push_back(INT_MIN);
            for(int i=0;i<=n;i++){
                while(stack.size()>1 && nums[stack.back()]>=nums[i]){
                    int now_index = stack.back();
                    stack.pop_back();
                    long long l = now_index - stack.back();
                    long long r = i - now_index;
                    output+= (ana(l,r,k)*nums[now_index]);
                    output = output;
                }
                stack.push_back(i);
            }
    
            stack.clear();
            stack.push_back(-1);
            nums.pop_back();
            nums.push_back(INT_MAX);
            for(int i=0;i<=n;i++){
                while(stack.size()>1 && nums[stack.back()]<=nums[i]){
                    int now_index = stack.back();
                    stack.pop_back();
                    long long l = now_index - stack.back();
                    long long r = i - now_index;
                    output+= (ana(l,r,k)*nums[now_index]);
                    output = output;
                }
                stack.push_back(i);
            }
            return output;
        }
    };
