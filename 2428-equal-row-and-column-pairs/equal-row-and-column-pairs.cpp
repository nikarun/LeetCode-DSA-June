class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>res;
        for(int i=0;i<n;++i){
            vector<int>temp;
            for(int j=0;j<n;++j){
                temp.push_back(grid[j][i]);
            }
            res.push_back(temp);
        }
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i]==res[j]) ++ans;
            }
        }
        return ans;

    }
};