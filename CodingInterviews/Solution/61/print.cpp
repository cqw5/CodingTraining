/*! Author: qwchen
 *! Date  : 2016-12-01
 *  61. 按之字形顺序打印二叉树
 *  题目描述
 *    请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，
 *    其他行以此类推。
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
 *   使用两个栈left2right和right2left实现
 *   奇数层节点存放在栈left2right中，出栈时，对于每个元素，先将其左孩子入到right2left，再将其右孩子入到right2left
 *   偶数层节点存放在栈right2left中，出栈时，对于每个元素，先将其右孩子入到left2right，再将其左孩子入到left2right
 */
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if (pRoot == nullptr) {
            return result;
        }
        stack<TreeNode*> left2right;
        stack<TreeNode*> right2left;
        left2right.push(pRoot);
        vector<int> layer;
        while (!left2right.empty() || !right2left.empty()) {
            while (!left2right.empty()) {
            	TreeNode* top = left2right.top();
                layer.push_back(top->val);
                if (top->left != nullptr) {
                    right2left.push(top->left);
                }
                if (top->right != nullptr) {
                    right2left.push(top->right);
                }
                left2right.pop();
            }
            if (layer.size() > 0) {
                result.push_back(layer);
                layer.clear();
            }
            while (!right2left.empty()) {
				TreeNode* top = right2left.top();
                layer.push_back(top->val);
                if (top->right != nullptr) {
                    left2right.push(top->right);
                }
                if (top->left != nullptr) {
                    left2right.push(top->left);
                }
                right2left.pop();
            }
            if (layer.size() > 0) {
                result.push_back(layer);
                layer.clear();
            }
        }
        return result;
    }
    
};