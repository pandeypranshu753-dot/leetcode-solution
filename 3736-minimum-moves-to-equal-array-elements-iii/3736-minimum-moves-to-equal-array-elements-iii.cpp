class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[n-1]-nums[i]!=0)count+=(nums[n-1]-nums[i]);

        }
        return count;
        
    }
};