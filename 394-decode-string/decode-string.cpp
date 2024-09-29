class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;++i){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else {
                string curr_str="";
                while(st.top()!='['){
                    curr_str=st.top()+curr_str;
                    st.pop();
                }
                st.pop();
                string num=""; //because number could be of more than 1 digit
                while(!st.empty() && isdigit(st.top())){
                    num=st.top()+num;
                    st.pop();
                }
                int k=stoi(num);
                while(k--){
                    for(int i=0;i<curr_str.size();++i){
                        st.push(curr_str[i]);
                    }
                }
            }
        }

        string res="";
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;

    }
};