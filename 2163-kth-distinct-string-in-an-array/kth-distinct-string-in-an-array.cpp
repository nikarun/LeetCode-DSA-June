class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
     unordered_map<string,int>mp;
     for(string str:arr){
        mp[str]++;
     }
    //  for(auto it=mp.begin();it!=mp.end();++it){
    //     if(it->second==1){
    //         if(--k==0) return it->first;
    //     }
    //  }
    for(int i=0;i<arr.size();++i){
        if(mp[arr[i]]==1){
            if(--k==0) return arr[i];
        }
    }
     return "";   

    }
};