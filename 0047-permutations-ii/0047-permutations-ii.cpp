class Solution {
public:
    vector<vector<int>>ans;
    void permutation(vector<int>&num,int i,int n){
        if(i==n-1){
            ans.push_back(num);
            return;
        }
        unordered_set<int>visited;
        for(int j=i;j<n;j++){
            if(visited.count(num[j]))continue;
            visited.insert(num[j]);
            swap(num[i],num[j]);
            permutation(num,i+1,n);
            swap(num[i],num[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& num) {
        sort(num.begin(),num.end());
        permutation(num,0,num.size());
        return ans;
        
    }
};