class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=0;
        for(int it: nums){
            sum+=it;
            if(sum<0)
                sum=0;
            ans=max(sum,ans);
        }
        return ans;
    }
};