class Solution {
public:
     vector<vector<int>>result;
     int n;
     void solve(int start,vector<int>&arr,int target,vector<int>&temp){
        if(target==0){
            result.push_back(temp);
            return;
        }
            if(target<0||start>=arr.size())return;
            temp.push_back(arr[start]);
            solve(start,arr,target-arr[start],temp);
            temp.pop_back();
            solve(start+1,arr,target,temp);
        
     }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        result.clear();
        vector<int>temp;
        solve(0,arr,target,temp);
        return result;
        
    }
};