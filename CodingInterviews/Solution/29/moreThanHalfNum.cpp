/*! Author: qwchen
 *! Date  : 2016-11-21
 *  29. 数组中出现次数超过一半的数字
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 思路：遍历一遍数组，用一个字典保存每个元素的计数；再遍历一遍字典寻找计数最大的元素；如果最大计数大于数组长度的一半，返回该元素，否则返回0
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    int moreThanHalfNum(vector<int> numbers) {
        if (numbers.size() == 0) {
            return 0;
        }
        unordered_map<int, int> count;  // 用一个无序字典保存每个元素的计数
        // 遍历一遍数组，统计每个元素的计数
        for (int i = 0; i < numbers.size(); i++) {
            count[numbers[i]] = count[numbers[i]] + 1;
        }
        // 遍历一遍字典寻找计数最大的元素
        int maxNum = 0;
        int maxCount = 0;
        for (auto elem: count) {
            if (elem.second > maxCount) {
                maxCount = elem.second;
                maxNum = elem.first;
            }
        }
        // 如果最大计数大于数组长度的一半，返回该元素，否则返回0
        if (maxCount > numbers.size()/2) {
            return maxNum;
        }
        else {
            return 0;
        }
    }
};


/* 
 * 思路：遍历两遍数组
 *       第一遍遍历时，保存两个值，一个是数组中的一个元素，一个是一个次数。当我们遍历到下一个元素与我们之前保存的元素相同时，次数+1，
 *           如果下一个元素与之前保存的那个元素不同时，则次数-1。如果次数为0时，我们需要保存下一个元素，并把次数设为1。
 *           如果我们要找的元素出现的次数比数组其他所有元素出现的次数还要多，那么最后存下了的元素肯定是该次数超过元素一半的元素。
 *           如果我们要找的元素不存在，最后也会存下了一个元素，因此我们要进行第二次变量，判断最后保存下来的元素的次数是不是大于数组元素个数的一半。
 *       第二遍遍历时，计数最后保存下来的元素的次数是不是大于数组元素个数的一半。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution2 {
public:
    int moreThanHalfNum(vector<int> numbers) {
        if (numbers.size() == 0) {
            return 0;
        }
        // 第一次遍历，寻找元素
        int num = numbers[0];
        int count = 1;
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] == num) {
                count++;
            }
            else {
                count--;
            }
            if (count == 0) {
                num = numbers[i];
                count = 1;
            }
        }
        // 第二次遍历，判断该元素出现的次数是不是超过数组的一半
        count = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] == num) {
                count++;
            }
        }
        if (count > numbers.size() / 2) {
            return num;
        }
        else {
            return 0;
        }
    }
};


void testSolution() {
    vector<int> a = {1,2,3,2,2,2,4,5,2,2,2,2,4,2,5,3,2,4,3,2,3,2,4,2,2,2,4};
    Solution1 sol1;
    Solution2 sol2;
    cout << sol1.moreThanHalfNum(a) << endl;
    cout << sol2.moreThanHalfNum(a) << endl;
}

int main() {
    testSolution();
    return 0;
}

