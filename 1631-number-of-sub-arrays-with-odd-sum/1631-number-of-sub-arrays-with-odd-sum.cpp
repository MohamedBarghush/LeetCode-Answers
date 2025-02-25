class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int size=arr.size(), ans=0, odd=0, even=0, sum=0;
        for(int i=0; i<size; ++i)
        {
            sum+=arr[i];
            if(sum%2!=0)
            {
                ans=(ans+1)%1000000007;
                ans=(ans+even)%1000000007;
                odd++;
            }
            else
            {
                ans=(ans+odd)%1000000007;
                even++;
            }
        }
        return ans;
    }
};