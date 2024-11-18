class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& candidates,vector<int>output,int target,int idx,int sum){
        if(sum==target){
            ans.push_back(output);
            return;
        }
        if(sum>target)  return;

        if(idx<candidates.size()){
            solve(ans,candidates,output,target,idx+1,sum);            
            output.push_back(candidates[idx]);
            solve(ans,candidates,output,target,idx,sum+candidates[idx]);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>output;
        int sum=0,idx=0;
        solve(ans,candidates,output,target,idx,sum);
        return ans;
    }
};