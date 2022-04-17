/*! Source: https://leetcode-cn.com/problems/diameter-of-binary-tree/
 *! Author: qwchen
 *! Date  : 2022-04-17
 *  最长公共子序列
 */


/*
 * 思路：
 *   https://leetcode-cn.com/problems/longest-common-subsequence/solution/zui-chang-gong-gong-zi-xu-lie-by-leetcod-y7u0/
 *   创建 dp[m+1][n+1] ，用dp[i][j]表示text1[0:i-1]和text[0:j-1]的最长公共子串
 *   dp[0][j] = dp[i][0] = 0,                 , 只有一个字符串的时候没有公共子序列
 *   dp[i][j] = | dp[i-1][j-1]                , text1[i-1] == text2[j-1]
 *              | max(dp[i][j-1], dp[i-1][j]) , text1[i-1] != text2[j-1]
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(m*n)
 */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) {
            char a = text1[i-1];
            for (int j = 1; j <= n; j++) {
                char b = text2[j-1];
                if (a == b) dp[i][j] = dp[i-1][j-1] + 1;
                else        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};


