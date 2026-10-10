class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int>ans(100001,0);
        long long k=(long long)k1+k2,sum=0;
        int mxdiff=0;
        for(int i=0;i<n;i++){
          int diff=abs(nums1[i]-nums2[i]);
          ans[diff]++;
          sum+=diff;
          mxdiff=max(mxdiff,diff);
        }
        if(sum<=k)return 0;
        for(int i=mxdiff;i>0&&k>0;i--){
            long long move=min(k,(long long)ans[i]);
            ans[i]-=move;
            ans[i-1]+=move;
            k-=move;
        }
        long long res=0;
        for(int i=0;i<=mxdiff;i++){
            res+=(long long)i*i*ans[i];
        }
        return res;

    }
};