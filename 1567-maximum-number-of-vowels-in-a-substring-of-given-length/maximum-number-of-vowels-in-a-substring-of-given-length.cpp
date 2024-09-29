class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int res=0;
        int max_res=0;
        for(int i=0;i<n;++i){
            if(i<k) {
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o'||s[i]=='u'){
                    ++res;
                }
            }
            else{
                max_res=max(max_res,res);
                if(s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o'||s[i-k]=='u') --res;
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o'||s[i]=='u'){
                    ++res;
                }
            }
        }
        return max(max_res,res);
    }
};