class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        int prev_wait_time=customers[0][0]+customers[0][1];
        long long res=prev_wait_time-customers[0][0];
        for(int i=1;i<n;++i){
            prev_wait_time=max(prev_wait_time,customers[i][0])+customers[i][1];
            res+=prev_wait_time-customers[i][0];
        }
        return (double) res/n;
    }
};