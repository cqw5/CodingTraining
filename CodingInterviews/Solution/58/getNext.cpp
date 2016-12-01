/*! Author: qwchen
 *! Date  : 2016-12-01
 *  58. 二叉树的下一个节点
 *  题目描述
 *    给定一个二叉树和其中的一个节点，请找出中序遍历顺序的下一个节点并且返回。注意，树中的节点不仅包含左右子节点，同时包含指向父节点的指针。
 */

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/

/*
 * 如果当前节点有右孩子，那么下一个节点就是以其右孩子为根的子树的最左的节点
 * 否则，如果当前节点是其父节点的左孩子，那么下一个节点就是其父节点
 * 否则，当前节点就是其父节点的右孩子了，我们可以沿着父节点指针往上走，直到找到一个节点是其父节点的左孩子，则返回该节点的父节点，如果找不到，返回空。
 */

/*
 * 迭代解法
 */
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode == nullptr) {
            return nullptr;
        }
        if (pNode->right != nullptr) {
            pNode = pNode->right;
            while (pNode->left != nullptr) {
                pNode = pNode->left;
            }
            return pNode;
        }
        TreeLinkNode* parent = pNode->next;
        while(parent != nullptr && pNode != parent->left) {
            pNode = parent;
            parent = pNode->next;
        }
        return parent;
    }
};

/*
 * 递归解法
 */
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode == nullptr) {
            return nullptr;
        }
        if (pNode->right != nullptr) {
            return mostLeft(pNode->right);
        }
        return nextNode(pNode);
    }

private:
    TreeLinkNode* mostLeft(TreeLinkNode* pNode) {
       	if (pNode->left != nullptr) {
            return mostLeft(pNode->left);
        }
        return pNode;
    }
    
    TreeLinkNode* nextNode(TreeLinkNode* pNode) {
        if (pNode->next == nullptr) {
            return nullptr;
        }
        if (pNode == pNode->next->left) {
            return pNode->next;
        }
        return nextNode(pNode->next);
    }
};