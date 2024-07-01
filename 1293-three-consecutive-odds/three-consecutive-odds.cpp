class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odds=0;
        int n=arr.size();
        for(int i=0;i<n;++i){
            if(odds==3) return true;
            if(arr[i]%2!=0) ++odds;
            else{
                odds=0;
            }
        }
        return odds>=3?true:false;
    }
};