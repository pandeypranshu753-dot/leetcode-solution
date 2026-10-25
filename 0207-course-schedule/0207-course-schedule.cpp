class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        
            for(const auto& neigh:prerequisites){
                adj[neigh[1]].push_back(neigh[0]);
                indegree[neigh[0]]++;
            }
            queue<int>q;
           // unordered_set<int>vis;
            for(int i=0;i<numCourses;i++){
                if(indegree[i]==0){
                    q.push(i);
                //    vis.inset(i);
                }
            }
            int count=0;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                count++;
            for(auto neigh:adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                  //  vis.insert(neigh);
                }
            }

            

        }
        return count==numCourses;
        
    }
};