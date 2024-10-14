class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mid%2==0){
                if(mid-1>=0 && nums[mid]==nums[mid-1]) end=mid;
                else if(mid+1<n && nums[mid]==nums[mid+1]) start=mid+1;
                else return nums[mid];
            }
            else{
                if(mid-1>=0 && nums[mid]==nums[mid-1]) start=mid+1;
                else if(mid+1<n && nums[mid]==nums[mid+1]) end=mid;
                else return nums[mid];
            }
        }
        return -1;
    }
};