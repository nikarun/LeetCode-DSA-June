class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        if(n==0) return 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;++i){
            int sum=nums[i];
            pq.push(sum);
            for(int j=i+1;j<n;++j){
                sum+=nums[j];
                pq.push(sum);
            }
        }

        long long res=0;
        for(int i=1;i<=right;++i){
            int top=pq.top();
            pq.pop();
            if(i>=left){
                res+=top%mod;
            }
        }
        return res%mod;


    }
};

// gen all subarrays -->n2
// sort them 
// fetch sum from le to re

