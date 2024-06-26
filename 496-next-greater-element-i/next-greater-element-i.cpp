class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=0;i<n;++i){
            int elm=nums2[i];
            while(!st.empty() && st.top()<elm){
                mp[st.top()]=elm;
                st.pop();
            }
            st.push(elm);
        }
        vector<int>res;
        for(int i=0;i<m;++i){
            int elm=nums1[i];
            if(mp.find(elm)!=mp.end()){
                res.push_back(mp[elm]);
            }
            else{
                res.push_back(-1);
            }
        }
        return res;
    }
};

