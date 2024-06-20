class Solution {
public:
    bool possible(vector<int>&position,int mid, int m){
        int balls=1;//track balls kept count
        int prev=position[0];//where last ball was kept
        int n=position.size();
        for(int i=1;i<n;++i){
            if(position[i]-prev>=mid){
                balls+=1;
                prev=position[i];
                if(balls>=m) return true;
            }
        }
        return balls>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        //check on which gaps can balls be kept
        //start from mid 
        sort(position.begin(),position.end());
        int s=0,e=position[n-1];//s=0 because min gap between two elements can be 1 also but max gap can be only max value of array
        int res=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(position,mid,m)){
                res=mid;
                s=mid+1;//try widening because if mid gap is possible than any greator gap can also be possible
            }
            else e=mid-1;
        }
        return res;
    }
};