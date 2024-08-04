class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        if(n==0) return 0;
        vector<int>subArraySum;
        for(int i=0;i<n;++i){
            int sum=nums[i];
            subArraySum.push_back(sum);
            for(int j=i+1;j<n;++j){
                sum+=nums[j];
                subArraySum.push_back(sum);
            }
        }
        sort(subArraySum.begin(),subArraySum.end());
        for(int j=0;j<subArraySum.size();++j){
            cout<<subArraySum[j]<<"  ";
        }
        long long res=0;
        for(int i=left;i<=right;++i){
            res+=subArraySum[i-1]%mod;
        }
        return res%mod;


    }
};

// gen all subarrays -->n2
// sort them 
// fetch sum from le to re