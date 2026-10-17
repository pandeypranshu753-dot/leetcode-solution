class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0)return 0;
        int m= matrix[0].size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1&&i>0&&j>0){
                    matrix[i][j]=min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]})+1;
                }
                res+=matrix[i][j];
            }
        }
        return res;
        
    }
};