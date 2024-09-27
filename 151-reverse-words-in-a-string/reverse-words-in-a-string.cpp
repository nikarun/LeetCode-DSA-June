class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string res="";
        stack<string>st;
        for(int i=0;i<n;++i){
            while(s[i]==' ') ++i;
            string temp="";
            while(i<n && s[i]!=' '){
                temp+=s[i];
                ++i;
            }
            if(temp.size()>0){
            st.push(temp);
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
            if(!st.empty()) res+=" ";
        }
        return res;
    }
};