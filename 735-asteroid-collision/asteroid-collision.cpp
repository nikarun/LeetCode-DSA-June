class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
     int n=asteroids.size();
     if(n==0){
        return {};
     }   
     stack<int>st;
     for(int i=0;i<n;++i){
        int unit=asteroids[i];
        if(unit>0 || st.empty()){
            st.push(unit);
        }
        else{
                while(!st.empty() && st.top()>0 && st.top()<abs(unit)){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(unit)) st.pop();
                else{
                    if(st.empty() || st.top()<0) st.push(unit);
                }
        }
     }
     vector<int>res;
     while(!st.empty()){
        res.push_back(st.top());
        st.pop();
     }
     reverse(res.begin(),res.end());
     return res;
    }
};