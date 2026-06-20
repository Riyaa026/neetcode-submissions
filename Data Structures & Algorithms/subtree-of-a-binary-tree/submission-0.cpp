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
   bool identical(TreeNode* p,TreeNode* q)
    {
        if(p==nullptr||q==nullptr)
        return p==q;
        if(p->val!=q->val)
        return false;
        return identical(p->left,q->left)&&identical(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr)
        return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node->val==subRoot->val)
            {
                if(identical(node,subRoot))
                return true;
            }
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);

        }
        return false;

    }
};
