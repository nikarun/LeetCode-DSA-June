class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
     int k=0;
     if(m*n!=original.size()) return {};
     vector<vector<int>>res(m,vector<int>(n,-1));
   
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                res[i][j]=original[k++];
                if(k>=original.size()){
                    break;
                }
            }
        }
     return res;   
    }
};