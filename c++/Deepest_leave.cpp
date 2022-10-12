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
   int sum=0;
    int maxdepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+max(maxdepth(root->left),maxdepth(root->right));
    }
   int findsum(TreeNode* root,int level,int depth)
    {
       
      if(root==NULL)
          return 0;
       if(root!=NULL)
       {
        if(level==depth)
           sum+=root->val;
       }
       
       
        findsum(root->left,level+1,depth);
        findsum(root->right,level+1,depth);
       return sum;
    }
    int deepestLeavesSum(TreeNode* root) 
    {
        int depth=maxdepth(root);
     return findsum(root,1,depth);
     //   return sum;
            
    }
};
