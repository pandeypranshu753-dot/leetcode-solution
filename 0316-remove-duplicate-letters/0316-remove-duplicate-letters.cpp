class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        string ans;

        for (char c : s) {
            mp[c]--;

            if (ans.find(c) != string::npos) continue;

            while (!ans.empty() && ans.back() > c && mp[ans.back()] > 0) {
                ans.pop_back();
            }

            ans.push_back(c);
        }

        return ans;
    }
};
    
