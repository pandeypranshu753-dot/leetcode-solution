class Solution {
public:
    bool isbipirtitebfs(vector<vector<int>>& graph,int curr, vector<int>&color,int currcolor){
        queue<int>qu;
        qu.push(curr);
        color[curr]=currcolor;
        while(!qu.empty()){
            int u=qu.front();
            qu.pop();
            for(int& v:graph[u]){
                if(color[v]==color[u])return false;
                else if(color[v]==-1){
                    color[v]=1-color[u];
                    qu.push(v);
                }

            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
            if(isbipirtitebfs(graph,i,color,1)==false){
                return false;
            }
            }
        }
        return true;
        
    }
};