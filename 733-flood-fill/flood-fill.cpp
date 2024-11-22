class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int currColor, int m, int n){
        if(sr>m-1 || sc>n-1 || sr<0 || sc<0 || image[sr][sc]!=currColor || image[sr][sc]==color) return;
        image[sr][sc]=color;
        dfs(image,sr+1,sc,color,currColor,m,n);
        dfs(image,sr-1,sc,color,currColor,m,n);
        dfs(image,sr,sc+1,color,currColor,m,n);
        dfs(image,sr,sc-1,color,currColor,m,n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        if(m==0 && n==0) return {{}};
        int currColor=image[sr][sc];
        dfs(image,sr,sc,color,currColor,m,n);
        return image;
    }
};