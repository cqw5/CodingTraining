/*! Source: https://leetcode.com/problems/missing-number
 *! Author: qwchen
 *! Date  : 2017-04-23
 *  缺失的数
 *  给定一个长度为n的，包含元素0, 1, 2, ..., n的的数组
 */

/*
 * 如果原始数组未排序，使用XOR的方法
 * 思路：
 *   两个同样的数异或的结果为0
 *   长度为n的数组，其下标为0,1,2,...,n-1，其中的值为0,1,2,...,n中缺一个
 *   如果让n与全部下标和值XOR，那么最终留下的就去缺少的那个值
 * 时间复杂度：O(n). 23 ms. beats 73.23% of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};

/*
 * 如果原始数组是排序的，使用二分查找的方法
 * 思路：
 *   如果mid == nums[mid]，说明<=mid的部分都存在，缺少的元素一定在>mid中
 *   否则mid != nums[mid]，缺少的元素在<=mid中
 * 时间复杂度：O(logn)
 * 空间复杂度: O(1)
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.size() != nums.back()) return nums.back() + 1;
        int low = 0, high = nums.size() - 1, mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (nums[mid] == mid) low = mid + 1;
            else                  high = mid;
        }
        return low;
    }
};

