class Solution {
public:
    int trap(vector<int>& hight) {
        int n=hight.size();
        if(n==0)return 0;
        vector<int>prev(n);
        prev[0]=-1;
        int max=hight[0];
        for(int i=1;i<n;i++){
            prev[i]=max;
            if(max<hight[i])max=hight[i];
        }
        vector<int>next(n);
        next[n-1]=-1;
         max=hight[n-1];
        for(int i=n-2;i>=0;i--){
            next[i]=max;
            if(max<hight[i])max=hight[i];
        }
        vector<int>minm(n);
        for(int i=0;i<n;i++){
            minm[i]=min(prev[i],next[i]);

        }
        int water=0;
        for(int i=0;i<n;i++){
            if(hight[i]<minm[i]){
                water+=(minm[i]-hight[i]);
            }
        }
        return water;
        
    }
};