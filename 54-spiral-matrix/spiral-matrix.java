class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m=matrix.length;
        int n=matrix[0].length;
        int column_start=0,column_end=n-1,row_start=0,row_end=m-1;
        List<Integer>order=new ArrayList<>(m*n);
        int p=0;
        while(column_start<=column_end && row_start<=row_end){
            for(int k=column_start;k<=column_end;++k){
                order.add(matrix[row_start][k]);
            }
            if(++row_start>row_end) break;
            for(int k=row_start;k<=row_end;++k){
                order.add(matrix[k][column_end]);
            }
            if(--column_end<column_start) break;
            for(int k=column_end;k>=column_start;--k){
                order.add(matrix[row_end][k]);
            }
            if(--row_end<row_start) break;
            for(int k=row_end;k>=row_start;--k){
                order.add(matrix[k][column_start]);
            }
            if(++column_start>column_end) break;
        }
        return order;
    }
}