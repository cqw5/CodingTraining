/*! Author: qwchen
 *! Date  : 2016-11-23
 *  39. 二叉树的深度
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
    	if (pRoot == nullptr) {
            return 0;
        }
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return max(left, right) + 1;
    }
};