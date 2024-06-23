class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        multiset<int,greater<int>>ms;
        int res=0;
        int l=0;
        for(int i=0;i<n;++i){
            ms.insert(nums[i]);
            int smallest=*ms.rbegin();
            int largest=*ms.begin();
            while(largest-smallest>limit){
                ms.erase(ms.find(nums[l]));
                ++l;
                smallest=*ms.rbegin();
                largest=*ms.begin();
            }
            res=max(res,i-l+1);
        }
        return res;
    }
};