class Solution {
public:
     void subset(vector<vector<int>>&res,vector<int>&nums,vector<int>&ans,int begin){
        res.push_back(ans);
        for(int i=begin;i<nums.size();i++){
            if(i==begin||nums[i]!=nums[i-1]){
                ans.push_back(nums[i]);
                subset(res,nums,ans,i+1);
                ans.pop_back();
            }
        }
     }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>ans;
        subset(res,nums,ans,0);
        return res;

        
    }
};