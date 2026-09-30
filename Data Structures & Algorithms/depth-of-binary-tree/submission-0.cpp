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
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        if(root &&  root->left==NULL && root->right==NULL)return 1;
        
        int lh=0;if(root->left)lh=1+maxDepth(root->left);
        int rh=0;if(root->right)rh=1+maxDepth(root->right);
        return max(lh,rh);
    }
};
