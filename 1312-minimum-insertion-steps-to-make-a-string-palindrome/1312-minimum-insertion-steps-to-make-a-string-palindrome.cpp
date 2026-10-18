class Solution {
public:
 vector<vector<int>>dp;
 int lps(string&s,string&t,int i,int j){
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])return dp[i][j]=1+lps(s,t,i-1,j-1);
    else return dp[i][j]=max(lps(s,t,i-1,j),lps(s,t,i,j-1));
 }
    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        int m=t.size();
        dp.resize(n,vector<int>(m,-1));
        return n-lps(s,t,n-1,m-1);
        
    }
};