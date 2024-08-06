class Solution {
public:
    static bool comp(const pair<char,int>&a, const pair<char,int>&b){
        return a.second>b.second;
    }
    int minimumPushes(string word) {
        int n=word.size();
        unordered_map<char,int>mp;
        for(int i=0;i<word.size();++i){
            mp[word[i]]++;
        }
        vector<pair<char,int>>vec;
        for(auto it=mp.begin();it!=mp.end();++it){
            vec.push_back({it->first,it->second});
        }
        sort(vec.begin(),vec.end(),comp);
        int res=0;
        //place first 9 most frequent characters in first postion
        //then next 9 on second position
        //next 9 on rd postion & so on
        int count=1;//unique characters
        int pos=1; //position
        for(int i=0;i<vec.size();++i){
            if(count>8){
                pos+=1;
                count=1;
            }
            res+=(vec[i].second*pos);
            cout<<" vec "<<vec[i].second<<" "<<" res "<<res<<" pos "<<pos<<" count "<<count<<endl;
            ++count;
        }
        return res;
    }
};