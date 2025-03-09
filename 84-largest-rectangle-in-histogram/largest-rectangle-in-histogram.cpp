class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        heights.push_back(0);
        heights.insert(heights.begin(),0);
        int n=heights.size();
        stack<int>st;
        st.push(0);
        int max_area=heights[1];
        for(int i=1;i<n;++i){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int h=heights[st.top()];
                st.pop();
                int b=i-1-st.top();
                int area=h*b;
                max_area=max(max_area,area);

            }
            st.push(i);
        }
        return max_area;
    }
};