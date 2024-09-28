class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        // vector<char>res;
        int ans=0;
        for(int i=0;i<n;++i){
            int count=1;
            while(i<n-1 && chars[i]==chars[i+1]) {
                ++count;
                ++i;
            }
            chars[ans++]=chars[i];
            if(count>1){
                string temp=to_string(count);
                for(int i=0;i<temp.size();++i){
                    chars[ans++]=temp[i];
                }
            }
        }
        // chars=res;
        return ans;
    }
};