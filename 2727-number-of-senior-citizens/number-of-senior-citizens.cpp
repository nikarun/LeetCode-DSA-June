class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res=0;
        for(string str: details){
            if(stoi(str.substr(11,2))>60) ++res;
        }
        return res;
    }
};