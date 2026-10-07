class Solution {
public:
     bool isvalid(string s){
        int n= s.length();
        int balance=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')balance++;
            else if(s[i]==')'){
                balance--;
                if(balance<0){
                    return false;
                }
            }
        }
        return balance==0;

     }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.length();
        vector<string>ans;
        unordered_set<string>visited;
        queue<string>q;
        q.push(s);
        visited.insert(s);
        bool found=false;
        while(!q.empty()){
            int m=q.size();
            while(m--){
                string curr=q.front();
                q.pop();
                if(isvalid(curr)){
                    ans.push_back(curr);
                    found=true;
                }
                if(found)continue;//skip if string aleardy found
                for(int i=0;i<curr.size();i++){
                    if(curr[i]!='('&&curr[i]!=')')continue;
                    string next=curr.substr(0,i)+curr.substr(i+1);
                    if(visited.find(next)==visited.end()){
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            if(found)break;
        }
        return ans;

        
    }
};