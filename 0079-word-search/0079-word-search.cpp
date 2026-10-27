class Solution {
public:
int n,m;
 bool find(vector<vector<char>>&board,int i,int j,int idx,string& word){
    if(idx==word.size())return true;
    if(i<0||i>=n||j<0||j>=m||board[i][j]=='#')return false;
    if(board[i][j]!=word[idx])return false;
    char temp=board[i][j];
    board[i][j]='#';
    bool status=find(board,i+1,j,idx+1,word)||find(board,i-1,j,idx+1,word)||find(board,i,j+1,idx+1,word)||find(board,i,j-1,idx+1,word);
    board[i][j]=temp;
    return status;

}
    bool exist(vector<vector<char>>& board, string word) {
         n=board.size();
         m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]&& find(board,i,j,0,word))return true;
            }
        }
        return false;
    }
};