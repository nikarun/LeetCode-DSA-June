class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       int n=nums.size();
       int c1=INT_MAX, c2=INT_MAX;
       for(int p:nums){
        if(p<=c1) c1=p;
        else if(p<=c2) c2=p;
        else return true;
       } 
       return false;
    }
};