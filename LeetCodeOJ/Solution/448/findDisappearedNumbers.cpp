/*! Source: https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
 *! Author: qwchen
 *! Date  : 2022-04-20
 *  找到所有数组中消失的数字
 */

/*
 * 思路：
 *   将数组每一个元素放到自己合适的位置（即A[i] == i+1的位置），如果发现重复元素就把重复的元素设置为0
 *   当每个元素被放到合适的位置之后，剩下的没有被放的位置就是缺失的元素。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != 0 && nums[i] != i+1) {
                if (nums[i] == nums[nums[i]-1]) {
                    nums[i] = 0;
                } else {
                    swap(nums[i], nums[nums[i]-1]);
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};