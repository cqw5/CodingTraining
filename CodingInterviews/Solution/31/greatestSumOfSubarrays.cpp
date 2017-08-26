/*! Author: qwchen
 *! Date  : 2016-11-8
 * 31：连续子数组的最大和
 * 思路：用动态规划来求解
 *       用theSum(i)表示以第i个元素结尾的子数组的最大和，我们要求的就是max(theSum(i))，
 *       则动态规划的递归方程为：
 *       theSum(i) = | array[i]                  i = 0 或 theSum(i-1) <= 0
 *                   | theSum(i-1) + array[i]    i > 0 且 theSum(i-1) > 0
 *       使用迭代法来求解动态规划的递归方程，用一个数组theSum[i]来保存theSum(i)的值。
 *       回溯求解最大子数组：从最大的theSum[i]进行回溯，如果theSum[i]>0，就将其加入子数组中
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 *
 */

#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

/*
 * 连续子数组的最大和，不需要求出该连续子数组
 */
class Solution {
public:
    int findGreatestSumOfSubArray(vector<int> array) {
        int maxSum = INT_MIN;
        int curSum = 0;
        for(int i = 0; i < array.size(); i++) {
            if(curSum <= 0) curSum = array[i];
            else            curSum += array[i];
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};


/*
 * 连续子数组的最大和，需要求出该子数组
 */
template <class T>
class Solution {
public:
    int findGreatestSumOfSubarrays(vector<T>& array, vector<T>& subarray){
        if (array.empty()) return 0; // 当数组为空，直接返回0
        int n = array.size();
        vector<T> theSum(n, 0);      // 用theSum[i]表示以第i个数字结尾的子数组的最大和
        int maxIndex = -1;           // 记录max(theSum(i))的下标      
        int maxSum = INT_MIN;       // max(theSum(i))
        // 迭代求解theSum[i]
        theSum[0] = array[0];
        for(int i = 1; i < n; i++){
            if (theSum[i-1] <= 0) theSum[i] = array[i];
            else                  theSum[i] = theSum[i-1] + array[i];
            if (theSum[i] > maxSum) {
                maxSum = theSum[i];
                maxIndex = i;
            }
        }
        if (maxSum <= 0){ // 如果maxSum <= 0,说明数组全为非正数
            subarray.push_back(array[maxIndex]);
            return maxSum;
        }
        stack<T> s;
        for (; maxIndex >= 0 && theSum[maxIndex] > 0; maxIndex--){
            s.push(array[maxIndex]);
        }
        while(!s.empty()){
            subarray.push_back(s.top());
            s.pop();
        }
        return maxSum;
    }
};

void testSolution(){
    vector<vector<int> > arrays= {
        {1, -2, 3, 10, -4, 7, 2, -5}, // 正常情况
        {},                           // 为空
        {1, 5, 2, 4, 5, 6},           // 全为正
        {-2, -4, -1, -4, -5, -6}      // 全为负
    };
    Solution<int> sol;
    for (vector<int> array: arrays){
        vector<int> subarray;
        int maxSum = sol.findGreatestSumOfSubarrays(array, subarray);
        cout << "subarray is {";
        for(int i = 0; i < subarray.size(); i++){
            cout << subarray[i] << " ";
        }
        cout << "}" << endl;
        cout << "It's sum is " << maxSum << endl << endl;
    }
}

int main(){
    testSolution();
    return 0;
}


