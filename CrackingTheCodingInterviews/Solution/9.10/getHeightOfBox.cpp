/*! Author: qwchen
 *! Date  : 2017-02-21
 *! 递归和动态规划: 9.10 堆箱子
 *！题目描述：
 *    有一堆箱子，每个箱子宽为wi，长为di，高为hi，现在需要将箱子都堆起来，而且为了使堆起来的箱子不到，上面的箱子的宽度和长度
 *    必须小于下面的箱子。（箱子不能翻转）。请实现一个方法，求出能堆出的最高的高度，这里的高度即堆起来的所有箱子的高度之和。
 *    给定三个int数组w,l,h，分别表示每个箱子宽、长和高，同时给定箱子的数目n。请返回能堆成的最高的高度。保证n小于等于500。
 */

/*
 * 思路：
 *   先按照箱子的长度或者宽度对箱子进行从大到小排序
 *   然后使用动态规划，用一个长度为n的数组来保存堆到当前箱子所能达到的最大高度。（题目就类似于求数组的最长连续子串）
 *   对于每一个箱子，求其与前面的每个箱子所可能堆成的最高高度的组合，找出能组合成最高的那个组合
 *   用一个变量来保存当前的全局的最高高度。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 */
class Box {
public:
    int getHeight(vector<int> w, vector<int> l, vector<int> h, int n) {
        if (n <= 0) return 0;
        // 先使用冒泡排序按箱子的宽度进行排序（从大到小）
        for (int i = n; i > 1; i--) {
            for (int j = 0; j < i - 1; j++) {
                if (w[j] < w[j + 1]) {
                    swap(w[j], w[j + 1]);
                    swap(l[j], l[j + 1]);
                    swap(h[j], h[j + 1]);
                }
            }
        }
        vector<int> dp(n, 0);
        dp[0] = h[0];
        int res = dp[0];
        for (int i = 1; i < n; i++) {
            int temp = 0;
            dp[i] = h[i];
            for (int j = i - 1; j >= 0; j--) {
                if (w[j] > w[i] && l[j] > l[i]) {
                    temp = max(temp, dp[j]);
                }
            }
            dp[i] += temp;
            res = max(res, dp[i]);
        }
        return res;
    }
};

