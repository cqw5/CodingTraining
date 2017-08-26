/*! Author: qwchen
 *! Date  : 2016-12-01
 *  60. 把二叉树打印成多行
 *  题目描述
 *    从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
 */

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

/*
 * 思路：
 *   跟二叉树的标准层次遍历一样，使用一个队列，并使用nullptr指针来分割队列中二叉树的每一层
 *   用一个局部的数组保存一层的元素，遇到nullptr指针就将局部数组的元素加到结果中，并局部数组
 */
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if (pRoot == nullptr) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(pRoot);
        q.push(nullptr);
        vector<int> layer;
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front != nullptr) {
                layer.push_back(front->val);
                if (front->left != nullptr)  q.push(front->left);
                if (front->right != nullptr) q.push(front->right);
            }
            else {
                result.push_back(layer);
                layer.clear();
                if (!q.empty()) {
                    q.push(nullptr);
                }
            }
        }
        return result;
    }
};

/*
 * 思路：使用先序遍历。注意一定要先去树的高度
 */
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        int high = maxDepth(pRoot);
        vector<vector<int> > res(high);
        dfs(pRoot, res, 0);
        return res;
    }
    
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    
    void dfs(TreeNode* pRoot, vector<vector<int> >& res, int depth) {
        if(pRoot == nullptr) return;
        res[depth].push_back(pRoot->val);
        dfs(pRoot->left, res, depth+1);
        dfs(pRoot->right, res, depth+1);
    }
};
