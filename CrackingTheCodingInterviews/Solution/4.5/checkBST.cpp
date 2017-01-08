/*! Author: qwchen
 *! Date  : 2017-01-08
 *! 树和图: 4.5 检查是否为BST
 *！题目描述：
 *      请实现一个函数，检查一棵二叉树是否为二叉查找树。
 *      给定树的根结点指针TreeNode* root，请返回一个bool，代表该树是否为二叉查找树。
 *  下面三种解法分别使用了前序、中序、后序遍历，时间复杂度和空间复杂度都相同
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
 * 思路：
 *   后序遍历
 *   注意到，二叉查找树中，每一个结点都要不小于其左子树的最大值，不大于其右子树的最小值
 *   因此，对于每一个结点，寻找其左子树的最大值和右子树的最小值，然后与其作比较
 * 时间复杂度：O(n)
 * 空间复杂度：O(logn) 递归栈的深度
 */
class Checker {
public:
    bool checkBST(TreeNode* root) {
        if (root == nullptr) return false;
        int maxChild = root->val;
        int minChild = root->val;
        return check(root, maxChild, minChild);
    }
    
private:
    bool check(TreeNode* root, int& maxChild, int& minChild) {
    	// 若树为空，则其最大值和最小值等于其父节点
        if (root == nullptr) return true;
        // 检查左子树，并找到左子树的最大值和最小值
        int maxLeftChild = root->val, minLeftChild = root->val;
        if (!check(root->left, maxLeftChild, minLeftChild)) return false;
        // 检查右子树，并找到右子树的最大值和最小值
        int maxRightChild = root->val, minRightChild = root->val;
        if (!check(root->right, maxRightChild, minRightChild)) return false;
        // 检查当前结点是否大于左子树的最大值和小于右子树的最小值
        if (root->val < maxLeftChild || root->val > minRightChild) return false;
        // 以当前结点为根的数的最小值等于其左子树的最小值，最大值等于其右子树的最大值
        maxChild = maxRightChild;
        minChild = minLeftChild;
        return true;
    }
};

/*
 * 思路：
 *   中序遍历
 *   注意到，一个一棵树是二叉查找树，那么其中序遍历肯定是一个非递减有序的数组
 *   对二叉树进行中序遍历，保留上一个遍历过的结点的值，如果当前结点的值不小于上一个结点的值，就继续遍历，直达结束，返回true
 *   如果中途出现当前结点的值小于上一个结点的值，返回false
 * 时间复杂度：O(n)
 * 空间复杂度：O(logn) 递归栈的深度
 */
class Checker {
public:
    bool checkBST(TreeNode* root) {
        if (root == nullptr) return false;
        int tail = INT_MIN;  // 标记上一个访问过的结点
        return check(root, tail);
    }
    
private:
    bool check(TreeNode* root, int& tail) {
        if (root == nullptr) return true;
        // 递归检查左子树
        if (!check(root->left, tail))  return false;
        // 检查当前结点
        if (tail > root->val) return false;
        tail = root->val;
        // 递归检查右子树
        if (!check(root->right, tail)) return false;
        // 全部检查完毕
        return true;
    }
};

/*
 * 思路：
 *   先序遍历
 *   通过先序遍历过程中自上而下传递最小和最大值来解决这个问题。
 *   从(min=INT_MIN, max=INT_MAX)这个范围开始，根节点显然落在其中。然后处理左子树，检查左子树的结点是否落在(min=INT_MIN, max=root->val)范围内。
 *   然后在处理右子树，检查这些结点是否落在(min=20, max=INT_MAX)范围内。
 *   然后，依次遍历整棵树。进入左子树时，更新max。进入右子树时，更新min。只要有任一结点不能通过检查，则停止并返回false
 * 时间复杂度：O(n)
 * 空间复杂度：O(logn) 递归栈的深度
 */
class Checker {
public:
    bool checkBST(TreeNode* root) {
        if (root == nullptr) return false;
        return check(root, INT_MIN, INT_MAX);
    }
    
private:
    bool check(TreeNode* root, int minValue, int maxValue) {
        if (root == nullptr) return true;
        // 检查当前结点
        if (root->val < minValue || root->val > maxValue) return false;
        // 递归检查左子树
        if (!check(root->left, minValue, root->val))      return false;
        // 递归检查右子树
        if (!check(root->right, root->val, maxValue))     return false;
        // 全部检查完毕
        return true;
    }
};

