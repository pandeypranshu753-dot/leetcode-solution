class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int ele:nums){
            sum+=ele;
        }
        if(sum%2!=0)return false;
        int targetsum=sum/2;
        vector<bool>dp(targetsum+1,false);
        dp[0]=true;
        for(int num:nums){
            for(int i=targetsum;i>=num;i--){
                dp[i]=dp[i]||dp[i-num];
                if(dp[targetsum])return true;
            }
        }
        return dp[targetsum];
    }
};