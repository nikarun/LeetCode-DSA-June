class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odds=0;
        int n=arr.size();
        for(int i=0;i<n;++i){
            if(arr[i]%2!=0) ++odds;
            else{
                if(odds==3) return true;
                odds=0;
            }
            if(odds==3) return true;
        }
        return false;
    }
};