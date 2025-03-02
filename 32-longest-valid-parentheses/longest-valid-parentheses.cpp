class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        stack<int>st;
        for(int i=0;i<n;++i){
            if(s[i]=='(') st.push(i);
            else{
                if(!st.empty() && s[st.top()]=='(') st.pop();
                else st.push(i);
            }
        }
        if(st.empty()) return n;
        int res=0;
        int a=n,b=0;
        while(!st.empty()){
            b=st.top();st.pop();
            res=max(res,a-b-1);
            a=b;
        }
        res=max(res,a);
        return res;
    }
};