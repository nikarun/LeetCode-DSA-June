class Solution {
    // public static void reverseRows(int[][]  matrix){
    //     int m=matrix.length;
    //     for(int i=0;i<m;++i){
    //         int left=0,right=matrix[i].length-1;
    //         while(left<right){
    //             int temp=matrix[i][left];
    //             matrix[i][left]=matrix[i][right];
    //             matrix[i][right]=temp;
    //             ++left;
    //             --right;
    //         }
    //     }
    // }
    public void rotate(int[][] matrix) {
        //reverse every row & then take image around y=x line
        int m=matrix.length;
        for(int i=0;i<m/2;++i){
            int []temp=matrix[i];
            matrix[i]=matrix[m-i-1];
            matrix[m-i-1]=temp;
        }
        for(int i=0;i<m;++i){
            for(int j=i+1;j<m;++j){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
    }
}

// 3,2,1
// 6,5,4
// 9,8,7

// 3-->(0,0), 7-->(2,2)
// 2-->(0,1), 4-->(1,2) 
// 6 -->(1,0), 8-->(2,1)


// 7,8,9
// 4,5,6
// 1,2,3