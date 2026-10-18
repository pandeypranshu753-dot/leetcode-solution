class Solution {
public:
vector<vector<int>>dp;
   int lcs(string& a,string& b,int i,int j){
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(a[i]==b[j])return dp[i][j]= 1+lcs(a,b,i-1,j-1);
    else return dp[i][j]= max(lcs(a,b,i-1,j),lcs(a,b,i,j-1));

   }
    int longestCommonSubsequence(string a, string b) {
        int n=a.size();
        int m=b.size();
        dp.resize(n,vector<int>(m,-1));
        return lcs(a,b,n-1,m-1);
        
    }
};