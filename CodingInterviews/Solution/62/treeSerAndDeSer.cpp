/*! Author: qwchen
 *! Date  : 2016-12-01
 *  62. 序列化二叉树
 *  题目描述
 *    请实现两个函数，分别用来序列化和反序列化二叉树
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

/*
 * 思路：
 *   如果将二叉树序列化为先序遍历中序遍历的话，就可以进行反序列化还原成原来的二叉树，但是这种方法有一个前提：树中不能存在重复结点
 *   下面是一种更通用的方法，运行树存在重复结点
 *        |--1--|
 *        |     |
 *     |--2  |--3--|
 *     |     |     |
 *     4     5     6
 *   表示为：1,2,4,$,$,$,3,5,$,$,6,$,$，即进行先序遍历，并将空节点表示为$
 *   
 *   如果该题结点都为正数，可可以将$用-1表示，这样就全部都为数字了
 */
class Solution {
public:
    // 将二叉树序列化
    vector<string> serialize(TreeNode* root) {
        vector<string> seq;
        if (root == nullptr) {
            return seq;
        }
        seq = serialize2(root);
    }

    vector<string> serialize2(TreeNode* root) {
        if (root == nullptr) {
            return {"$"};
        }
        vector<string> seq;
        seq.push_back(num2str(root->val));
        vector<string> left = serialize2(root->left);
        seq.insert(seq.end(), left.begin(), left.end());
        vector<string> right = serialize2(root->right);
        seq.insert(seq.end(), right.begin(), right.end());
        return seq;
    }

    // 将二叉树反序列化
    TreeNode* deserialize(vector<string> seq) {
        if (seq.size() == 0) {
            return nullptr;
        }
        int i = 0;
        return deserialize2(seq, i);
    }

    // 注意i是传引用
    TreeNode* deserialize2(vector<string> seq, int &i) {
        if (i >= seq.size() || seq[i] == "$") {
            i++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(str2num(seq[i]));
        i++;
        root->left = deserialize2(seq, i);
        root->right = deserialize2(seq, i);
        return root;
    }


private:
    // 将字符串转化为数字
    int str2num(string s) {
        stringstream ss(s);
        int num;
        ss >> num;
        return num;
    }

    // 将数字转化为字符串
    string num2str(int num) {
        stringstream s;
        s << num;
        return s.str();
    }
};


void preOrder(TreeNode* root) {
    if (root != nullptr) {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

void testSolution() {
    Solution sol;
    vector<string> s = {"1", "2", "400", "$", "$", "$", "3", "5", "$", "$", "16", "$", "$"};
    TreeNode* root = sol.deserialize(s);          // 转化为二叉树
    // 输出二叉树的先序遍历和中序遍历
    cout << "preOrder: "; 
    preOrder(root);
    cout << endl;
    cout << "inOrder: ";
    inOrder(root);
    cout << endl;
    vector<string> result = sol.serialize(root);  // 将二叉树序列化
    // 输出序列化的结果
    for (auto i: result) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    testSolution();
    return 0;
}
