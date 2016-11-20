/*! Author: qwchen
 *! Date  : 2016-11-17
 *  20. 顺时针打印矩阵
 *  思路：此题不难，关键就是边界，边界没处理好容易造成重复打印或者数组越界
 *        要注意矩阵可能行数大于列数，也可能列数大于行数，行数和列数可能为奇数，也可能为偶数。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        // 矩阵为空直接返回
        int rowNum = matrix.size();
        if (rowNum == 0) {
            return result;
        }
        int colNum = matrix[0].size();
        if (colNum == 0) {
            return result;
        }
        int n = min(rowNum, colNum) / 2;
        for (int k = 0; k < n; k++) {
            int i = k, j = k;
            // 打印上
            for (; j <= colNum - 1 - k - 1; j++) {
                cout << matrix[i][j] << " ";
                result.push_back(matrix[i][j]);
            }
            // 打印右
            for (; i <= rowNum - 1 - k - 1; i++) {
                cout << matrix[i][j] << " ";
                result.push_back(matrix[i][j]);
            }
            // 打印下
            for (; j > k; j--) {
                cout << matrix[i][j] << " ";
                result.push_back(matrix[i][j]);
            }
            // 打印左
            for (; i > k; i--) {
                cout << matrix[i][j] << " ";
                result.push_back(matrix[i][j]);
            }
        }
        // 如果行数小于列数，并且行数为奇数，则最后还有一行要打印
        if (rowNum <= colNum) {
            if (rowNum & 1) {
                int i = n, j = n;
                for (; j <= colNum - 1 - n; j++) {
                    result.push_back(matrix[i][j]);
                }
            }
        }
        // 如果列数小于行数，并且列数为奇数，则最后还有一列要打印
        else {
            if (colNum & 1) {
                int i = n, j = n;
                for (; i <= rowNum - 1 - n; i++) {
                    result.push_back(matrix[i][j]);
                }
            }
        }
        return result;
    }
};

void testSolution(){
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {4, 5, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    Solution sol;
    vector<int> result = sol.printMatrix(matrix);
    for (int a: result) {
        cout << a << " ";
    }
    cout << endl;
}

int main() {
    testSolution();
    return 0;
}