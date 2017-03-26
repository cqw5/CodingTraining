/*! Source: https://leetcode.com/problems/edit-distance/
 *! Author: qwchen
 *! Date  : 2016-11-09
 * Solution 为该文件最优的方案
 * test数据只用于测试是否语法错误，完整的测试见LeetCode。
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*
 * 动态规划 + 滚动数组
 * 用一维数组dist[i]滚动保存中间状态，用一个变量upper_left记录distance[i-1][j-1]
 * 递归方程：
 *     dist(i,j) = | min(dist(i-1,j)+1, dist(i,j-1)+1, dist(i-1, j-1))      word1[i-1] == word[j-1]
 *                 | min(dist(i-1,j)+1, dist(i,j-1)+1, dist(i-1, j-1)+1)    word1[i-1] != word[j-1]
 * 迭代求解dist数组
 * 最终dist[word2.size()]就是要求的解
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(n) if m > n; O(m) if m < n
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (m <= 0) return n;
        if (n <= 0) return m;
        if (m < n) return minDistance(word2, word1);
        vector<int> dist(n+1, 0);
        for (int i = 0; i <= n; i++) {
            dist[i] = i;
        }
        for (int i = 1; i <= m; i++) {
            int temp = dist[0];
            dist[0] = i;
            for (int j = 1; j <= n; j++) {
                int minDist = min(dist[j-1], dist[j]) + 1;
                if (word1[i-1] == word2[j-1]) minDist = min(temp, minDist);
                else                          minDist = min(temp + 1, minDist);
                temp = dist[j];
                dist[j] = minDist;
            }
        }
        return dist[n];
    }
};

/*
 * 动态规划
 * 用二维数组dist[i][j]保存中间状态
 * 递归方程：
 *     dist(i,j) = | min(dist(i-1,j)+1, dist(i,j-1)+1, dist(i-1, j-1))      word1[i-1] == word[j-1]
 *                 | min(dist(i-1,j)+1, dist(i,j-1)+1, dist(i-1, j-1)+1)    word1[i-1] != word[j-1]
 * 迭代求解dist数组
 * 最终dist[word1.size()][word2.size()]就是要求的解
 * 时间复杂度：O(n*m)
 * 空间复杂度：O(n*m)
 */
class Solution1 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (m <= 0) return n;
        if (n <= 0) return m;
        // dist[m+1][n+1]
        vector<int> col(n+1, 0);
        vector<vector<int>> dist(m+1, col);
        for (int i = 0; i <= n; i++) {
            dist[0][i] = i;
        }
        for (int i = 1; i <= m; i++) {
            dist[i][0] = i;
            for (int j = 1; j <= n; j++) {
                int minDist = min(dist[i-1][j], dist[i][j-1]) + 1;
                if (word1[i-1] == word2[j-1]) dist[i][j] = min(dist[i-1][j-1], minDist);
                else                          dist[i][j] = min(dist[i-1][j-1] + 1, minDist);
            }
        }
        return dist[m][n];
    }
};


void testSolution(){
    string word1 = "oslo";
    string word2 = "snow";
    Solution sol;
    cout << sol.minDistance(word1, word2) << endl;
    Solution1 sol1;
    cout << sol1.minDistance(word1, word2) << endl;
}

int main(){
    testSolution();
    return 0;
}

