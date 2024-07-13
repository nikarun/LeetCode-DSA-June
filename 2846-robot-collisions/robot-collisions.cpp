class Solution {
public:

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int>ind(n);
        for(int i=0;i<n;++i){
            ind[i]=i;
        }
        sort(ind.begin(), ind.end(), [&](const int x, const int y) {
            return positions[x] < positions[y];
        });
        stack<int>st;
        vector<int>res;
        for(int p:ind){
            if(directions[p]=='R'){
                st.push(p);
            }
            else{
                while(!st.empty()){
                    int top=st.top();
                    if(healths[top]<healths[p]){
                        healths[top]=0;
                        healths[p]-=1;
                        st.pop();
                    }
                    else if(healths[top]==healths[p]){
                        healths[top]=0;
                        healths[p]=0;
                        st.pop();
                        break;
                    }
                    else{
                        healths[top]=healths[top]-1;
                        healths[p]=0;
                        break;
                    }
                }
            }
        }
        for(int y:healths){
            if(y>0){
                res.push_back(y);
            }
        }
        return res;
    }
};

    //     map<int,pair<int,char>>mp;
    //     int n=positions.size();
    //     for(int i=0;i<n;++i){
    //         mp[positions[i]]={healths[i],directions[i]};
    //     }
    //     stack<pair<int,int>>st;
    //     vector<int>res;
    //     for(auto it=mp.begin();it!=mp.end();++it){
    //         pair<int,char>p=it->second;
    //         int pos=it->first;
    //         char dir=p.second;
    //         int health=p.first;
    //         if(dir=='R'){
    //             st.push({pos,health});
    //         }
    //         else{
    //             while(!st.empty()){
    //                 pair<int,int>top=st.top();
    //                 if(top.second==health){
    //                     st.pop();
    //                     healths[pos]=0;
    //                     healths[top.first]=0;
    //                     break;
    //                 }
    //                 else if(top.second<health){
    //                     st.pop();
    //                     health-=1;
    //                     healths[pos]=health;
    //                     healths[top.first]=0;
    //                 }
    //                 else{
    //                     st.pop();
    //                     st.push({top.first,top.second-1});
    //                     healths[top.first]=top.second-1;
    //                     healths[pos]=0;
    //                     break;
    //                 }
    //             }
    //         }         
    //     }
    //     for(int p:healths){
    //         if(p>0){
    //             res.push_back(p);
    //         }
    //     }
    //     return res;
    // }
// };