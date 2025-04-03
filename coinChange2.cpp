class Solution {
    public:
    
        int solve(vector<int>& coins, int idx,int A,vector<vector<int>>&dp){
            if(A==0)    return 1;
            if(idx==0){
                if(A%coins[0]==0) return 1;
                else return 0;
            }
            if(dp[idx][A]!=-1)  return dp[idx][A];  
            int ntake=solve(coins,idx-1,A,dp);
            int take=0;
            if(coins[idx]<=A){
                take=solve(coins,idx,A-coins[idx],dp);
            }
            return dp[idx][A]= take+ntake;
        }
    
        int change(int amount, vector<int>& coins) {
            vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
            return solve(coins,coins.size()-1,amount,dp);
        }
    };