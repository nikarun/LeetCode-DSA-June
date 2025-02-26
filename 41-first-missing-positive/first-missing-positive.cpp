class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            if(nums[0]!=1) return 1;
            else return 2;
        }
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }

        for(int i=1;i<=n+1;++i){
            if(mp[i]==0) return i;
        }
        return -1;

    }
};

// mp->freq,
// 1 ->len(n)
