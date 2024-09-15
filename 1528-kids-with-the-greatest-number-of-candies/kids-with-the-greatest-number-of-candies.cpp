class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        if(n==0) return {};
        int maxCandies=0;
        for(int candy:candies){
            maxCandies=max(maxCandies,candy);
        }
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