/*! Author: qwchen
 *! Date  : 2017-02-17
 *! 递归和动态规划: 9.2 机器人走方格I
 *! 题目描述
 *    有一个XxY的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。请设计一个算法，计算机器人有多少种走法。
 *    给定两个正整数int x,int y，请返回机器人的走法数目。保证x＋y小于等于12。
 */

/*
 * 思路：
 *   动态规划，类似于编辑距离的解法
 * 时间复杂度：O(x * y)
 * 空间复杂度：O(min(x, y))，利用滚动数组
 */
class Robot {
public:
    int countWays(int x, int y) {
        if (x <= 0 || y <= 0) return 0;
        if (x > y) return countWays(y, x);
        vector<int> f(x, 1);
        for (int i = 1; i < y; i++) {
            for (int j = 1; j < x; j++) {
                f[j] = f[j - 1] + f[j];
            }
        }
        return f[x - 1];
    }
};

