class Solution {
public:
    int partition(vector<int>&nums,int low,int high){
        int partitionIdx=low;
        int pivot=nums[high];
        for(int i=low;i<high;i++){
            if(nums[i]<=pivot){
                swap(nums[i],nums[partitionIdx]);
                partitionIdx++;
            }
        }
        swap(nums[partitionIdx],nums[high]);
        return partitionIdx;
    }
    void quickSort(vector<int>& nums,int low,int high){
        if(low<high){
            int partitionIdx=partition(nums,low,high);
            quickSort(nums,low,partitionIdx-1);
            quickSort(nums,partitionIdx+1,high);
        }
    }

    void merge(vector<int>&nums,int low,int high,int mid){
        vector<int> sort;
        int left=low,right=mid+1;
        while(left<=mid && right<=high){
            if(nums[left]>nums[right]){
                sort.push_back(nums[right++]);
            }
            else{
                sort.push_back(nums[left++]);
            }
        }
        while(left<=mid){
            sort.push_back(nums[left++]);
        }
        while(right<=high){
            sort.push_back(nums[right++]);
        }
        int idx=low;
        for(auto it:sort){
            nums[idx++]=it;
        }
    }

    void mergeSort(vector<int>&nums,int low,int high){
        int mid=low+(high-low)/2;
        if(low>=high)    return;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,high,mid);
    }

    vector<int> sortArray(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        mergeSort(nums,low,high);
        return nums;
    }
};