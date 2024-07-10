class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n=logs.size();
        vector<string>res;
        for(int i=0;i<n;++i){
            string temp=logs[i];
            if(temp[0]=='.' && temp[1]=='.'){
                if(res.size()>0){
                    res.pop_back();
                }
            }
            else if(temp[0]!='.'){
                string path=temp.substr(0,3);
                res.push_back(path);
            }
        }
        return res.size();
    }
};


// vector<string>vec
// vec={d1,d21}