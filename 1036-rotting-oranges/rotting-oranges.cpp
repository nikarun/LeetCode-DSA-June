class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
     int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        if(n==0) return 0;
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
             if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        if(q.empty()) return -1;
        int x[]={1,-1,0,0};
        int y[]={0,0,-1,1};
        int count=-1;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        while(!q.empty()){
            int size=q.size();
            while(size--){
            auto ptr=q.front();
            q.pop();
            vis[ptr.first][ptr.second]=true;
            for(int i=0;i<4;i++){
            if(ptr.first+x[i]>=0 && ptr.first+x[i]<m && ptr.second+y[i]>=0 && ptr.second+y[i]<n && grid[ptr.first+x[i]][ptr.second+y[i]]==1 && !vis[ptr.first+x[i]][ptr.second+y[i]]){
                    fresh--;
                grid[ptr.first+x[i]][ptr.second+y[i]]=2;
                    q.push({ptr.first+x[i],ptr.second+y[i]});
               // vis[ptr.first+x[i]][ptr.second+y[i]]=true;
                }
            }
            }
            count++;
            
        }
        if(fresh!=0) return -1;
     if(count==-1) return 0;
        return count;
    
    }
};