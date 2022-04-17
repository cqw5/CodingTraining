/*! Source: https://leetcode-cn.com/problems/permutations/
 *! Author: qwchen
 *! Date  : 2022-04-17
 *  全排列
 */

/*
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        permuteHelp(nums, 0, nums.size());
        return res;
    }
private:
    vector<vector<int>> res;
    void permuteHelp(vector<int>& nums, int k, int n) {
        if (k == n) {
            res.push_back(nums);
        } else {
            for (int i = k; i < n; i++) {
                swap(nums[k], nums[i]);
                permuteHelp(nums, k+1, n);
                swap(nums[k], nums[i]);
            }
        }      
    }
};

