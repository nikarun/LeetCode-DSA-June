class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0 || n==1) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
        });
        int first=intervals[0][0];
        int second=intervals[0][1];
        int res=0;
        for(int i=1;i<n;++i){
            if(intervals[i][0]<second){
                ++res;
            }
            else{
                second=max(second,intervals[i][1]);
            }
        }
        return res;
    }
};