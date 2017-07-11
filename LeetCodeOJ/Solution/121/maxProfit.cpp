/*! Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
 *! Author: qwchen
 *! Date  : 2016-7-11
 *  买和卖股票的最佳时间
 *  有一个数组，数组每个元素表示每个时刻的股票价格，求在何时买入何时卖出能是的受益最大，求最大的受益。
 *  只能买一次和卖一次  
 */

/*
 * 思路：
 *   求如果在当前时刻买入的话，在后面何时卖出受益最大化。
 *   因此需要对每一个时刻，求其后面的最大值。用一个数来维护当前时候后面的最大值。
 * 时间复杂度：O(N). beats 16.44 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int bestSell = 0;
        for(int i = prices.size() - 1; i >= 0; i--) {
            int curProfit = bestSell - prices[i];
            if (curProfit > maxPro) maxPro = curProfit;
            if (prices[i] > bestSell) bestSell = prices[i];
        }
        return maxPro;
    }
};


/*
 * 思路：
 *   求若在当前时刻卖出的话，在前面何时买入受益最大化。
 *   因此需要对每一个时刻，求其前面的最小值。用一个数来维护当前时刻之前的最小值。
 * 时间复杂度：O(N). beats 16.44 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int bestBuy = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            int curPro = prices[i] - bestBuy;
            if (curPro > maxPro) maxPro = curPro;
            if (prices[i] < bestBuy) bestBuy = prices[i];
        }
        return maxPro;
    }
};




