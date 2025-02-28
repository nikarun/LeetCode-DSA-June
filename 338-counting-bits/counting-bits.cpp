class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1,0);
        for(int i=1;i<=n;++i){
            if(i%2==0) res[i]=res[i/2];
            else res[i]=res[i-1]+1;
        }
        return res;
    }
};



// 0->0
// 1-->1
// 2-->010
// 3-->11
// 4-->100
// 5-->101
// 6-->110
// 7-->111
// 8-->1000
// 9-->1001
// 10-->1010
// 11-->1011
// 12-->1100
// 13 -->1101
// 14 ->1110
// 15-->1111


// for odd prev+1.
// for event ->half
