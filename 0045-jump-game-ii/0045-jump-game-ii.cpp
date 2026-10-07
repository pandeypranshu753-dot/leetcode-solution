class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jump=0;
        int end=0;
        int fartherest=0;
        for(int i=0;i<n-1;i++){
            fartherest=max(fartherest,i+nums[i]);
            if(i==end){
                jump++;
                end=fartherest;
            }
        }
        return jump;
    }
};