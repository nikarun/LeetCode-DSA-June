class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        if(n==0) return 0;
        long long int sum=0;
        for(int c:chalk){
            sum+=c;
        }
        long long int res=k%sum;
        while(res>=0){
            for(int i=0;i<n;++i){
                res-=chalk[i];
                if(res<0) return i;
            }
        }
        return -1;
    }
};