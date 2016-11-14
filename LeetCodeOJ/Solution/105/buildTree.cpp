/*! Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 *! Author: qwchen
 *! Date  : 2016-11-14
 * 根据先序序列和中序序列构建二叉树
 * 思路：先序遍历的序列中第一个是树的根节点，后面的结点中，前面部分是根节点的左子树的结点，后面部分是根节点的右子树的结点。
 *       中序遍历的序列中树的根节点在中间，而根节点前面的部分是根节点的左子树的结点，后面的部分是根节点有右子树的结点。
 *       因此已知先序遍历序列和中序遍历序列，根据先序遍历的第一个结点确定根节点，然后从在中序遍历中寻找根节点为位置rootIndex。
 *       将中序遍历中根节点前面的序列in[0: rootIndex-1]作为左子树的中序遍历，前序遍历中pre[1:rootIndex]作为左子树的前序遍历，递归求解左子树。
 *       将中序遍历中根节点后面的序列in[rootIndex+1: in.length-1]作为右子树的中序遍历，前序遍历中pre[rootIndex+1: pre.length-1]作为右子树的前序遍历，递归求解右子树。
 * 易错点：计算下标时容易混乱
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

private:
    /*
     * Parament：
     *     pre: 先序序列
     *     in:  中序序列
     *     pre_begin: 先序序列的起始下标
     *     pre_end:   先序序列的终止下标
     *     in_begin:  中序序列的起始下标
     *     in_end:    中序序列的终止下标
     * Return:
     *     TreeNode* 指向树的根节点的指针
     */
    TreeNode* build(vector<int>& pre, vector<int>& in, int pre_begin, int pre_end, int in_begin, int in_end){
        if (pre_begin > pre_end){ // 起始下标大于终止下标，则为空节点
            return nullptr;
        }
        int root_val = pre[pre_begin];    // 根节点的值
        int root_index = in_begin;        // 根节点在中序序列中的下标
        while(in[root_index] != root_val){
            root_index++;
        }
        int len_left = root_index - in_begin;    // 左子树的序列长度
        TreeNode* root = new TreeNode(root_val); // 根节点
        root->left = build(pre, in, pre_begin+1, pre_begin+len_left, in_begin, root_index-1); // 左子树
        root->right = build(pre, in, pre_begin+len_left+1, pre_end, root_index+1, in_end);    // 右子树
        return root;
    }
};

