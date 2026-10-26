class Solution {
public:
// n=grid.size(),m=grid[0].size();
    void dfs(vector<vector<int>>&grid,int r,int c,long long& sum){
        int n=grid.size(),m=grid[0].size();
        if(r<0||r>=n||c<0||c>=m||grid[r][c]==0)return;
        sum+=grid[r][c];
        grid[r][c]=0;
       
        dfs(grid,r+1,c,sum);
        dfs(grid,r-1,c,sum);
        dfs(grid,r,c-1,sum);
        dfs(grid,r,c+1,sum);

        
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
       // long long sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    long long sum=0;
                   // sum+=grid[i][j];
                   // if(sum%k==0)count++;
                    dfs(grid,i,j,sum);
                    if(sum%k==0)count++;
                }
            }
        }
        return count;
        
    }
};