/*! Source: https://leetcode.com/problems/triangle/
 *! Author: qwchen
 *! Date  : 2016-11-09
 * 如果允许修改原来的数组，Solution为最优方案；如果不允许修改原来的数组，Solution1为最优方案。
 * test数据只用于测试是否语法错误，完整的测试见LeetCode。
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * 动态规划
 * 就地修改二维数组triangle[i][j]，用triangle[i][j]表示从三角形最底下到当前顶点的最小距离
 * 自底向上迭代求解triangle[i][j]
 * 递归方程：
 *     triangle(i,j) = min(triangle(i+1,j), triangle(i+1,j+1)) + triangle(i,j)
 * 最终triangle[0][0]就是要求解的值
 * 时间复杂度：O(n^2):n为数组的维数
 * 空间复杂度：O(1):n为数组的维数
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        for(int i = triangle.size()-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};

/*
 * 动态规划
 * 用一个一维数组f[j]来保存当前行，f[j]表示从三角形最底下到当前顶点的最小距离
 * 自底向上迭代更新一维数组f[j]
 * 递归方程：
 *     对于每一层，f(j) = min(f(j), f(j+1)) + triangle(i,j)
 * 最终f(0,0)就是要求解的值
 * 时间复杂度：O(n^2):n为数组的维数
 * 空间复杂度：O(n):n为数组的维数
 */
class Solution1 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        vector<int> f = triangle[triangle.size()-1];
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++){
                f[j] = min(f[j], f[j+1]) + triangle[i][j];
            }
        }
        return f[0];
    }
};

/*
 * 动态规划
 * 用二维数组f[i][j]表示从三角形最上面的顶点triangle[0][0]到当前顶点的最小距离
 * 自顶向下迭代求解数组f[i][j]
 * 递归方程：
 *     f(i,j) = | triangle(i,j)                               i=0,j=0
 *              | f(i-1,0) + triangle(i,j)                    i>0,j=0
 *              | min(f(i-1,j-1), f(i,j))+triangle(i,j)       i>0,0<j<i
 *              | f(i-1,j-1) + triangle(i,j)                  i>0,j=i
 * 最后求最后一行的最大小值即可
 * 时间复杂度：O(n^2):n为数组的维数
 * 空间复杂度：O(n^2):n为数组的维数
 */
class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        vector<vector<int>> f;
        vector<int> f0 = {triangle[0][0]};
        f.push_back(f0);
        for(int i = 1; i < triangle.size(); i++){
            vector<int> fi;
            fi.push_back(f[i-1][0] + triangle[i][0]);
            for(int j = 1; j < triangle[i].size()-1; j++){
                fi.push_back(min(f[i-1][j-1], f[i-1][j]) + triangle[i][j]);
            }
            fi.push_back(f[i-1][i-1] + triangle[i][i]);
            f.push_back(fi);
        }
        auto minSum = min_element(f[triangle.size()-1].begin(), f[triangle.size()-1].end());
        return *minSum;
    }
};

void testSolution(){
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    Solution1 sol1;
    cout << sol1.minimumTotal(triangle) << endl;
    Solution2 sol2;
    cout << sol1.minimumTotal(triangle) << endl;
    Solution sol;
    cout << sol.minimumTotal(triangle) << endl;
}

int main(){
    testSolution();
    return 0;
}