/*! Author: qwchen
 *! Date  : 2016-11-27
 *  43. n个骰子和为s的概率
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 思路：
 *   这是一个动态规划问题，存在大量重复子问题。
 *   该题如果用递归来求解，不避免重复计算，n个骰子，每个骰子有diceMaxValue种可能，那么时间复杂度会达到O(diceMaxValue ^ n)，指数级别的
 *   下面使用循环迭代的方式来求解：
 *     使用两个数组来存放骰子点数的每个总数出现的次数，两个数组可以叫他计算，类似于归并排序中那样使用两个数组交替。
 *     投一个骰子，一个数组的第n个数字表示骰子和为n出现的次数；
 *     投下一次骰子，另一个数组和为n的骰子出现的次数为n-1、n-2、n-3、n-4、n-5、n-6之和。
 *     投递第k个骰子，出现点数之和在区间[k, k*diceMaxValue]之内，因此只需要计算数组在该区间之内的值，超出该区间的值都设置为0.
 * 时间复杂度：O(diceMaxValue * n * n) = O(n^2)
 * 空间复杂度：O(diceMaxValue * n)     = O(n)
 * diceMaxValue为骰子的最大点数，通常为6，是一个常数
 */
class Solution {
public:
    /*
     * 假定每个骰子最大点数为diceMaxValue, 投n个骰子，求出现的每一种点数之和的概率
     * 返回数组中，数组的下标代表和的值，数组的值代表和为该下标的数出现的概率
     */
    vector<double> diceProb(int diceMaxValue, int n) {
        vector<double> result;
        if (n <= 0) return result;
        // 两个交替计算的辅助数组，数组的第n为表示骰子和为n出现的次数
        vector<vector<int>> count(2);
        count[0].assign(n * diceMaxValue + 1, 0);
        count[1].assign(n * diceMaxValue + 1, 0);
        int flag = 0;
        // 投第1个骰子时，每种结果出现的次数为1
        for (int i = 1; i <= diceMaxValue; i++) {
            count[flag][i] = 1;
        }
        // 计算投第2到第n个骰子时的结果
        for (int k = 2; k <= n; k++) {
            // 区间[k, k*diceMaxValue]之外的都为0
            for (int i = 1; i < k; i++) {
                count[1-flag][i] = 0;
            }
            // 计算区间[k, k*diceMaxValue]之间
            for (int i = k; i <= k * diceMaxValue; i++) {
                count[1-flag][i] = 0;  // 必须清0
                for (int j = 1; j <= diceMaxValue && i-j > 0; j++) { // i-j > 0，防止数组下标访问向下越界
                    count[1-flag][i] += count[flag][i-j];
                }
            }
            flag = 1 - flag;
        }
        // 投n个筛子所有可能结果
        int totalCount = 1;
        for (int i = 0; i < n; i++) {
            totalCount *= diceMaxValue;
        }
        // 计算概率
        for (int i = 1; i < count[flag].size(); i++) {
            result.push_back((double)count[flag][i] / totalCount);
        }
        return result;
    } 
};


void testSolution() {
    Solution sol;
    vector<double> result = sol.diceProb(6, 6);
    for (int i = 0; i < result.size(); i++) {
        cout << i << " : " << result[i] << endl;
    }
}

int main() {
    testSolution();
    return 0;
}
