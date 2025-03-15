class Solution {
    boolean isDetonated(int x1, int x2, int y1, int y2, int r){
        long dx = (long) x2 - x1;
        long dy = (long) y2 - y1;
        long res = dx * dx + dy * dy;
        long radiusSquared = (long) r * r;
        return res <= radiusSquared;
    }
    void dfs(int src, int[][] bombs, boolean[] vis, int[] cnt){
        if(vis[src]) return;
        int x1=bombs[src][0];
        int y1=bombs[src][1];
        int r=bombs[src][2];
        cnt[0]++;
        vis[src]=true;
        for(int i=0;i<bombs.length;++i){
            int x2=bombs[i][0];
            int y2=bombs[i][1];
            if(!vis[i] && isDetonated(x1,x2,y1,y2,r)){
                dfs(i,bombs,vis,cnt);
            }
        }
    }
    public int maximumDetonation(int[][] bombs) {
        int n=bombs.length;
        int maxBombs=0;
        for(int i=0;i<n;++i){
            boolean[] vis=new boolean[n];
            int[] cnt={0};
            dfs(i,bombs,vis,cnt);
            maxBombs=Math.max(maxBombs,cnt[0]);
        }
        return maxBombs;

    }
}