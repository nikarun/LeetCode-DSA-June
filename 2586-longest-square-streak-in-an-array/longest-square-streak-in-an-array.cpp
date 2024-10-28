class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // int n=nums.size();
        // unordered_map<int,int>mp;
        // for(int p:nums){
        //     mp[p]++;
        // }
        // sort(nums.begin(),nums.end());
        // int res=0;
        // for(int i=0;i<n-1;++i){
        //     long long int temp=nums[i];
        //     int cntr=1;
        //     while(temp<=nums[n-1]){
        //         temp=temp*temp;
        //         if(mp[temp]>0) ++cntr;
        //         else break;
        //     }
        //     res=max(res,cntr);
        // }
        // return res==1?-1:res;
        int n = nums.size();
        unordered_set<int> numSet(nums.begin(), nums.end()); 
        int res = -1;

        for (int num : nums) {
            int count = 0;
            long long current = num;

            while (numSet.find(current) != numSet.end()) {
                count++;
                current *= current; 
                if (current > pow(10,5)) break;
            }

            if (count >= 2) {
                res = max(res, count);
            }
        }

        return res;
    }
};

// 2,8,9,10,13,13,16

// 4,3,6,16,8,2

// 2,3,4,6,8,16

// 2,4,16

// n*sqrt(n)

// 2,3,5,6,7



