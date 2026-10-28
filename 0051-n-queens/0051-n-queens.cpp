class Solution {
public:
   vector<vector<string>>result;
   int N;
   bool isvalid(vector<string>&grid,int row,int col){
    // attack from top
    for(int i =row-1;i>=0;i--){
        if(grid[i][col]=='Q'){
            return false;
        }
    }
        // attack from left diagonal
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        // attack from right digonal
        for(int i=row-1,j=col+1;i>=0&&j<N;i--,j++){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        return true;

    
   }
   void solve(vector<string>&grid,int row){
    if(row>=N){
        result.push_back(grid);
      return;
   }
   for(int col=0;col<N;col++){
    if(isvalid(grid,row,col)){
        grid[row][col]='Q';
        solve(grid,row+1);
        grid[row][col]='.';
     }
    }
   }
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        vector<string>grid(n,string(n,'.'));
        solve(grid,0);
        return result;
        
    }
};