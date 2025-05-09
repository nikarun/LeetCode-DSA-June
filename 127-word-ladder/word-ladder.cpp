class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordSet(wordList.begin(),wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>visited;
        while(!q.empty()){
            auto [word,lvl]=q.front();
            q.pop();

            for(int i=0;i<word.length();++i){
                string temp = word;
                for(char c='a';c<='z';++c){
                    temp[i]=c;
                    if(temp==beginWord) continue;
                    if(temp==endWord) return lvl+1;
                    if(wordSet.find(temp)!=wordSet.end() && visited.find(temp)==visited.end()){
                        q.push({temp,lvl+1});
                        visited.insert(temp);
                    }
                }
            }
        }
        return 0;
    }
};