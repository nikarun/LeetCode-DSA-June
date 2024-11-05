class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        if(n==0) return 0;
        int res=0;
        for(int i=1;i<n;i+=2){
            if(s[i]!=s[i-1]) res+=1;
        }
        return res;
    }
};