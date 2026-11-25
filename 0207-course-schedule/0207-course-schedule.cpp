class Solution {
public:
     bool topologicalsort(unordered_map<int,vector<int>>&adj,int n,vector<int>&indegree){
        queue<int>qu;
        int count=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                count++;
                qu.push(i);
            }
        }
        while(!qu.empty()){
            int u=qu.front();
            qu.pop();
            for(int& v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    count++;
                    qu.push(v);
                }
            }
        }
     
        if(count==n)return true;
        else return false;
     }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree( numCourses,0);
       // queue<int>qu;
        for(auto& v:prerequisites){
            int a=v[0];
            int b=v[1];
            adj[b].push_back(a);//b->a
            indegree[a]++;

        }
        return topologicalsort(adj,numCourses,indegree);

        
    }
};