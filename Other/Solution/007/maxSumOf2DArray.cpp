/*! Author: qwchen
 *! Date  : 2017-09-06
 *  二维数组中子数组之和的最大值（编程之美2.15）
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
 * 思路：
 *   定义该和最大的子数组4个顶点分别为:(i_min,j_min),(i_min,j_max)
 *                                 (i_max,j_min),(i_max,j_max)
 *   其中由(i_min,j_min)和(i_max,j_max)来确定一个子数组
 *
 *   暴力解法的情况下:(i_min,j_min)和(i_max,j_max)分别有m*n种可能，即有m*m*n*n种可能的子二维数组，并且求子二位数组的时间复杂度为O(Sum)
 *                   此时的时间复杂度为O(m*m*n*n*Sum)
 *   我们可以用空间换时间，先把Sum计算好，是的后续可以在O(1)的时间复杂度内求Sum。
 *
 *   如果我们把这个问题看出确定子数组的上下边界和左右边界的问题：
 *   我们可以遍历所有可能的上下边界，O(m*m)；那么确定左右边界时，如果把某一列在上下边界之间的元素看成一个整体（和），那么这个问题就转化为一维数组的子数组的最大和。O(n)
 *   求子数组某一列所有元素的和，我们可以先预先计算好，保存起来，这样后续就可以在O(1)的时间复杂度内完成这个操作。
 *   具体就是，用一个二维数组BC，其中BC[i][j]表示第j列中从第0行到当前行所有元素的和，那么后续BC[i,j,k](第k列第i行到第j行的所有元素的和)=BC[j][k]-BC[i-1][k]
 *   这样可以使得时间复杂度降低到O(m*m*n)
 *
 * 时间复杂度：O(m*m*n)
 * 空间复杂度：O(m*n)
 */
int maxSum(vector<vector<int> >& A) {
    int m = A.size();
    if(m < 0) return 0;
    int n = A[0].size();
    if(n < 0) return 0;
    vector<int> row(n, 0);
    vector<vector<int> > BC(m, row);
    // BC[i][j]表示第j列中从第0行到当前行所有元素的和，那么后续:
    // BC[i,j,k](第k列第i行到第j行的所有元素的和)= | BC[j][k]            , i=0
    //                                          | BC[j][k]-BC[i-1][k] , i>0
    for(int j = 0; j < n; j++) {
        BC[0][j] = A[0][j];
        for(int i = 1; i < m; i++) {
            BC[i][j] = BC[i-1][j] + A[i][j];
        }
    }
    int res = INT_MIN;
    // i和j表示子数组的上界和下界，k表示列下标
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            int curMax = 0;
            for(int k = 0; k < n; k++) {
                int curVal = 0;
                if(i == 0) curVal = BC[j][k];
                else       curVal = BC[j][k] - BC[i-1][k];
                if(curMax >= 0) curMax += curVal;
                else            curMax = curVal;
                if(curMax > res) res = curMax;
            }
        }
    }
    return res;
}

int main() {
    int arr[4][4] = {
        {1, -2, 3, 4},
        {2, -5, 1, 5},
        {3, 4, 4, 6},
        {-2, 1, 5, -4}
    };
    vector<int> row(4, 0);
    vector<vector<int> > A(4, row);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            A[i][j] = arr[i][j];
        }
    }
    cout << maxSum(A) << endl;
    return 0;
}


