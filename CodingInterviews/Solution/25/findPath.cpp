/*! Author: qwchen
 *! Date  : 2016-11-19
 *  25. 二叉树中和为某一值的路径
 */ 


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

/*
 * 思路：
 * 先序遍历二叉树。
 *     对每个节点，记录其父节点，就可以从叶子节点反向找到唯一的路径回溯到根节点。
 *     对每个叶子节点，记录从根节点到其的路径长度，就可以从中找到路径长度为某一值的路径。
 *     不像图中节点时从0开始编号的，节点数也是已知的；树中的节点数未知，编号也不是连续，可以使用map来记录节点的父节点和叶子节点的路径长度
 * 问题：如果节点值会重复，那么这个方法就不可行。
 */ 
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        preOrder(root, 0);
        // 将长度为expectNumber的路径加入到result中
        for (auto leaf: pathSumLeaf) {
            if (leaf.second == expectNumber) {
                vector<int> path;
                int key = leaf.first;
                while(key != root->val) {
                    path.insert(path.begin(), key);
                    key = preNode[key];
                }
                path.insert(path.begin(), root->val);
                result.push_back(path);
            }
        }
        return result;
    }

private:
    map<int, int> pathSumLeaf;       // 记录每个叶子节点到根节点的路径长度
    unordered_map<int, int> preNode; // 记录每个节点的父节点
    /*
     * 先序遍历，构造map pathSumLeaf 和 preNode
     */
    void preOrder(TreeNode* root, int fatherPathSum) {
        if (root->left == nullptr && root->right == nullptr) { // 叶子节点
            pathSumLeaf[root->val] = fatherPathSum + root->val;
        }
        else { // 内部节点
            if (root->left != nullptr) {
                preNode[root->left->val] = root->val;  // 让子节点的父节点指向当前节点
                preOrder(root->left, fatherPathSum + root->val);
            }
            if (root->right != nullptr) {
                preNode[root->right->val] = root->val;
                preOrder(root->right, fatherPathSum + root->val);
            }
        }
        
    }
};


/*
 * 思路：
 * 先序遍历二叉树，栈来保存从根节点到当前节点的序列，用一个变量来保存从根节点到当前节点的路径长度
 * 遍历到根节点时，判断当前路径长度是否等于期望路径长度，若是，则将当前栈中保存的路径保存下来。
 */
class Solution {
public:
    vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        vector<int> path;
        int pathLen = 0;
        preOrder(root, result, path, pathLen, expectNumber);
        return result;
    }

private:
    /*
     * root: 以当前节点为根的子树
     * result: 保存结果的数组
     * path: 理解为保存从根节点到当前节点的路径的栈
     * pathLen: 从根节点到当前节点的路径长度
     * expectNumber: 期望路径长度
     */
    void preOrder(TreeNode* root, vector<vector<int>>& result, vector<int>& path, int& pathLen, int expectNumber) {
        if (root->left == nullptr && root->right == nullptr) {  // 叶子节点
            path.push_back(root->val);
            pathLen += root->val;
            if (pathLen == expectNumber) {
                result.push_back(path);
            }
        }
        else {  // 非叶子节点
            path.push_back(root->val);
            pathLen += root->val;
            if (root->left != nullptr) {
                preOrder(root->left, result, path, pathLen, expectNumber);
                path.pop_back();
                pathLen -= root->left->val;
            }
            if (root->right != nullptr) {
                preOrder(root->right, result, path, pathLen, expectNumber);
                path.pop_back();
                pathLen -= root->right->val;
            }
        }
    }
};


