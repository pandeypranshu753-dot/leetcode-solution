class Solution {
public:
vector<vector<int>>dp;
int total;
int helper(int i,vector<int>&nums,int sum,int target){
    if(i==nums.size()){
        if(sum==target)return 1;
        else return 0;
    }
    if(dp[i][sum+total]!=-1)return dp[i][sum+total];
    int add=helper(i+1,nums,sum+nums[i],target);
    int sub=helper(i+1,nums,sum-nums[i],target);
    return dp[i][sum+total]=add+sub;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        total=0;
        for(int ele:nums)total+=ele;
        dp.resize(nums.size(),vector<int>(2*total+1,-1));//row,column
        return helper(0,nums,0,target);
        
    }
};