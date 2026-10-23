class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int k=-1;
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(x!=i)k&=x;
        }
        if(k==-1)return 0;
        else return k;
        
    }
};