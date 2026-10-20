class Solution {
public:
vector<vector<int>>dp;
    int countSubstrings(string s) {
        int n=s.size();
        dp.resize(n,vector<int>(n,0));
        int count=0;
        for(int k=0;k<n;k++){
            for(int i=0, j=k;i<n && j<n;i++,j++){
                if(s[i]!=s[j])dp[i][j]=0;
                else{
                    //for 2 length
                    if(j<=i+1){
                        dp[i][j]=1;
                        count++;
                    }
                    else if(dp[i+1][j-1]==1){
                        dp[i][j]=1;
                        count++;
                    }
                    else dp[i][j]=0;
                }
            }
        }
        return count;
        
    }
};