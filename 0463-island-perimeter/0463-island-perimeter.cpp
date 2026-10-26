class Solution {
public:
    int dfs(vector<vector<int>>&grid,int r,int c){
        int n=grid.size();
        int m=grid[0].size();
        if(r<0||r>=n||c<0||c>=m||grid[r][c]==0)return 1;
        if(grid[r][c]==-1)return 0;
        grid[r][c]=-1;
        return (dfs(grid,r-1,c)+dfs(grid,r+1,c)+dfs(grid,r,c-1)+dfs(grid,r,c+1));
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int parameter=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    parameter+=dfs(grid,i,j);
                }

            }
        }
        return parameter;
        
    }
};