/*! Author: qwchen
 *! Date  : 2016-11-25
 * Solution2的是该文件最优的Solution，测试当sum=5亿时，Solution1耗时1362ms，Solution2耗时1ms
 */

#include <iostream>
#include <vector>
#include <stack>
#include <time.h>

using namespace std;

/*
 * 思路：
 *   使用一个滑动窗口：
 *       当窗口内的值小于sum时，窗口前方右移一位，增大窗口；
 *       当窗口内的值大于sum时，窗口后方右移一位，缩小窗口；
 *       当窗口内的值等于sum时，将窗口内的连续序列满足条件。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution1 {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        if (sum < 3) {
            return result;
        }
        int i = 1,
            j = 2;
        int sumOfSeq = 3;
        while (i <= sum / 2) {
            if (sumOfSeq < sum) {
                j++;
                sumOfSeq += j;
            }
            else if (sumOfSeq > sum) {
                sumOfSeq -= i;
                i++;
            }
            else {
                vector<int> seq;
                for (int k = i; k <= j; k++) {
                    seq.push_back(k);
                }
                result.push_back(seq);
                sumOfSeq -= i;
                i++;
                j++;
                sumOfSeq += j;
            }
        }
        return result;
    }
};


/*
 * 思路：
 *   考虑到，长度为k且和为sum值只序列seq最多只能有1个，并且存在k * mean(seq) == sum的特点
 *   当k是奇数时，mean(seq)是整数；序列为[sum/k - k/2, sum/k + k/2]
 *   当k为偶数时，mean(seq)是小数位为0.5的浮点数；序列为[sum/k - k/2 + 1, sum/k + k/2]
 *   另外，随着k的增大，序列中的值会越来越小；我们从k=2开始查找，每次让k+1；直到序列中最小的值<=0时，就终止不用再查找了。
 * 时间复杂度：O(k)，k为(0,sum)之间最长的连续子序列的长度，k << sum
 * 空间复杂度：O(1)
 * 题目要求结果按序列首位的数字排序，而该方法先得到的连续子序列是长度最小的，也是首位值最大的，因此先用栈存放，后续再出栈进行逆序
 */
class Solution2 {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        if (sum < 3) {
            return result;
        }
        stack<vector<int>> reResult;
        for (int i = 2; i < sum; i++) {
            if (((i & 1) == 1) && (sum % i == 0)) {  // i 是奇数
                int j = sum / i - i / 2;
                if (j <= 0) {
                    break;
                }
                vector<int> seq;
                for (; j <= sum / i + i / 2; j++) {
                    seq.push_back(j);
                }
                reResult.push(seq);
            }
            else if (((i & 1) == 0) && (1.0 * sum / i - sum / i == 0.5)) { // i是偶数
                int j = sum / i - i / 2 + 1;
                if (j <= 0) {
                    break;
                }                
                vector<int> seq;
                for (; j <= sum / i + i / 2; j++) {
                    seq.push_back(j);
                }
                reResult.push(seq);
            }
        }
        while(!reResult.empty()) {
            result.push_back(reResult.top());
            reResult.pop();
        }
        return result;
    }
};

void testSolution(){
    Solution1 sol1;
    Solution2 sol2;
    vector<vector<int>> result1;
    vector<vector<int>> result2;
    int sum = 500000000;
    clock_t start_time, end_time; 
    
    start_time = clock();
    result1 = sol1.FindContinuousSequence(sum);
    end_time = clock(); 
    int duration1 = end_time - start_time;
    cout << "Solution1: " << duration1 << "ms" << endl;

    start_time = clock();
    result2 = sol2.FindContinuousSequence(sum);
    end_time = clock(); 
    int duration2 = end_time - start_time;
    cout << "Solution2: " << duration2 << "ms" << endl;    
}

int main(){
    testSolution();
    return 0;
}
