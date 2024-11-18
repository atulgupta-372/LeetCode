class Solution {

public:
    void solve(vector<vector<int>>&ans,vector<int>output,vector<int>&nums,int idx){
        if(idx>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            solve(ans,output,nums,idx+1);
            swap(nums[idx],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int idx=0;
        solve(ans,output,nums,idx);
        return ans;
    }
};