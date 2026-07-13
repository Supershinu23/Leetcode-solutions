// Last updated: 14/07/2026, 00:53:21
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
    void test(TreeNode* t, int val){
        if(t->val > val){
            if(t->left!=nullptr){
                test(t->left,val);
            }else{
                t->left = new TreeNode(val);
                return;
            }
        }
        if(t->val < val){
            if(t->right!=nullptr){
                test(t->right, val);
            }else{
                t->right = new TreeNode(val);
                return;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr) return new TreeNode(val);
        test(root, val);
        return root;
    }
};