class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int currColor, int m, int n, vector<vector<bool>>&vis){
        if(sr>m-1 || sc>n-1 || sr<0 || sc<0 || image[sr][sc]!=currColor || image[sr][sc]==color || vis[sr][sc]) return;
        image[sr][sc]=color;
        vis[sr][sc]=true;
        dfs(image,sr+1,sc,color,currColor,m,n,vis);
        dfs(image,sr-1,sc,color,currColor,m,n,vis);
        dfs(image,sr,sc+1,color,currColor,m,n,vis);
        dfs(image,sr,sc-1,color,currColor,m,n,vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        if(m==0 && n==0) return {{}};
        int currColor=image[sr][sc];
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        dfs(image,sr,sc,color,currColor,m,n,vis);
        return image;
    }
};