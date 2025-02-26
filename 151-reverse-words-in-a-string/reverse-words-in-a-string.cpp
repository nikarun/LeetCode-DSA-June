class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int n=s.size();
        int i=0;
        while(i<n){
            string subStr="";
            while(i<n && s[i]==' ') ++i;
            while(i<n && s[i]!=' '){
                subStr+=s[i];
                ++i;
            }
            if(subStr!=""){
                st.push(subStr);
            }
        }
        string resStr="";
        while(!st.empty()){
            resStr+=st.top();
            st.pop();
            if(!st.empty()) resStr+=' ';
        }
        return resStr;
    }
};