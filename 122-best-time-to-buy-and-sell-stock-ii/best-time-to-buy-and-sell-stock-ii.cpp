class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0;
        int res=0;
        while(i<n){
            while(i<n-1 && prices[i]>=prices[i+1]) ++i;
            int purchase=prices[i];
            while(i<n-1 && prices[i]<=prices[i+1]) ++i;
            int sell=prices[i];
            res+=(sell-purchase);
            ++i;
        }
        return res;
    }
};