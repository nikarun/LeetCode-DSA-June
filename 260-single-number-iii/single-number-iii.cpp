class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xoR=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            xoR^=nums[i];
        }
        int mask=1;
        while(1){
            if((mask & xoR)==0) mask= mask << 1;
            else break;
        }
        int a=0,b=0;
        for(int i=0;i<n;++i){
            if(nums[i] & mask) a^=nums[i];
            else b^=nums[i];
        }
        return {a,b};
    }
};

// num->[1,2,1,3,2,5]
// [1,1,2,2,3,5]
// 1->001
// 2->010
// 1->001
// 3->011
// 2->001
// 5->101
// -->100

// bit manipulation techinque -?