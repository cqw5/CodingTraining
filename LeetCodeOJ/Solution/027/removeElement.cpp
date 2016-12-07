/*! Source: https://leetcode.com/problems/remove-element/
 *! Author: qwchen
 *! Date  : 2016-12-07
 * Solution 为该文件最优的方案
 * test数据只用于测试是否语法错误，完整的测试见LeetCode。
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 思路：
 *   考虑到从数组中间删除一个元素的时间复杂度为O(n),而删除末尾元素的时间复杂度为O(1)
 *   考虑到本题可以修改数组元素的顺序
 *   因此，遍历一遍数组，并不断的将待删除元素与数组末尾第一个与待删除元素不同的元素交换位置，使得将待删除元素放到数组末尾
 *   最后待删除的元素都在数组末尾，直接从数组末尾删除元素即可
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len <= 0) {
            return 0;
        }
        int low = 0;
        int high = len - 1;
        while (low <= high) {
            if (nums[low] == val) {
                swap(nums[low], nums[high]);
                high--;
            }
            else {
                low++;
            }
        }
        for (int i = len - high -1; i > 0; i--) {
            nums.pop_back();
        }
        return high + 1;
    }
};


void testSolution() {
    vector<int> nums = {3,2,2,3};
    int val = 3;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    Solution sol;
    int len = sol.removeElement(nums, val);
    cout << len << endl;
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    testSolution();
    return 0;
}

