class Solution {
public:
 void dfs(vector<vector<int>>&image,int currrow,int currcol,int initialcolor,int newcolor){
    int n= image.size();
    int m=image[0].size();
    if(currrow<0||currcol<0||currrow>=n||currcol>=m){
        return;
    }
    if(image[currrow][currcol]!=initialcolor)return;
    image[currrow][currcol]=newcolor;
    dfs(image,currrow+1,currcol,initialcolor,newcolor);
    dfs(image,currrow,currcol+1,initialcolor,newcolor);
    dfs(image,currrow-1,currcol,initialcolor,newcolor);
    dfs(image,currrow,currcol-1,initialcolor,newcolor);
   }
   
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc])return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
        
    }
     
};