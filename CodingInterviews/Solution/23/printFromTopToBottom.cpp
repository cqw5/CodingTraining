/*! Author: qwchen
 *! Date  : 2016-11-18
 *  23. 二叉树的层次遍历
 */

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> levelOrder;
        if (root == nullptr) {
            return levelOrder;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* out = q.front();
            q.pop();
            levelOrder.push_back(out->val);
            if (out->left != nullptr) {
                q.push(out->left);
            }
            if (out->right != nullptr) {
                q.push(out->right);
            }
        }
        return levelOrder;
    }
};

