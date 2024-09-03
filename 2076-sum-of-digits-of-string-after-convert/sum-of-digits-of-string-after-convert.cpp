class Solution {
public:
    int getLucky(string s, int k) {
     int n=s.size();
     string numericString="";
     for(int i=0;i<n;++i){
        int baseValue=int(s[i])-96;
        numericString+=to_string(baseValue);
     }  
     cout<<numericString<<endl; 
     while(k>0 && numericString.size()>1){
        int res=0;
        n=numericString.size();
        for(int i=0;i<n;++i){
            res+=int(numericString[i])-'0';
        }
        // cout<<res<<endl;
        numericString=to_string(res);
        --k;
     }
     return stoi(numericString);
    }
};