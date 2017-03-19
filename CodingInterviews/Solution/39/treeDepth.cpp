/*! Author: qwchen
 *! Date  : 2016-11-23
 *  39.1 二叉树的深度
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

/* 
 * 递归版本
 */
class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return 0;
        }
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return max(left, right) + 1;
    }
};

/*
 * 非递归版本
 * 思路：
 *   注意到求是的高度是一个后序遍历，因此，借鉴树的后序遍历非递归版本的写法，就可以求出树的高度。
 *   具体是，再后序遍历中，栈的大小代表树的高度。
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
    int TreeDepth(TreeNode* pRoot) {
        int high = 0;
        stack<TreeNode*> s;
        TreeNode *p = pRoot;
        TreeNode *pre = nullptr;
        while (p != nullptr || !s.empty()) {
            while (p != nullptr) {
                s.push(p);
                if (s.size() > high) high = s.size();   // 更新树的高度
                p = p->left;
            }
            if (!s.empty()) {
                p = s.top();
                if (p->right == nullptr || p->right == pre) {
                    pre = p;
                    s.pop();
                    p = nullptr;
                }
                else {
                    p = p->right;
                }
            }
        }
        return high;
    }
};

