class Solution {
public:

    void solve(vector<vector<int>>&ans,vector<int> output,int i,vector<int>&nums){
        if(i>=nums.size()){
            ans.push_back(output);
            return;
        }
        solve(ans,output,i+1,nums);
        int element=nums[i];
        output.push_back(element);
        solve(ans,output,i+1,nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(ans,output,0,nums);
        return ans;
    }
};