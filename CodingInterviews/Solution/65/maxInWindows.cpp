/*! Author: qwchen
 *! Date  : 2016-12-03
 *  65. 滑动窗口的最大值
 *  题目描述
 *    给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 *    例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
 *    针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
 *      {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/*
 * 思路：
 *   如果使用暴力解法，对每个窗口都变成寻找其最大元素，时间复杂度为O(nk)，空间复杂度为O(k)
 *   注意到，对于一个窗口内的元素，如果一个元素后面有元素比它还大，那么这个元素肯定不可能成为最大元素，因为它肯定比它后面的元素先流出窗口
 *   我们可以用一个双端队列(deque)保存可能成为滑动窗口最大值的元素（deque中的元素是下标递增，值递减）
 *   新来一个元素，我们把deque中超出窗口范围的元素删除（因为该元素已经不再窗口内）
 *                 然后把小于当前元素的值也删除（因为前面的元素一定并当前元素先出窗口，如果它们还小于当前元素，那他们永远也不可能成为最大元素）
 * 时间复杂度：O(n)
 * 空间复杂度：O(k)
 */
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> result;
        if (size <= 0 || num.size() < size) {
            return result;
        }
        deque<int> maxIndex;
        for (int i = 0; i < size; i++) {
            while(!maxIndex.empty() && num[maxIndex.back()] < num[i]) {
                maxIndex.pop_back();
            }
            maxIndex.push_back(i);
        }
        result.push_back(num[maxIndex[0]]);
        for (int i = size; i < num.size(); i++) {
            if (i - maxIndex[0] >= size) {
                maxIndex.pop_front();
            }
            while (!maxIndex.empty() && num[maxIndex.back()] < num[i]) {
                maxIndex.pop_back();
            }
            maxIndex.push_back(i);
            result.push_back(num[maxIndex[0]]);
        }
        return result;
    }
};

void testSolution() {
    vector<int> num = {2,3,4,2,6,2,5,1};
    int size = 3;
    Solution sol;
    vector<int> result = sol.maxInWindows(num, size);
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    testSolution();
    return 0;
}

