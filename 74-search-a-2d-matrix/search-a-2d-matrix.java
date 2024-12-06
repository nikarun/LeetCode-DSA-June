class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int i=0;
        int m=matrix.length;
        int n=matrix[0].length;
        int j=n-1;
        while(i<m && j>=0){
            if(target==matrix[i][j]) return true;
            else if(target>matrix[i][j]) ++i;
            else --j;
        }
        return false;
    }
}