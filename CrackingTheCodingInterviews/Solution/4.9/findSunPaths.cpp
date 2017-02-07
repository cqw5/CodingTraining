/*! Author: qwchen
 *! Date  : 2017-02-07
 *! 树和图: 4.9 打印二叉树种节点数值总和等于某个给定值的所有路径
 */

/*
 * 简化版本：假设路径必须从根节点开始，但可以在任意节点结束
 * 思路：
 *   先序遍历，保持从根节点到当前节点的路径，若路径等于sum
 * 时间复杂度：O(n)
 */
class Solution {
public:
    vector<vector<int>> findSunPaths(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        int current = 0;
        findPath(root, paths, path, sum, current);
        return paths;
    }

private:
    void findPath(TreeNode* root, vector<vector<int>>& paths, vector<int>& path, int sum, int& current) {
        if (root == nullptr) return;
        path.push_back(root->value);
        current += root->value;
        if (current == sum) { 
            paths.push_back(path);
        }
        findPath(root->left, paths, path, sum, current);
        current -= path.back();
        path.pop_back();
        findPath(root->right, paths, path, sum, current);
        current -= path.back();
        path.pop_back();
    }
};


/*
 * 推广：路径可以从人一个节点开始
 * 思路：
 *   在前面简化版本，已经可以求得根节点到每一个节点的路径。现在，我们递归访问每个节点，获得根节点到当前节点的路径。
 *   随后，从当前节点反向到root，将路径上的节点值加起来。但每条路径总和等于sum时，就保存该路径。
 * 时间复杂度：O(n*logn)
 */
class Solution {
public:
    vector<vector<int>> findSunPaths(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        findPath(root, paths, path, sum);
    }

private:
    bool findPath(TreeNode* root, vector<vector<int>>& paths, vector<int>& path, int sum) {
        if (root == nullptr) return;
        path.push_back(root->value);
        int current = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            current += path[i];
            if (current == sum) {
                vector<int> currentPath;
                for (int j = i; j < path.size(); j++) {
                    currentPath.push_back(path[j]);
                }
                paths.push_back(currentPath);
            }
        }
        findPath(root->left, paths, path, sum);
        path.pop_back();
        findPath(root->right, paths, path, sum);
        path.pop_back();
    }
};

