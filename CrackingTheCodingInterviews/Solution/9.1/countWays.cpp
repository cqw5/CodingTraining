/*! Author: qwchen
 *! Date  : 2017-02-17
 *! 递归和动态规划: 9.1 上楼梯
 *! 题目描述:
 *    有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶、3阶。
 *    请实现一个方法，计算小孩有多少种上楼的方式。为了防止溢出，请将结果Mod 1000000007
 */

/*
 * 思路：
 *   递归解法。但是存在大量重复计算，时间复杂度太高
 */
class GoUpstairs {
public:
    int countWays(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;
        return ((countWays(n - 1) + countWays(n - 2)) % 1000000007 + countWays(n - 3)) % 1000000007;
    }
};

/*
 * 思路：
 *   动态规划。
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class GoUpstairs {
public:
    int countWays(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;
        vector<int> f(n, 0);
        f[0] = 1, f[1] = 2, f[2] = 4;
        for (int i = 3; i < n; i++) {
            f[i] = ((f[i - 1] + f[i - 2]) % 1000000007 + f[i - 3]) % 1000000007;
        }
        return f[n - 1];
    }
};

/*
 * 思路：
 *   动态规划。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class GoUpstairs {
public:
    int countWays(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;
        int a = 1, b = 2, c = 4;
        for (int i = 3; i < n; i++) {
            int sum = ((a + b) % 1000000007 + c) % 1000000007;
            a = b;
            b = c;
            c = sum;
        }
        return c;
    }
};

