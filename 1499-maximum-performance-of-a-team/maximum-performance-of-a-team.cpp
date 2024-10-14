class Solution {
public:
    const int mod = (int)1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<pair<int,int>>vec;
        for(int i=0;i<n;++i){
            vec.push_back({efficiency[i],speed[i]});
        }
        sort(vec.rbegin(),vec.rend());
        long res=0;
        long topSpeed=0;
        for(int i=0;i<n;++i){
            int currSpeed=vec[i].second;
            int currEff=vec[i].first;
            if(pq.size()==k){
                topSpeed-=pq.top();
                pq.pop();
            }
            pq.push(currSpeed);
            topSpeed+=currSpeed;
            res=max(res,topSpeed*currEff);
        }
        return res%mod;

    }
};