class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int n=height.size();
        int i=0,j=n-1;
        while(i<n && j>0){
            res=max(res,min(height[i],height[j])*(j-i));
            if(height[i]<height[j]) ++i;
            else --j;
        }
        return res;
    }
};

// [1,8,6,2,5,4,8,3,7]