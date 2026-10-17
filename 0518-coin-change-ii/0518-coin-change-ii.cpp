class Solution {
public:
    int helper(vector<int>&coins,int amount,int n,vector<vector<int>>&dp){
        if(amount==0)return 1;
        if(n<0||amount<0)return 0;
       if(dp[n][amount]!=-1)return dp[n][amount];
       int take=0;
        if(coins[n]<=amount){
            take=helper(coins,amount-coins[n],n,dp);
        }
        int leave=helper(coins,amount,n-1,dp);
        return dp[n][amount]=take+leave;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(coins,amount,n-1,dp);
        
    }
};