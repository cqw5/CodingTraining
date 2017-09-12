/*! Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
 *! Author: qwchen
 *! Date  : 2016-7-11
 *  买和卖股票的最佳时间II
 *  有一个数组，数组每个元素表示每个时刻的股票价格，求在何时买入何时卖出能是的受益最大，求最大的受益。
 *  可以买多次和卖多次
 */

/*
 * 思路：
 *   如果考虑保障交易次数最少。
 *   股票趋势可以看成一条上下波动的曲线，从头到位找到所有的上升线段的起点和终点，将其差累加即可。
 * 时间复杂度：O(N). beats 38.28 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int buy = -1, sell = -1;
        int maxPro = 0;
        int i = 0;
        while (i < prices.size() - 1) {
            // 寻找上升线段的起点
            while (i < prices.size() - 1) {
                if (prices[i] < prices[i+1]) {
                    buy = prices[i++];
                    break;
                }
                else {
                    i++;
                }
            }
            // 寻找上升线段的终点
            while (i < prices.size() - 1) {
                if (prices[i] > prices[i+1]) {
                    sell = prices[i++];
                    break;
                }
                else {
                    i++;
                }
            }
            // 注意点前面因为用到i+1，因此终止条件就是<prices.size()-1，没有考虑到最后一个元素，这里考虑最后一个元素
            if (i == prices.size() - 1 && buy != -1) {
                sell = max(sell, prices[n-1]);
            }
            maxPro += sell - buy;
            sell = -1;
            buy = -1;
        }
        return maxPro;
    }
};



/*
 * 思路：
 *   如果不考虑保障交易次数最少。但是实际上，股票交易是有成本的。
 *   这是这道题的Bug。
 * 时间复杂度：O(N). beats 10.17 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        for (int i = 1; i < prices.size(); i++) {
            maxPro += max(prices[i] - prices[i-1], 0);
        }
        return maxPro;
    }
};


