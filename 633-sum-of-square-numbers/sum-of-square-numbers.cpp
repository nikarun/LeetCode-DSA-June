class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left=0,right=sqrt(c);
        cout<<right<<endl;
        while(left<=right){
            if(left*left + right*right == c) return true;
            else if(left*left + right*right < c) ++left;
            else --right;
        }
        return false;
    }
};