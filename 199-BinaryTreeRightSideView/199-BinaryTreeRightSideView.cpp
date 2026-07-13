// Last updated: 14/07/2026, 00:54:59
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        vector<int> ans;
        if(root==nullptr)return ans;

        while(!q.empty()){
            TreeNode* t = q.front();
            int size = q.size();
            ans.push_back(t->val);

            for(int i=0;i<size;i++){
                TreeNode* a = q.front();
                q.pop();

                if(a->right!=nullptr)q.push(a->right);
                if(a->left!=nullptr)q.push(a->left);
            }
            
        }
        return ans;
    }
};