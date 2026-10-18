class Solution {
public:
vector<vector<int>>dp;
  int lcs(string&s,string&t,int i,int j){
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])return dp[i][j]=1+lcs(s,t,i-1,j-1);
    else return dp[i][j]=max(lcs(s,t,i-1,j),lcs(s,t,i,j-1));

  }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        int m=t.size();
        dp.resize(n,vector<int>(m,-1));
        return lcs(s,t,n-1,m-1);
        
    }
};