class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        if(mat.empty()||mat[0].empty())return{};
        queue<pair<int,int>>qu;
        int MAX_VALUE=n*m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    qu.push({i,j});
                }
                else{
                    mat[i][j]=MAX_VALUE;
                }
            }
        }
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!qu.empty()){
            auto[row,col]=qu.front(); qu.pop();
            for(auto [dr,dc]:dir){
                int r=row+dr,c=col+dc;
                if(r>=0&&r<n&&c>=0&&c<m&&mat[r][c]>mat[row][col]+1){
                    qu.push({r,c});
                    mat[r][c]=mat[row][col]+1;
                }
            }
        }
        return mat;
    }
};