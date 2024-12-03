class Solution {
    public static void reverse(int[][] matrix){
        int n=matrix.length-1;
        int i=0;
        // System.out.println(n);
        while(i<n){
            System.out.println(i);
            System.out.println(n);
            int[] temp=matrix[i];
            matrix[i]=matrix[n];
            matrix[n]=temp;
            ++i;
            --n;
        }
    }
    public void rotate(int[][] matrix) {
        int m=matrix.length;
        int n=matrix[0].length;
        reverse(matrix);
        System.out.println(Arrays.deepToString(matrix));
        for(int i=0;i<m;++i){
            for(int j=i+1;j<n;++j){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }

    }
}