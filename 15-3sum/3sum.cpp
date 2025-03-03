class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return {};
        vector<vector<int>>res;
        // [1,0,1,2,-1,-4]
        // [-4,-1,0,1,1,2]
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;++i){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    ++j;
                    --k;
                    while(j<n && nums[j]==nums[j-1]) ++j;
                    while(k>0 && nums[k]==nums[k+1]) --k;
                }
                else if(sum<0){
                    ++j;
                }
                else {
                    --k;
                } 
            }
        }
        return res;
    }
};

// [1,0,1,2,-1,-4]


// sort->[-4,-1,-,1,1,2]
// i,j,k