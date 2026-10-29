class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>&arr,int target,int idx,vector<int>&subset){
        if(target==0){
            result.push_back(subset);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1])continue;
            if(arr[i]>target)break;
            subset.push_back(arr[i]);
            solve(arr,target-arr[i],i+1,subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int>subset;
        result.clear();
        solve(arr,target,0,subset);
        return result;
        
    }
};