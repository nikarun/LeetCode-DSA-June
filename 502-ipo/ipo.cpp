class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());
        int i = 0;
        priority_queue<int> maximizeCapital;
        while (k--) {
            while (i < n && projects[i].first <= w) {
                maximizeCapital.push(projects[i].second);
                i++;
            }
            if (maximizeCapital.empty())
                break;
            w += maximizeCapital.top();
            maximizeCapital.pop();
        }
        return w;
    }
        // int cap=w;
        // while(k>0){
        //     int c=cap;
        //     int max_profit=0;
        //     int max_index=-1;
        //     vector<bool>vis(profits.size(),false);
        //     for(int i=0;i<=c && i<profits.size();++i){
        //         if(max_profit<profits[i] && !vis[i]){
        //             max_profit=profits[i];
        //             max_index=i;
        //             vis[i]=true;
        //         }
        //     }
        //     cap+=max_profit;
        //     --k;
        // }
        // return cap;
};
// k=2,w=0,p=[1,2,3], c=[0,1,1]

// p=[1,2,3]
// k=3
// c=[0,1,2]
// c=0
// c=1
// c=3

// i=0 to i<c -->check what you can pick max from unpicked project & mark it as picked