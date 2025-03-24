class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        stack<int>st;
        unordered_map<int,int>mp;
        for(int i=m-1;i>=0;--i){
            int top=-1;
            while(!st.empty() && st.top()<nums2[i]){
                // top=st.top();
                st.pop();
            }
            mp[nums2[i]]=st.empty()?-1:st.top();
            st.push(nums2[i]);
        }
        vector<int>res;
        for(int i=0;i<n;++i){
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};