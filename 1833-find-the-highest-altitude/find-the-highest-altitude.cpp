class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int sum=0;
        int max_sum=0;
        for(int g:gain){
            sum+=g;
            max_sum=max(max_sum,sum);
        }
        return max_sum;
    }
};