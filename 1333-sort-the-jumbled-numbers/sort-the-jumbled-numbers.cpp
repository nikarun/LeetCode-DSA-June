class Solution {
public:
    static bool comp(const pair<int,int>&a,const pair<int,int>&b){
        return a.second<b.second;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=mapping.size();
        int m=nums.size();
        vector<pair<int,int>>vec;
        for(int num:nums){
            string temp=to_string(num);
            int idx=0;
            string res="";
            for(int i=0;i<temp.size();++i){
                // cout<<temp[i]-'0'<<endl;
                res+=to_string(mapping[temp[i]-'0']);
                // cout<<"mapping[temp[i]-'0'] "<<mapping[temp[i]-'0']<<endl;
                // cout<<"res "<<res<<endl;
            }
            // cout<<res<<endl;
            int new_mapping=stoi(res);
            vec.push_back({num,new_mapping});
        }
        sort(vec.begin(),vec.end(),comp);
        vector<int>result;
        for(int i=0;i<vec.size();++i){
            result.push_back(vec[i].first);
        }
        return result;
        
    }
};