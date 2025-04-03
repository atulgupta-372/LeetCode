class Solution {
    public:
    
        int findTargetSumWays(vector<int>& nums, int target) {
            int sum=accumulate(nums.begin(),nums.end(),0);
            if(target+sum <0 || (target+sum)%2==1) return 0;
            int tsum=(target+sum)/2;
            vector<int>dp(tsum+1,0);
            dp[0]=1;
            for(auto it:nums){
                for(int i=tsum;i>=it;i--){
                    dp[i]+=dp[i-it];
                }
            }
            return dp[tsum];
        }
    };