/*! Source: https://leetcode.com/problems/container-with-most-water
 *! Author: qwchen
 *! Date  : 2017-4-29
 *  能装最多水的容器
 *    给定n个非负的整数a1 a2 an，代表来二维平面的上点(i, ai)。
 *    画n条垂直于x轴的线段，其两个端点分布为(i, 0)和(i, ai)。
 *    需要寻找两条线，使得这两条线和x轴构成的容器能装下更多的水。
 */

/* 
 * 思路：
 *   先选择第一和最后一列构成容器。对于其他的列构成的容器，因为其宽会比之前的小，因此必须更高才可能构成容量更大的容器。
 * 时间复杂度：O(n). 19 ms. beats 48.85 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        if (height.size() < 2) return res;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            res = max(res, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return res;
    }
};

