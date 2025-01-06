class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        if(n==0) return {};
        // if(n==1) return {boxes[0]};
        vector<int>res;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=abs(j-i)*(boxes[j]-'0');
            }
            res.push_back(sum);
        }
        return res;
    }
};