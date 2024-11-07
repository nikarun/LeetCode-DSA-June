class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();
        if(n==0) return 0;
       //There will be total around 32 bits
       // for each bit check how many numbers have set bit on that position
       int res=0;
       for(int i=0;i<31;++i){
        int cntr=0;
        for(int candidate: candidates){
            if((candidate & 1<<i)) ++cntr; //1 left shifts i give a number which have 1 at i th position
            res=max(res,cntr);
        }
       }
       return res;
    }
};