class Solution {
public:
    int maxLength(vector<int>& nums) {
     

        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long product = nums[i];
            long long g = nums[i], l = nums[i];

            for (int j = i+1; j < n; j++) {
                product *= nums[j];

                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]) ;
                if(product>g*l)break;

                if (product == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;   
    
   
    

    
       
        
    }
};