/*! Source: https://leetcode.com/problems/binary-tree-level-order-traversal/
 *! Author: qwchen
 *! Date  : 2016-11-14
 * 二叉树的层次遍历
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
 * 使用两个队列实现，交替存储邻接层
 */
class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderSeq;
        if (root == nullptr){
            return levelOrderSeq;
        }
        queue<TreeNode*> theQueue1;
        queue<TreeNode*> theQueue2;
        vector<int> currentLevelSeq;
        theQueue1.push(root);
        while(!theQueue1.empty() || !theQueue2.empty()){
            // 如果队列1非空，将队列1中的结点出队，并将其val放到当前层序列中
            // 同时，将队列中结点的子节点放到队列2中
            while(!theQueue1.empty()){
                TreeNode* currentNode = theQueue1.front();
                currentLevelSeq.push_back(currentNode->val);
                if (currentNode->left != nullptr)  theQueue2.push(currentNode->left);
                if (currentNode->right != nullptr) theQueue2.push(currentNode->right);
                theQueue1.pop();
            }
            // 将当前层序列追加到层次遍历的序列中，清空当前队列
            if (!currentLevelSeq.empty()){
                levelOrderSeq.push_back(currentLevelSeq);
                currentLevelSeq.clear();
            }
            // 如果队列2非空，将队列2中的结点出队，并将其val放到当前层序列中
            // 同时，将队列中结点的子节点放到队列1中
            while(!theQueue2.empty()){
                TreeNode* currentNode = theQueue2.front();
                currentLevelSeq.push_back(currentNode->val);
                if (currentNode->left != nullptr)  theQueue1.push(currentNode->left);
                if (currentNode->right != nullptr) theQueue1.push(currentNode->right);
                theQueue2.pop();
            }
            // 将当前层序列追加到层次遍历的序列中，清空当前队列
            if (!currentLevelSeq.empty()){
                levelOrderSeq.push_back(currentLevelSeq);
                currentLevelSeq.clear();
            }
        }
        return levelOrderSeq;
    }
};

/*
 * 使用一个队列实现，不同层之间用一个NULL指针分割
 */
class Solution2 {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> levelOrderSeq;
        if (root == nullptr){
            return levelOrderSeq;
        }
        queue<TreeNode*> theQueue;
        vector<int> currentLevelSeq;
        theQueue.push(root);
        theQueue.push(nullptr); // 在第一层结尾处加上nullptr
        while(!theQueue.empty()){
            TreeNode* currentNode = theQueue.front();
            theQueue.pop();
            // 如果为nullptr，说明当前层取完了，将当前层序列加入到层次遍历序列中
            // 取出nullptr后，如果此时队列为空，说明层次遍历结束了；如果此时队列非空，说明又有新的元素加进来了。
            if (currentNode == nullptr){  
                levelOrderSeq.push_back(currentLevelSeq);
                currentLevelSeq.clear();
                if (!theQueue.empty()){
                    theQueue.push(nullptr);
                }
            }
            else {
                currentLevelSeq.push_back(currentNode->val);
                if (currentNode->left != nullptr)  theQueue.push(currentNode->left);
                if (currentNode->right != nullptr) theQueue.push(currentNode->right);
            }
        }
        return levelOrderSeq;
    }
};


/*
 * 不需要队列，使用深度优先进行层次遍历
 *
 * 在maxDepth中使用分3行求left = maxDepth(root->left); right = maxDepth(root->right); max(left, right) + 1
 * 效率为beats 21% of cpp submissions.
 * 在maxDepth中使用 max(maxDepth(root->left), maxDepth(root->right)) + 1;
 * 效率飙到 beats 93.29% of cpp submissions.
 */
class Solution3 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int high = maxDepth(root);
        vector<vector<int>> levelOrderSeq(high);
        dfs(root, 0, levelOrderSeq);
        return levelOrderSeq;
    }
    
private:
    int maxDepth(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    
    void dfs(TreeNode* root, int level, vector<vector<int>>& levelOrderSeq){
        if (root == nullptr){
            return;
        }
        levelOrderSeq[level].push_back(root->val);
        dfs(root->left, level+1, levelOrderSeq);
        dfs(root->right, level+1, levelOrderSeq);
    }
};