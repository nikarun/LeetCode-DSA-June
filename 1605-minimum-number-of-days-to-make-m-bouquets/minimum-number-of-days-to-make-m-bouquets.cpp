class Solution {
public:
    bool check(int day, vector<int>& bloomDay, int m, int k){
        int fc=0;
        int bc=0;
        for(int i=0;i<bloomDay.size();++i){
            if(bloomDay[i]<=day){
                ++fc;
                 if(fc==k){
                ++bc;
                fc=0;
            }
            }
            else{
                fc=0;
            }
        }
        if(bc>=m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n) return -1;
        int low=INT_MAX,high=INT_MIN;
        for(int i=0;i<n;++i){
           low=min(low,bloomDay[i]);
           high=max(high,bloomDay[i]);
        }
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(mid,bloomDay,m,k)) high=mid;
            else low=mid+1;
        }
        return high;
        
    }
};