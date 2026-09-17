class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isincrease=true;
        bool isdecrease=true;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
              isdecrease=false ;
            }
            if(nums[i]<nums[i-1]){
                isincrease=false;
            }
            
        }
        return isincrease||isdecrease;
    }
};