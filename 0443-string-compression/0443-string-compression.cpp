class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int idx=0;
        while(i<n){
            char curr_char=chars[i];
            int count=0;
            while(i<n&&curr_char==chars[i]){
                count++;
                i++;
                //count++;
            }
            chars[idx]=curr_char;
            idx++;
            if(count>1){
            string count_char=to_string(count);
            for(char & ch:count_char){
                chars[idx]=ch;
                idx++;
            }
            }
        }
        return idx;
        
    }
};