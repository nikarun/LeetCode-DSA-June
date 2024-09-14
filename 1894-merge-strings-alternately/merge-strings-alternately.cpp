class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int n=word1.size();
        int m=word2.size();
        int i=0,j=0;
        while(i<n && j<m){
            res+=word1[i++];
            res+=word2[j++];
        }
        if(i<n){
            res+=word1.substr(i,n-i+1);
        }
        if(j<m){
            res+=word2.substr(j,m-j+1);
        }
        return res;
    }
};