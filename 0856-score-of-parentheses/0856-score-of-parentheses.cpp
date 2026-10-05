class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();
        int depth=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                depth++;
            }
        
        else{
            depth--;
            if(s[i-1]=='('){
                count+=1<<depth;
            }
        }
        
        }
        return count;  
    }
};