/*! Author: qwchen
 *! Date  : 2016-11-10
 * 9：斐波那契数列
 * 思路：
 *   1.Solution(最优解法)：迭代，不断更新两个数来保存f(n-1)和f(n-2)
 *     时间复杂度：O(n)，空间复杂度：O(1)
 *   2.Solution2：动态规划迭代解法，用一个数组保存每个状态
 *     时间复杂度：O(n)，空间复杂度：O(n)
 *   3.Solution3：动态规划递归解法，用一个数组保存每个状态，避免重复计算
 *     段错误: 您的程序发生段错误，可能是数组越界，堆栈溢出（比如，递归调用层数太多）等情况引起
 *   4.Solution4：直接递归，大量重复计算
 *     运行超时:您的程序未能在规定时间内运行结束，请检查是否循环有错或算法复杂度过大。
 */

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Solution {
public:
    long long Fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        long long f0 = 0;
        long long f1 = 1;
        long long fn = 0;
        for (int i = 2; i <= n; i++){
            fn = f0 + f1;
            f0 = f1;
            f1 = fn;
        }
        return fn;
    }
};

class Solution1 {
public:
    long long Fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<long long> f(n + 1, 0);
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};

class Solution2 {
public:
    long long Fibonacci(int n) {
        vector<long long> f(n, -1);
        f[0] = 0;
        f[1] = 1;
        return subFibonacci(f, n);
    }

private:
    long long subFibonacci(vector<long long>& f, int n){
        if (f[n] >= 0) return f[n];
        f[n] = subFibonacci(f, n - 1) + subFibonacci(f, n - 2);
        return f[n];
    }    
};

class Solution3 {
public:
    long long Fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};

void testSolution(){
    Solution sol;
    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;
    int n = 50;
    clock_t start_time, end_time;
    int duration;
    // Solution
    start_time = clock();
    cout << sol.Fibonacci(n) << endl;
    end_time = clock();
    duration = end_time - start_time;
    cout << "Solution: " << duration << "ms" << endl;

    // Solution1
    start_time = clock();
    cout << sol1.Fibonacci(n) << endl;
    end_time = clock();
    duration = end_time - start_time;
    cout << "Solution1: " << duration << "ms" << endl;

    // Solution2
    start_time = clock();
    cout << sol2.Fibonacci(n) << endl;
    end_time = clock();
    duration = end_time - start_time;
    cout << "Solution2: " << duration << "ms" << endl;

    // Solution3
    start_time = clock();
    cout << sol3.Fibonacci(n) << endl;
    end_time = clock();
    duration = end_time - start_time;
    cout << "Solution3: " << duration << "ms" << endl;
}

int main(){
    testSolution();
    return 0;
}