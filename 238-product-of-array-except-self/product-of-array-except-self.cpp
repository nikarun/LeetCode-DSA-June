class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pdt=1;
        int n=nums.size();
        int zeros=0;
        for(int p:nums){
            if(p==0) ++zeros;
            else pdt*=p;
        }
        vector<int>res;
        for(int i=0;i<n;++i){
            if(zeros>1){
                res.push_back(0);
            }
            else if(zeros==1){
                if(nums[i]!=0){
                    res.push_back(0);
                }
                else{
                    res.push_back(pdt);
                }
            }
            else{
                res.push_back(pdt/nums[i]);
            }
        }
        return res;
    }
};