class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        if(n==0) return {};
        vector<int>res;
        stack<int>st;
        for(int i=0;i<n;++i){
            int curr_ast = asteroids[i];
            if(curr_ast<0){
                if(st.empty()) st.push(curr_ast);
                else{
                    while(!st.empty() && st.top()>0 && st.top()<abs(curr_ast)){
                        st.pop();
                    }
                    if(st.empty() || st.top()<0) st.push(curr_ast);
                    if(st.top() == abs(curr_ast) && st.top()>0) st.pop();
                    
                }
            }
            else{
                st.push(curr_ast);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};