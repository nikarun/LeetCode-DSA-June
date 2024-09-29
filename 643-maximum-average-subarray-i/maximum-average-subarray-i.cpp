class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<k;++i){
            sum+=nums[i];
        }
        int max_sum=sum;
        for(int i=1;i+k<=n;++i){
            sum-=nums[i-1];
            sum+=nums[i+k-1];
            max_sum=max(max_sum,sum);
        }
        return static_cast<double>(max_sum) / k;
    }
};