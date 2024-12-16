class Solution {
    public int trap(int[] height) {
        int n=height.length;
        int maxLeft=0;
        int maxRight=0;
        int i=0,j=n-1;
        int waterTrapped=0;
        while(i<j){
            maxLeft=Math.max(maxLeft,height[i]);
            maxRight=Math.max(maxRight,height[j]);
            int currWater=0;
            if(height[i]<height[j]){
                currWater=height[i];
                ++i;
            }
            else{
                currWater=height[j];
                --j;
            }
            waterTrapped+=Math.min(maxLeft,maxRight)-currWater;
        }
        return waterTrapped;
    }
}