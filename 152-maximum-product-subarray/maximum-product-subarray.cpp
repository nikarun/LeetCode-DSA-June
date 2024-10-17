class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int l=1,r=1;
        int i=0,j=n-1;
        int max_pdt=INT_MIN;
        while(i<n && j>=0){
            l=(l==0)?1:l;
            r=(r==0)?1:r;
            l*=nums[i];
            cout<<l<<endl;
            r*=nums[j];
            max_pdt=max(max_pdt,max(l,r));
            ++i;
            --j;
        }
        return max_pdt;
    }
};