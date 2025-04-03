class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0 || n==1) return n;
        sort(nums.begin(),nums.end());
        // if(k<(nums[1]-nums[0])) return 1;
        int i=0,j=0;
        long long sum=0;
        int res=0;
        for(j=0;j<n;++j){
            sum+=nums[j];
            while(static_cast<long>(j-i+1)*nums[j]-sum>k) sum-=nums[i++];
            res=max(res,j-i+1);
        }
        return res;
    }
};
// [1,5,5,7]

// [1,2,4]
// k=5
// 1,2,