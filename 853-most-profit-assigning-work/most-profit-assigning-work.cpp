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
        for(int i=0;i<worker.size();++i){
            int max_profit=0;
            for(int j=0;j<vec.size();++j){
                if(vec[j].first<=worker[i]){
                    max_profit=max(max_profit,vec[j].second);
                }
                else{
                    break;
                }
            }
            res+=max_profit;
        }
        return res;
    }
};