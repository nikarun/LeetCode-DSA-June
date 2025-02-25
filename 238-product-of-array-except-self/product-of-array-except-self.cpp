class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int zerosCount=0;
       int n=nums.size();
       vector<int>pdt(n,-1);
       int totalPdt=1;
       for(int i=0;i<n;++i){
        if(nums[i]==0){
            ++zerosCount;
        }
        else{
            totalPdt*=nums[i];
        }
       } 

       for(int i=0;i<n;++i){
        if(nums[i]==0) {
            if(zerosCount>1){
                pdt[i]=0;
            }
            else{
                pdt[i]=totalPdt;
            }
        }
        else{
            if(zerosCount>0) pdt[i]=0;
            else pdt[i]=totalPdt/nums[i];
        }
       }
       return pdt;

    }
};