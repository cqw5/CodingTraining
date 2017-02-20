/*! Author: qwchen
 *! Date  : 2017-02-20
 *! 递归和动态规划: 9.8 硬币表示
 *！题目描述：
 *    有数量不限的硬币，币值为25分、10分、5分和1分，请编写代码计算n分有几种表示法。
 *    给定一个int n，请返回n分有几种表示法。
 *
 * 网上的DP方案：http://www.cnblogs.com/python27/archive/2013/09/05/3303721.html
 */

/*
 * 思路：
 *   递归，暴力求解
 *   对于25取遍所有可能，剩下的10再取遍所有可能，剩下的5再取遍所有可能，剩下的1就只有一种可能（全为1）
 *   有大量重复子问题，会超时
 */
class Coins {
public:
    int countWays(int n) {
        if (n <= 0) {
            return 0;
        }
        return countWays(n, 25);
    }

private:
    int countWays(int n, int denom) {
       	int nextDenom;
        if (denom == 25)      nextDenom = 10;
        else if (denom == 10) nextDenom = 5;
        else if (denom == 5)  nextDenom = 1;
        else                  return 1;
        int ways = 0;
        for (int i = 0; i * denom <= n; i++) {
            ways += countWays(n - i * denom, nextDenom);
            
        }
        return ways;
    }
};

/*
 * 思路：
 *   动态规划
 *   链接：https://www.nowcoder.com/questionTerminal/c0503ca0a12d4256af33fce2712d7b24
 *   假如只有1元，那对于任给的1~n，必然只有1中组合方法。
 *   假设增加一种新面值：coin元。对于任意i（i属于1~n），
 *   当i<coin的时候，新面值组合方法为0，dp[i]不变。
 *   当i=coin，新组合方法为1，总dp[i]=旧dp[i]+1
 *   当coin<i<2coin，新组合方法仍然为1，总dp[i]=旧dp[i] + 新dp[i-coin]
 *   当i=2coin，仍然有总 dp[i]=旧dp[i] + 新dp[i- coin]
 */
class Coins {
public:
    int countWays(int n) {
        if (n <= 0) {
            return 0;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        vector<int> coins = {1, 5, 10, 25};
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= n; j++) {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        return dp[n];
    }
};