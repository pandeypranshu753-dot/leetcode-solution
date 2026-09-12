class Solution {
public:
    vector<vector<int>>result;
    void f(vector<int>&cand,int t,int idx,vector<int>&subset){
        if(t==0){
            result.push_back(subset);
            return;
        }
        for(int i=idx;i<cand.size();i++){
            if(i>idx && cand[i]==cand[i-1])continue;
            if(cand[i]>t)break;
            subset.push_back(cand[i]);
            f(cand,t-cand[i],i+1,subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>subset;
        result.clear();
        f(candidates,target,0,subset);
        return result;
        
    }
};