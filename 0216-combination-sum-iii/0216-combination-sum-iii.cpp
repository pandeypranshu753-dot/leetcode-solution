class Solution {
public:
    vector<vector<int>>result;
    void solve(int start,int n,int k,vector<int>&temp){
        if(k==0){
            if(n==0){
            result.push_back(temp);
            return;
        }
        }
        if(start>9||n<0)return;
        temp.push_back(start);
        solve(start+1,n-start,k-1,temp);
        temp.pop_back();
        solve(start+1,n,k,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<int>target;
        solve(1,n,k,temp);
        return result;
        
    }
};