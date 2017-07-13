/*! Source: https://leetcode.com/problems/summary-ranges
 *! Author: qwchen
 *! Date  : 2016-7-14
 *  总结数据范围
 *    给定一个递增排序的数组（元素没重复），返回他范围的总结。
 *    如[0,1,2,4,5,7], 返回["0->2","4->5","7"].
 */

/*
 * 思路：
 *   从头到尾遍历元素，如果下一个元素等于当前元素+1，那么下一个元素和当前元素就在同一个范围内；否则不再一个范围内。
 *   需要注意有些范围只有一个数。
 * 时间复杂度：O(N). beats 36.95 % of cpp submissions.
 * 空间复杂度：O(K). 
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0) return res;
        int low = 0, high = 0;
        while (high < nums.size() - 1) {
            if(nums[high] + 1 == nums[high+1]) {
                high++;
            }
            else {
                if(low < high) {
                    res.push_back(to_string(nums[low]) + "->" + to_string(nums[high]));
                }
                else {
                    res.push_back(to_string(nums[low]));
                }
                high++;
                low = high;
            }
        }
        if(low < high) {
            res.push_back(to_string(nums[low]) + "->" + to_string(nums[high]));
        }
        else {
            res.push_back(to_string(nums[low]));
        }
        return res;
    }
};

