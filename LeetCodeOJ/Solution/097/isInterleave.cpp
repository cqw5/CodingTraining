/*! Source: https://leetcode.com/problems/interleaving-string/
 *! Author: qwchen
 *! Date  : 2016-11-09
 * 判断字符串s3是否由s1和s2组成
 * Solution 为该文件最优的方案
 * test数据只用于测试是否语法错误，完整的测试见LeetCode。
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 动态规划
 * 用一个二维数组bool f[i][j]表示s3[0,i+j)是否由s1[0,i)和s2[0,j)，是为true，否为false
 * 动态规划的递归方程：
 * f(i,j) = | true                                                                          i=0,j=0,即s1,s2都为空
 *          | (s1[i-1] == s3[i+j-1]) && f(i-1,0)                                            i>0,j=0 
 *          | (s2[j-1] == s3[i+j-1]) && f(0,j-1)                                            i=0,j>0
 *          | [(s1[i-1] == s3[i+j-1]) && f(i-1,0)] || [(s2[j-1] == s3[i+j-1]) && f(0,j-1)]  i>0,j>0
 * 迭代填表求解f(i,j)
 * 则f(s1.size(), s2.size())是所求
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n^2)
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len1 + len2 != len3) return false;
        if (len1 == 0) return s2 == s3;
        if (len2 == 0) return s1 == s3;
        vector<vector<bool>> f(len1+1, vector<bool>(len2+1, true)); // 初始为false或true都可以，初始为false的话，需要加f[0][0] = true
        for (int i = 1; i <= len1; i++){
            f[i][0] = (s1[i-1] == s3[i-1]) && f[i-1][0]; 
        }
        for (int j = 1; j <= len2; j++){
            f[0][j] = (s2[j-1] == s3[j-1]) && f[0][j-1];
        }
        for (int i = 1; i <= len1; i++){
            for (int j = 1; j <= len2; j++){
                f[i][j] = ((s1[i-1] == s3[i+j-1]) && f[i-1][j]) 
                        ||((s2[j-1] == s3[i+j-1]) && f[i][j-1]);
            }
        }
        return f[len1][len2];
    }
};

void testSolution(){
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";  // true
    string s4 = "aadbbbaccc";  // false
    Solution sol;
    cout << sol.isInterleave(s1, s2, s3) << endl;
    cout << sol.isInterleave(s1, s2, s4) << endl;
}

int main(){
    testSolution();
    return 0;
}