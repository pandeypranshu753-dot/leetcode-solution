/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int sum(TreeNode*root){
        if(root==NULL)return 0;
        return root->val+sum(root->left)+sum(root->right);
     }
     int size(TreeNode*root){
        if(root==NULL)return 0;
        return 1+size(root->left)+size(root->right);
     }
    int averageOfSubtree(TreeNode* root) {
      if(root==NULL)return 0;
      int Sum=sum(root);
      int Size=size(root);
      int avg=Sum/Size;
      int count=(root->val==avg)?1:0;
      
     return count+averageOfSubtree(root->left)+averageOfSubtree(root->right);

        
    }
};