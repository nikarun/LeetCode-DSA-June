class Solution {
public:
    int ones(int num){
        int cnt=0;
        while(num>0){
        if(num%2!=0) ++cnt;
        num/=2; 
        }
        return cnt;
    }

    vector<int> countBits(int n) {
        vector<int>res;
        for(int i=0;i<=n;++i){
            res.push_back(ones(i));
        }
        return res;
    }
};