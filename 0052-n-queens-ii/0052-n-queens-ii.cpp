class Solution {
public:
   int N;
   int count;
   bool issafe(vector<string>&grid,int row,int col){
    // from top attack
    for(int i=row-1;i>=0;i--){
        if(grid[i][col]=='Q'){
            return false;

        }
    }
    //from left digonal attack
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(grid[i][j]=='Q'){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0&&j<N;i--,j++){
        if(grid[i][j]=='Q'){
            return false;
        }
    }
    return true;

   }
   void solve(vector<string>&grid,int row){
    if(row>=N){
        count++;
    return ;
    }
    for( int col=0;col<N;col++){
        if(issafe(grid,row,col)){
            grid[row][col]='Q';
            solve(grid,row+1);
            grid[row][col]='.';
        }
    }

   }
    int totalNQueens(int n) {
        N=n;
         count=0;
        vector<string>grid(n,string(n,'.'));
        solve(grid,0);
        return count;
        
    }
};