class Solution {
public:
    vector<vector<int>>dp;
    bool helper(int i,vector<int>&nums,int sum,int target){
        if(i==nums.size()){
            if(sum==target)return true;
            else return false;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        if(sum+nums[i]>target)return dp[i][sum]=helper(i+1,nums,sum,target);
        else{
            int take=helper(i+1,nums,sum+nums[i],target);
            int leave=helper(i+1,nums,sum,target);
        return dp[i][sum]=(take||leave);
        }
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int ele:nums)totalsum+=ele;
        if(totalsum%2!=0)return false;
        int target=totalsum/2;
        dp.resize(n,vector<int>(target+1,-1));
        return helper(0,nums,0,target);
        
    }
};