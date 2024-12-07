class Solution {
private:
    bool checkSorted(vector<int>& nums){
    
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }
        return true;
    }


public:
    bool isMonotonic(vector<int>& nums) {
        if(checkSorted(nums))   return true;
        reverse(nums.begin(),nums.end());
        if(checkSorted(nums))   return true;
        return false;
    }
};