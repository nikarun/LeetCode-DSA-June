class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        if(n==0) return 0;
        int res=0;
        int i=1;
        while(i<n){
            if(s[i]!=s[i-1]) res+=1;
            i=i+2;
        }
        return res;
    }
};