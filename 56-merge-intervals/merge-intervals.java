class Solution {
    public int[][] merge(int[][] intervals) {
        int m=intervals.length;
        // int n=intervals[0].size();
        Arrays.sort(intervals, (int[] a, int[] b)->a[0]-b[0]);

        int first=intervals[0][0];
        int second=intervals[0][1];
        int cnt=1;
        for(int i=1;i<m;++i){
            if(intervals[i][0]<=second){
                second=Math.max(second,intervals[i][1]);
            }
            else{
                ++cnt;
                second=intervals[i][1];
            }
        }
        // System.out.println(cnt);
        int[][] res=new int[cnt][2];
        int k=0;
        first=intervals[0][0];
        second=intervals[0][1];
        for(int i=1;i<m;++i){
            if(intervals[i][0]<=second){
                second=Math.max(second,intervals[i][1]);
            }
            else{
                res[k][0]=first;
                res[k][1]=second;
                second=intervals[i][1];
                first=intervals[i][0];
                ++k;
            }
        }
        res[k][0]=first;
        res[k][1]=second;
        return res;

    }
}