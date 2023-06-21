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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        bool ans=0;
        s(root,targetSum,root->val,ans);
        return ans;
    }
private:
    void s(TreeNode* root,const int ts,int ps,bool& ans ){
        assert(root);
        if(!root->left && !root->right){
            if(ps==ts)ans=1;
        }
        else{
            if(root->left)s(root->left,ts,root->left->val+ps,ans);
            if(root->right)s(root->right,ts,root->right->val+ps,ans);
        }
    }
};