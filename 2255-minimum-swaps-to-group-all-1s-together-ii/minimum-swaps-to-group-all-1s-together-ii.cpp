class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int onesCount=0;
        for(int p:nums){
            if(p==1) ++onesCount;
        }
        if(onesCount==0 || onesCount==n) return 0;
        int currWindowOnes=0;
        for(int i=0;i<onesCount;++i){
            if(nums[i]==1) ++currWindowOnes;
        }
        int maxOnes=currWindowOnes;

        for(int i=0;i<n;++i){
            currWindowOnes-=nums[i];
            currWindowOnes+=nums[(i+onesCount)%n];
            maxOnes=max(maxOnes,currWindowOnes);
        }
        return onesCount-maxOnes;
    }
};