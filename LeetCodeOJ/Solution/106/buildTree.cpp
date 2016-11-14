/*! Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 *! Author: qwchen
 *! Date  : 2016-11-14
 * 根据中序序列和后序序列构建二叉树
 * 思路：与105题“根据先序序列和中序序列构建二叉树”相似
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
private:
    /*
     * Parament：
     *     in:   中序序列
     *     post: 后序序列
     *     in_begin:   中序序列的起始下标
     *     in_end:     中序序列的终止下标
     *     post_begin: 后序序列的起始下标
     *     post_end:   后序序列的终止下标
     * Return:
     *     TreeNode* 指向树的根节点的指针
     */
    TreeNode* build(vector<int>& in, vector<int>& post, int in_begin, int in_end, int post_begin, int post_end){
        if (in_begin > in_end){ // 起始下标大于终止下标，则为空节点
            return nullptr;
        }
        int root_val = post[post_end];     // 根节点的值
        int root_index = 0;                // 根节点在中序序列中的下标
        while(in[root_index] != root_val){
            root_index++;
        }
        int len_left = root_index - in_begin;    // 左子树的序列长度
        TreeNode* root = new TreeNode(root_val); // 根节点
        root->left = build(in, post, in_begin, root_index-1, post_begin, post_begin+len_left-1);
        root->right = build(in, post, root_index+1, in_end, post_begin+len_left, post_end-1);
        return root;
    }
};