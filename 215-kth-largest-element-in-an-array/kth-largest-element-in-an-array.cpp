class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int num:nums){
            pq.push(num);
        }
        while(!pq.empty() && --k>0){
            pq.pop();
        }
        return pq.top();
    }
};