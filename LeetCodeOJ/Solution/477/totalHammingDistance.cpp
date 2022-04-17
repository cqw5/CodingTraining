/*! Source: https://leetcode-cn.com/problems/total-hamming-distance/
 *! Author: qwchen
 *! Date  : 2022-04-17
 *  汉明距离总和
 */

/*
 * 思路：
 *   https://leetcode-cn.com/problems/total-hamming-distance/solution/yi-ming-ju-chi-zong-he-by-leetcode-solut-t0ev/
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < 30; i++) {
            int c = 0;
            for (int num: nums) {
                c += (num >> i) & 1;
            }
            res += c * (n - c);
        }
        return res;
    }
};