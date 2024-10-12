class Solution {
public:
    // bool is_cycle_present=false;
    // bool dfs(int src, vector<vector<int>>adj, vector<bool>&is_visited, vector<bool>&recursive_stack){
    //     if(!is_visited[src]){
    //     is_visited[src]=true;
    //     recursive_stack[src] = true;
    //     for(int k:adj[src]){
    //         if(!is_visited[k]){
    //             if(dfs(k,adj,is_visited,recursive_stack)) return true;
    //         }
    //         else{
    //             if(recursive_stack[k]){
    //                 return true;
    //             }
    //         }
    //     }
    //     }
    //    recursive_stack[src]=false; 
    //    return false;
    // }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        vector<int>in_degree(numCourses,0);
        queue<int>q;
        for(int i=0;i<numCourses;++i){
            for(int p:adj[i]){
                in_degree[p]++;
            }
        }
        // for(int i=0;i<numCourses;++i){
        //     cout<<in_degree[i]<<" ";
        // }
        for(int i=0;i<numCourses;++i){
            if(in_degree[i]==0) q.push(i);
        }
        int visited=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ++visited;
            cout<<visited<<endl;
            for(int p:adj[top]){
                in_degree[p]--;
                if(in_degree[p]==0) q.push(p);
            }
        }

        return visited==numCourses;
    }
};