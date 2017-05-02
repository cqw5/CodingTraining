/*! Source: https://leetcode.com/problems/binary-tree-level-order-traversal-ii
 *! Author: qwchen
 *! Date  : 2017-04-13
 *  二叉树的层次遍历
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
 * 思路：
 *   深度优先
 * 时间复杂度：O(n). 6 ms. beats 22.21 % of cpp submissions.
 * 空间复杂度：O(logn)
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int high = maxHigh(root);
        vector<int> layer;
        vector<vector<int>> res(high, layer);
        dfs(root, res, 0, high-1);
        return res;
    }
    
    int maxHigh(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxHigh(root->left), maxHigh(root->right)) + 1;
    }
    
    void dfs(TreeNode* root, vector<vector<int>>& res, int level, int high) {
        if (root == nullptr) return;
        res[high - level].push_back(root->val);
        dfs(root->left, res, level+1, high);
        dfs(root->right, res, level+1, high);
    }
};


/*
 * 思路：
 *   广度优先，迭代写法
 * 时间复杂度：O(n), 6 ms. beats 28.54% of cpp submissions.
 * 空间复杂度：O(n)
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res; // 很关键，没有这一行，下面遇到root为null的情况陷入死循环
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                res.push_back(level);
                level.clear();
                if (!q.empty()) {
                    q.push(nullptr);
                }
            }
            else {
                level.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        for (int i = 0; i < res.size() / 2; i++) {
            swap(res[i], res[res.size() - 1 - i]);
        }
        return res;
    }
};

/*
 * 思路：
 *   广度优先，递归写法（先序遍历）
 *   在先序遍历中，同一层，左边的节点会比右边的节点先被遍历。
 *   用一个变量标记当前所在的层，将节点放入当前所在层对于的结果数组元素位置即可。
 * 时间复杂度：O(n), 6 ms. beats 28.54% of cpp submissions.
 * 空间复杂度：O(n)
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        BFS(res, root, 0);
        for (int i = 0; i < res.size() / 2; i++) {
            swap(res[i], res[res.size() - 1 - i]);
        }
        return res;
    }
    
    void BFS(vector<vector<int>>& res, TreeNode* root, int level) {
        if (root == nullptr) return;
        if (level == res.size()) {
            res.push_back(vector<int>());
        }
        res[level].push_back(root->val);
        BFS(res, root->left, level+1);
        BFS(res, root->right, level+1);
    }
};

