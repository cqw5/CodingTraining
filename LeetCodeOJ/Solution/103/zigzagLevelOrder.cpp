/*! Source: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 *! Author: qwchen
 *! Date  : 2016-11-14
 * 二叉树的锯齿形层次遍历
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
 * 使用一个队列实现，不同层之间用一个NULL指针分割
 * 用一个level来记录层号，使用位运算来判断当前是奇数层还是偶数层
 *     在奇数层中，向当前序列的尾部追加元素
 *     在偶数层中，向当前序列的头部插入元素
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> seq;
        if (root == nullptr){
            return seq;
        }
        queue<TreeNode*> q;
        vector<int> cur_seq;
        q.push(root);
        q.push(nullptr); // 在第一层结尾处加上nullptr
        int level = 1;   // 标记层数
        while(!q.empty()){
            TreeNode* cur_node = q.front();
            q.pop();
            // 如果为nullptr，说明当前层取完了，将当前层序列加入到层次遍历序列中
            // 取出nullptr后，如果此时队列为空，说明层次遍历结束了；如果此时队列非空，说明又有新的元素加进来了
            if (cur_node == nullptr){
                seq.push_back(cur_seq);
                cur_seq.clear();
                level++;
                if (!q.empty()){
                    q.push(nullptr);
                }
            }
            else {
                if (level & 1){ // 在奇数层中，向当前序列的尾部追加元素
                    cur_seq.push_back(cur_node->val);
                } else {        // 在偶数层中，向当前序列的头部插入元素
                    cur_seq.insert(cur_seq.begin(), cur_node->val);
                }
                if (cur_node->left != nullptr) {
                    q.push(cur_node->left);
                }
                if (cur_node->right != nullptr){
                    q.push(cur_node->right);
                }
            }
        }
        return seq;
    }
};


/*
 * 该题也可以使用两个栈来实现，不过比较繁琐
 */