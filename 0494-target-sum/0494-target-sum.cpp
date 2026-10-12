class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int ele:nums){
            sum+=ele;
        }
        int targetsum=(sum+target)/2;
        if((sum+target)%2!=0)return 0;
        if(sum<abs(target))return 0;
        vector<int>dp(targetsum+1);
        dp[0]=1;
        for(int ele:nums){
            for(int i=targetsum;i>=ele;i--){
                dp[i]+=dp[i-ele];
            }
            
        }

        return dp[targetsum];
    }
};