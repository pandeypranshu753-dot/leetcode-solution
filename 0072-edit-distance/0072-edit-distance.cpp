class Solution {
public:
vector<vector<int>>dp;
    int minDistance(string a, string b) {
        int n=a.size(),m=b.size();
        dp.resize(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=1;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 
                if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1];
                else{
                    int add=1+dp[i][j-1];
                    int delet=1+dp[i-1][j];
                    int replace=1+dp[i-1][j-1];
                    dp[i][j]=min(add,min(delet,replace));
                }
            }
        }
        return dp[n][m];
        
    }
};