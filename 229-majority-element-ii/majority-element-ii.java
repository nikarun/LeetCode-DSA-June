class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int cnt1=0,cnt2=0;
        int elem1=Integer.MAX_VALUE,elem2=Integer.MIN_VALUE;
        int n=nums.length;
        for(int i=0;i<n;++i){
            if(elem1==nums[i]){
                ++cnt1;
            }
            else if(elem2==nums[i]) ++cnt2;
            else if(cnt1==0){
                elem1=nums[i];
                ++cnt1;
            }
            else if(cnt2==0) {
                elem2=nums[i];
                ++cnt2;
        }
        else{
            --cnt1;
            --cnt2;
        }
        }
        int fcntr1=0,fcntr2=0;
        for(int i=0;i<n;++i){
            if(elem1==nums[i]) ++fcntr1;
            if(elem2==nums[i]) ++fcntr2;
        }
        System.out.println(elem1);
        System.out.println(elem2);
        List<Integer>res=new ArrayList<Integer>();
        if(fcntr1>n/3){
            res.add(elem1);
        }
        if(fcntr2>n/3){
            res.add(elem2);
        }
        return res;
    }
}
