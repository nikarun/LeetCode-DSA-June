class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int water=0;
        while(i<n && j>0){
            water=max(water,min(height[i],height[j])*(j-i));
            if(height[i]<height[j]) ++i;
            else --j;
        }
        return water;
    }
};

// [1,8,6,2,5,4,8,3,7]

// curr-min(left[i],right[i])
// 2+6+3+4+4+0

// brute force ->n^2
