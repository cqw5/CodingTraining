/*! Author: qwchen
 *! Date  : 2016-11-8
 * 6：重建二叉树
 * 思路：先序遍历的序列中第一个是树的根节点，后面的结点中，前面部分是根节点的左子树的结点，后面部分是根节点的右子树的结点。
 *       中序遍历的序列中树的根节点在中间，而根节点前面的部分是根节点的左子树的结点，后面的部分是根节点有右子树的结点。
 *       因此已知先序遍历序列和中序遍历序列，根据先序遍历的第一个结点确定根节点，然后从在中序遍历中寻找根节点为位置rootIndex。
 *       将中序遍历中根节点前面的序列in[0: rootIndex-1]作为左子树的中序遍历，前序遍历中pre[1:rootIndex]作为左子树的前序遍历，递归求解左子树。
 *       将中序遍历中根节点后面的序列in[rootIndex+1: in.length-1]作为右子树的中序遍历，前序遍历中pre[rootIndex+1: pre.length-1]作为右子树的前序遍历，递归求解右子树。
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// 树节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/*
 * 复制数组，消耗内存太多
 */
class Solution1 {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
        if (pre.empty()) return NULL;
        // 寻找根节点在中序遍历中的位置rootIndex
        int rootIndex = 0;
        for (; rootIndex < in.size(); rootIndex++){
            if (in[rootIndex] == pre[0]) break;
        }
        TreeNode* root = new TreeNode(pre[0]); // 根节点
        vector<int> preLeft;  // 左子树的前序遍历
        vector<int> preRight; // 右子树的前序遍历
        vector<int> inLeft;   // 左子树的中序遍历
        vector<int> inRight;  // 右子树的中序遍历
        for (int i = 1; i <= rootIndex; i++){
            preLeft.push_back(pre[i]);
        }
        for (int i = rootIndex + 1; i < pre.size(); i++){
            preRight.push_back(pre[i]);
        }
        for (int i = 0; i < rootIndex; i++){
            inLeft.push_back(in[i]);
        }
        for (int i = rootIndex + 1; i < in.size(); i++){
            inRight.push_back(in[i]);
        }
        root->left = reConstructBinaryTree(preLeft, inLeft);    // 递归构建左子树
        root->right = reConstructBinaryTree(preRight, inRight); // 递归构建右子树
        return root;
    }
};

/*
 * 使用下标，不复制数组
 */
class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

private:
    TreeNode* build(vector<int>& pre, vector<int>& in, int pre_begin, int pre_end, int in_begin, int in_end){
        if (pre_begin > pre_end){
            return nullptr;
        }
        int root_val = pre[pre_begin];
        int root_index = in_begin;
        while(in[root_index] != root_val){
            root_index++;
        }
        int len_left = root_index - in_begin;
        int len_right = in_end - root_index;
        TreeNode* root = new TreeNode(root_val);
        root->left = build(pre, in, pre_begin+1, pre_begin+len_left, in_begin, root_index-1);
        root->right = build(pre, in, pre_begin+len_left+1, pre_end, root_index+1, in_end);
        return root;
    }
};

void testSolution(){
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> in  = {4,7,2,1,5,3,8,6};
    Solution2 sol;
    TreeNode* tree = sol.reConstructBinaryTree(pre, in);
}

int main(){
    testSolution();
    return 0;
}