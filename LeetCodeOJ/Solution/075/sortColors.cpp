/*! Source: https://leetcode.com/problems/sort-colors/
 *! Author: qwchen
 *! Date  : 2016-12-11
 *  颜色排序
 */

/*
 * 思路：
 *   只是3种颜色的排序，可以遍历数组一轮，如果当前是0则换到前面，如果当前是2则换到后面，如果当前是1则放在中间。
 * 时间复杂度：O(n). 3 ms. beats 26.32 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, i = 0;
        while (i <= high) {
            if (nums[i] == 0 && i > low) swap(nums[low++], nums[i]);
            else if (nums[i] == 2 && i < high) swap(nums[high--], nums[i]);
            else i++;
        }
    }
};



/*
 * 思路：箱子排序
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        queue<int> bin[3];
        for (int i = 0; i < nums.size(); i++) {
            bin[nums[i]].push(nums[i]);
        }
        int i = 0;
        for (int j = 0; j < 3; j++) {
            while(!bin[j].empty()) {
                nums[i++] = bin[j].front();
                bin[j].pop();
            }
        }
    }
};

/*
 * 思路：三向切分快速排序
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int lt = 0,
            mid = 0,
            gt = nums.size() - 1;
        while (mid <= gt) {
            if (nums[mid] < 1)      swap(nums[lt++], nums[mid++]);
            else if (nums[mid] > 1) swap(nums[gt--], nums[mid]);
            else                    mid++;
        }
    }
};

