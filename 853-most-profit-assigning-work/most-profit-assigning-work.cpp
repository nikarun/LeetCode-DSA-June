class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();
        int res=0;
        for(int i=0;i<worker.size();++i){
            int max_profit=0;
            for(int j=0;j<difficulty.size();++j){
                if(difficulty[j]<=worker[i]){
                    max_profit=max(max_profit,profit[j]);
                }
            }
            res+=max_profit;
        }
        return res;
    }
};