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
int max_dia=0;
int rec(TreeNode* root){
    if(root==NULL)return 0;

    int lh=1+rec(root->left);
    int rh=1+rec(root->right);
    max_dia=max(max_dia,lh+rh-2);
    return max(lh,rh);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int a=rec(root);
        return max_dia;
    }
};
