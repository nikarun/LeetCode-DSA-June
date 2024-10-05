class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==0) return 0;
        sort(points.begin(),points.end(), [](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        });
        int res=1;
        int first=points[0][0];
        int second=points[0][1];
        for(int i=1;i<n;++i){
            if(points[i][0]<=second) second = min(points[i][1], second);
            else {
                ++res;
                second=points[i][1];
            }
        }
        return res;
    }
};