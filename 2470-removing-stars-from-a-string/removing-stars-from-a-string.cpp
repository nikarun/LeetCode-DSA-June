class Solution {
public:
    string removeStars(string s) {
        string res="";
        stack<char>st;
        int i=0;
        int n=s.size();
        while(i<n){
            if(s[i]=='*') st.pop();
            else st.push(s[i]);
            ++i;
        }
        if(st.empty()) return "";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

// "erase*****"
