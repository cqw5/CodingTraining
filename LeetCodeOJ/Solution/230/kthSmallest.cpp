/*! Source: https://leetcode.com/problems/kth-smallest-element-in-a-bst
 *! Author: qwchen
 *! Date  : 2017-04-18
 *  二叉查找树中第k小的数
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
 * 思路：中序遍历，递归版本
 * 时间复杂度：O(k). 19 ms. beats 22.52% of cpp submissions.
 * 空间复杂度：O(logn)
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = kthSmallestNode(root, k);
        if (node) return node->val;
        else      return -1;
    }
    
    TreeNode* kthSmallestNode(TreeNode* root, int &k) {
        if (root == nullptr) return nullptr;
        TreeNode* left = kthSmallestNode(root->left, k);
        if (left) return left;
        k--;
        if (k == 0) return root;
        TreeNode* right = kthSmallestNode(root->right, k);
        if (right) return right;
        return nullptr;
    }
};


/*
 * 思路：中序遍历，迭代版本
 * 时间复杂度：O(k). 16 ms. beats 41.13% of cpp submissions.
 * 空间复杂度：O(logn)
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (p != nullptr || !s.empty()) {
            while (p != nullptr) {
                s.push(p);
                p = p->left;
            }
            if (!s.empty()) {
                TreeNode* top = s.top();
                k--;
                if (k == 0) return top->val;
                p = top->right;
                s.pop();
            }
        }
        return -1;
    }
};

