#include<bits/stdc++.h>

class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int n=word.size();
        int i=0;
        while(i<n){
            int cntr=1;
            char c=word[i];
            while(i+1<n && c==word[i+1] && cntr<=8){
                ++i;
                ++cntr;
            }
            string res=to_string(cntr);
            comp+=res;
            comp+=c;
            ++i;
        }
        return comp;
    }
};

// "aaaaaaaaaaaaaabb"


// str -->"abcde"

// comp ->""
