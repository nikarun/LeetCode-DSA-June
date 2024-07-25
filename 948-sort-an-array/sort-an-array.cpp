class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end){
        int l=mid-start+1;
        int r=end-mid;
        int left[l];
        int right[r];
        for(int i=0;i<l;++i){
            left[i]=nums[start+i];
        }
        for(int i=0;i<r;++i){
            right[i]=nums[mid+i+1];
        }
        int i=0,j=0,k=start;
        while(i<l && j<r){
            if(left[i]<right[j]){
                nums[k++]=left[i++];
            }
            else{
                nums[k++]=right[j++];
            }
        }
        while(i<l){
            nums[k++]=left[i++];
        }
        while(j<r){
            nums[k++]=right[j++];
        }
    }
    void mergeSort(vector<int>& nums, int start, int end){
        if(start<end){
            int mid=start+(end-start)/2;
            mergeSort(nums,start,mid);
            mergeSort(nums,mid+1,end);
            merge(nums,start,mid,end);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};