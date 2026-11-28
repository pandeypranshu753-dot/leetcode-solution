class Solution {
public:
   bool isbipirtitedfs(vector<vector<int>>& graph,int curr,vector<int>&color,int currcolor){
    color[curr]=currcolor;
    for(int&v:graph[curr]){
        if(color[v]==color[curr])return false;
        else if(color[v]==-1){
            int colorofv=1-currcolor;
            if(isbipirtitedfs(graph,v,color,colorofv)==false)return false;

        }
    }
    return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(isbipirtitedfs(graph,i,color,1)==false)return false;
            }
        }
        return true;
        
    }
};