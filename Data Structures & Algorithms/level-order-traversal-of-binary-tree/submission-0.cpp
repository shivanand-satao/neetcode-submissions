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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int size=q.size();
            while(size--){
                
                auto top_ele=q.front();
                q.pop();

                temp.push_back(top_ele->val);
                if(top_ele->left)q.push(top_ele->left);
                if(top_ele->right)q.push(top_ele->right);
            }
                res.push_back(temp);
        }
        return res;
    }
};
