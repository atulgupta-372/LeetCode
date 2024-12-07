class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3)    return false;
        int left=0,right=arr.size()-1;
        while(left<right){
            if(arr[left]<arr[left+1]){
                left++;
            }
            else{
                break;
            }
        }
        while(right>left){
            if(arr[right]<arr[right-1]){
                right--;
            }
            else{
                break;
            }
        }

        if(left==0 || right==arr.size()-1){
            return false;
        }

        if((right-left)==2){
            if(arr[left]<arr[left+1] && arr[right]<arr[right-1])    return true;
        }
        else if(left==right)    return true;
        return false;
    }
};