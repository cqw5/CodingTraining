/*! Author: qwchen
 *! Date  : 2017-01-08
 *! 树和图: 4.6 寻找下一个结点
 *！题目描述：
 *      请设计一个算法，寻找二叉树中指定结点的下一个结点（即中序遍历的后继）。
 *      给定树的根结点指针TreeNode* root和结点的值int p，请返回值为p的结点的后继结点的值。
 *      保证结点的值大于等于零小于等于100000且没有重复值，若不存在后继返回-1。
 */

/*
 * 假定结点不存在指向父节点的指针
 * 思路：
 *   对二叉查找树进行中序遍历，有一个引用变量记录上一个结点
 * 时间复杂度：0(n)
 * 空间复杂度：O(logn) 递归栈的深度
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Successor {
public:
    int findSucc(TreeNode* root, int p) {
        int next = -1;
        int tail = -1;
        findSucc(root, p, tail, next);
        return next;
    }
    
private:
    bool findSucc(TreeNode* root, int p, int& tail, int& next) {
        if (root == nullptr) return false;
        if (findSucc(root->left, p, tail, next)) return true;
        if (tail == p) {
            next = root->val;
            return true;
        }
        else {
            tail = root->val;
        }
        if (findSucc(root->right, p, tail, next)) return true;
        return false;
    }
};

/*
 * 假设结点存在指向父节点的指针
 * 思路：
 *   如果当前结点存在右孩子，则后续结点在右子树的最左结点中
 *   否则，如果该结点为父节点的左孩子，则父节点为后续结点
 *   否则，往父节点回溯，直到当前结点为父节点的左孩子，则父节点为后续结点；或者父节点为空，则没有后序结点，返回null
 * 时间复杂度：O(logn)
 * 空间复杂度：O(1)
 */
struct TreeNode {
    int val;
    TreeNode *parent;  // 指向父节点的指针
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Successor {
public:
    TreeNode* findSucc(TreeNode* p) {
        if (p == nullptr) return nullptr;
        // p存在右孩子，从右孩子寻找后续结点
        if (p->right != nullptr) {
            p = p->right;
            while (p->left != nullptr) {
                p = p->left;
            }
            return p;
        }
        // p没有右孩子，从祖先寻找后续结点
        TreeNode* pp = p->parent;
        while (pp != nullptr && p != pp->left) {
            p = pp;
            pp = p->parent;
        }
        return pp;
    }
};

