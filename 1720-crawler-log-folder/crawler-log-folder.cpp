class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n=logs.size();
        int ptr=0;
        for(int i=0;i<n;++i){
            string temp=logs[i];
            if(temp[0]=='.' && temp[1]=='.'){
                if(ptr>0){
                    --ptr;
                }
            }
            else if(temp[0]!='.'){
                // string path=temp.substr(0,3);
                // res.push_back(path);
                ++ptr;
            }
        }
        return ptr;
    }
};


// vector<string>vec
// vec={d1,d21}