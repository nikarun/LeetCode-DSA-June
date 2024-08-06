class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int>freq(26,0);
        for(int i=0;i<word.size();++i){
            freq[word[i]-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int res=0;
        //place first 9 most frequent characters in first postion
        //then next 9 on second position
        //next 9 on rd postion & so on
        int count=1;//unique characters
        int pos=1; //position
        for(int i=0;i<26;++i){
            if(freq[i]==0) break;
            if(count>8){
                pos+=1;
                count=1;
            }
            res+=(freq[i]*pos);
            ++count;
        }
        return res;
    }
};