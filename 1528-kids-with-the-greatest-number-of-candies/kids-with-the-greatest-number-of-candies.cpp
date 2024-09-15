class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        if(n==0) return {};
        int maxCandies=*max_element(candies.begin(),candies.end());
        vector<bool>res;
        for(int candy: candies){
            if(candy+extraCandies>=maxCandies){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;
    }
};