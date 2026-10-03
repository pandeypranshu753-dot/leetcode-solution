class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        int count=0;
        stack<int>st;
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push(i);
            else{
                if(!st.empty()){
                    int x=st.top();
                    dp[i]=i-x+1;
                    if(x>=1)dp[i]+=dp[x-1];
                    st.pop();

                }
            }
            count=max(count,dp[i]);

        }
        return count;
        
    }
};