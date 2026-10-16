class Solution {
public:
vector<vector<int>>dp;
int helper(int i,vector<int>&nums,int sum,int target){
        if(sum==target)return 0;
    if(i==nums.size()||sum>target)return -1e9;
    if(dp[i][sum]!=-1)return dp[i][sum];
    
        int take=1+helper(i+1,nums,sum+nums[i],target);
        int leave=helper(i+1,nums,sum,target);
    
    return dp[i][sum]=max(take,leave);

}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        dp.resize(n,vector<int>(target+1,-1));
        int ans= helper(0,nums,0,target);
        if(ans<0)return -1;
        return ans;
        
    }
};