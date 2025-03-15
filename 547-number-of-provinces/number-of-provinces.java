class Solution {

    public void dfs(int src, ArrayList<ArrayList<Integer>>adj, boolean[] vis){
        if(vis[src]) return;
        vis[src]=true;
        for(int i=0;i<adj.get(src).size();++i){
            dfs(adj.get(src).get(i),adj,vis);
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n=isConnected.length;
        ArrayList<ArrayList<Integer>>adj=new ArrayList<>();
        for(int i=0;i<n;++i){
            ArrayList<Integer>alist=new ArrayList<>();
            for(int j=0;j<n;++j){
                if(i!=j && isConnected[i][j]==1){
                    alist.add(j);
                }
            }
            adj.add(alist);
        }
        int cnt=0;
        boolean[] vis=new boolean[n];
        // Arrays.fill(vis,false);
        for(int i=0;i<n;++i){
            if(!vis[i]){
                System.out.println(i);
                dfs(i,adj,vis);
                ++cnt;
            }

        }
        return cnt;
    }
}