class Solution {
public:
    int numTeams(vector<int>& rating) {
        //for every middle man check its left & right;
        int n=rating.size();
        int res=0;
        for(int i=1;i<n-1;++i){
            int left_small=0,left_greator=0;
            int right_small=0,right_greator=0;
            for(int j=0;j<i;++j){
                if(rating[j]<rating[i]){
                    ++left_small;
                }
                else{
                    ++left_greator;
                }
            }
            for(int k=i+1;k<n;++k){
                if(rating[k]<rating[i]){
                    ++right_small;
                }
                else{
                    ++right_greator;
                }
            }
            res+=left_small*right_greator+left_greator*right_small;
        }
        return res;
    }
};