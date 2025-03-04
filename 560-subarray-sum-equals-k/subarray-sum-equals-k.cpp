class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_map<int,int>mp;
        int cnt=0;
        int sum=0;
        mp[sum]=1;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                cnt+=mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};

// [1,1,1]
// k=2

// [1,2,3], k=3
// n^2
// mp[1]=0
// mp[3]=2
// [1,2,3]
// for i ->0 to n:
//     sum=nums[i]
//     for j->i+1 to n:
//         sum+=nums[j]
//         if(sum==k):
//          store
    
// k=4
// 1,2,3,-1,0,2,-1
// mp[sum]++;
// mp[j]-mp[i] ==k;

// [1,2,3]
// mp[1]=1
// mp[3]=1
// mp[]
// k=4
// 1,2,3,-1,0,2,-1
// mp[1]=1
// mp[3]=1
// mp[6]=1
// mp[5]=1
// sum-k

// 0 -->i ==sum
// sum-k =present ->j
// j-->i -->k
