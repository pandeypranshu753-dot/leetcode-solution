class Solution {
public:
    vector<int>topologicalsort( unordered_map<int,vector<int>>&adj,int n, vector<int>&indegree){
        vector<int>result;
        int count=0;
        queue<int>qu;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                result.push_back(i);
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
                    result.push_back(v);
                    count++;
                    qu.push(v);
                }
            }
        }
        if(count==n){
            return result;
        }
        return {};


    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto&v:prerequisites){
            int a=v[0];
            int b=v[1];
            adj[b].push_back(a);//b->a
           // count++;
            indegree[a]++;
        }
        return topologicalsort(adj,numCourses,indegree);
        
    }
};