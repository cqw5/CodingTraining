/*! Source: https://leetcode.com/problems/unique-binary-search-trees
 *! Author: qwchen
 *! Date  : 2017-03-26
 *  n个节点有多少种结构的二叉查找树
 */

/*
 * 思路：
 *   动态规划
 *   有n个节点，每个节点都可以作为BST的根，就有n种情况；每一种情况(选取一个节点作为根节点)又有(左子树种树*右子树种树)种
 *   递归方程可以表示为：f(i) = | f(0)*f(i-1) + f(1)*f(i-2) + ... + f(i-1)*f(0)  i >= 2
 *                              | 1                                              i = 0 或 1
 *   求f(n)
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n+1);
        f[0] = 1, f[1] = 1;
        // 累加到n,为了求n
        for (int i = 2; i <= n; i++) { 
        	// 对于i，可以选取1~i中任意一个节点作为根节点
            for (int j = 1; j <= i; j++) { 
                // 选取j作为根节点后：左子树有j-1个节点，有f[j-1]种情况；右子树有i-j个节点，有f[i-j]种情况
                f[i] += f[j-1] * f[i-j];   
            }
        }
        return f[n];
    }
};

