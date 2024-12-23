class Solution {
    vector<vector<int>>finalresult;
    vector<int>result;
public:
    void func(vector<int>& candidates, int target,int size)
    {
if(target<0) return;
        if(size<=0 && target>=1) return ;
        if(target==0){
            finalresult.push_back(result);
            return;
        }
        result.push_back(candidates[size-1]);
        func(candidates,target-candidates[size-1],size);
        result.pop_back();
        func(candidates,target,size-1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       func(candidates,target,candidates.size());
        return finalresult;
    }
};
