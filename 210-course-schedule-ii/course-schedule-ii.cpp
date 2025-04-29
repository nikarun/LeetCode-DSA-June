class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses,0);
        for(int i=0;i<prerequisites.size();++i){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;++i){
            if(inDegree[i]==0) q.push(i);
        }
        int visCount=0;
        vector<int>ans;
        while(!q.empty()){
            int front=q.front();
            ans.push_back(front);
            q.pop();
            for(int i=0;i<adj[front].size();++i){
                inDegree[adj[front][i]]--;
                if(inDegree[adj[front][i]]==0) q.push(adj[front][i]);
            }
            ++visCount;
        }
        
        if(visCount==numCourses) return ans;
        return {};

    }
};