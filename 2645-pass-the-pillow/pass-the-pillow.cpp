class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<n) return time+1;
        int i=1;
        bool is_forward_dir=true;
        while(time>0){
            if(i==n) {
                is_forward_dir=false;
            }
            if(i==1) {
                is_forward_dir=true;
            }
            if(is_forward_dir) ++i;
            else --i;
            --time;
        }
        return i;
    }
};
// 1,2,3,4
// time=5
// time=4,i=2
// t=3,i=3,
// t=2,i=4
// t=1,i=3
// t=0,i=2
// 1->2->3->4
// time-1 th pe last will be having then 


// if time+1<n
// time+1
// else
// last_end=n-1
// time-=n-1
// tim-=n
// return n-time

