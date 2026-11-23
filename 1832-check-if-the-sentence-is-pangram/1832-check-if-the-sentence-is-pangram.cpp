class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_set<char>st;
        int n=s.length();
        for(int i=0;i<n;i++){
          //  if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u'){
                st.insert(s[i]);
           // }
        }
        int m=st.size();
        return m==26;
        
    }
};