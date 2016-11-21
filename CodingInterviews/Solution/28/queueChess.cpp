/*! Author: qwchen
 *! Date  : 2016-11-21
 *  28.2. 八皇后问题
 *  在8*8的国家象棋上摆放8个皇后，使其不能相互攻击，即任意两个皇后不得处在同一行、同一列或者同一对角线上。
 *  求可以有多少种摆放方法？
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 思想：由于8个皇后的任意不能处在相同一行，那么肯定是每一个皇后占据一行。
 *       定义一个数组colIndex[8]，数组中第i个下标i表示第i行的皇后，第i个数字表示位于第i列的皇后的列号。
 *       首先把colIndex的8个数字分别初始化为0-7，接下来对于0-7进行全排列；由于我们使用不同的数字初始化数组，所以任意两个皇后肯定在不同列。
 *       我们只需要判断皇后是不是在同一个对角线上，即对于任意的i和j，是否存在i - j == queen[i] - queen[j]) || (j - i == queen[i] - queen[j])
 */
class Solution {
public:
    int queenChess() {
        vector<int> colIndex = {0, 1, 2, 3, 4, 5, 6, 7};    
        vector<vector<int>> result;
        permutation(result, colIndex, 0, colIndex.size()-1);
        int count = 0;
        for (vector<int> queen: result) {
            bool isQueen = true;
            for (int i = 0; i < queen.size(); i++) {
                for (int j = i+1; j < queen.size(); j++) {
                    if ((i - j == queen[i] - queen[j]) || (i - j == queen[j] - queen[i])) {
                        isQueen = false;
                    }
                }
            }
            if (isQueen) {
                count++;
                for (int q: queen) {
                    cout << q << " ";
                }
                cout << endl;
            }
        }
        return count;
    }

private:
    void permutation(vector<vector<int>>& result, vector<int>& colIndex, int k, int n) {
        if (k == n) {
            result.push_back(colIndex);
            return;            
        }
        for (int i = k; i <= n; i++) {
            swap(colIndex[i], colIndex[k]);
            permutation(result, colIndex, k+1, n);
            swap(colIndex[i], colIndex[k]);
        }
    }
};

void testSolution() {
    Solution sol;
    int count = sol.queenChess();
    cout << count << endl;
}

int main() {
    testSolution();
    return 0;
}

