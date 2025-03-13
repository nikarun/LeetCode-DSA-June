class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m=nums1.length;
        int n=nums2.length;
        int i=0,j=0;
        int m1=0,m2=0;
        int count=0;
        for(count=0;count<=(m+n)/2;++count){
            m2=m1;
            if(i!=m && j!=n){
                if(nums1[i]<nums2[j]){
                    m1=nums1[i++];
                }
                else {
                    m1=nums2[j++];
                }
            }
            else if(i<m){
                m1=nums1[i++];
            }
            else {
                m1=nums2[j++];
            }
        }
        if((m+n)%2==0){
            double ans =(double) m1 + (double) m2;
            return ans / 2.0;
        }
        else{
            return (double) m1;
        }
       
    }
}