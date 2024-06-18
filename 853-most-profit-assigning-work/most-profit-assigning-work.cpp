class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();
        int res=0;
        vector<pair<int,int>>vec;
        for(int i=0;i<difficulty.size();++i){
            vec.push_back({difficulty[i],profit[i]});
        }
        sort(vec.begin(),vec.end());
        for(int i=1;i<n;++i){
            vec[i].second=max(vec[i].second,vec[i-1].second);
        }
        for(int i=0;i<worker.size();++i){
            int max_profit=0;
            int low=0,high=n-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(vec[mid].first<=worker[i]) {
                    low=mid+1;
                }
                else high=mid-1;
            }
            if(high>=0) res+=vec[high].second;
        }
        return res;
    }
};