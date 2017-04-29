/*! Source: https://leetcode.com/problems/jump-game-ii
 *! Author: qwchen
 *! Date  : 2017-4-29
 *  跳步游戏
 *    有一个数组，数组每个元素的值表示从当前结点出发下一步能走的最远距离。求从第一个到最后一步所需要的最少步数。
 */

/*
 * 思路：
 *   要使得从nums[0]走到nums[n-1]的步数最小，就需要每一步尽可能远
 *   用curMax表示当前能走到的最远距离；nextMax表示下一步能走到的最远距离。
 *   用i从头到尾走每一步
 *   用count来记录步数
 *   如果curMax<i，表示卡住了，没法往前走了
 * 时间复杂度：O(n). 12 ms. beats 74.21 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int count = 0;
        int curMax = nums[0];
        int nextMax = 0;
        int i = 0;
        int last = nums.size() - 1;
        while (curMax >= i) {
            count++;
            if (curMax >= last) return count;
            for (; i <= curMax; i++) {
                nextMax = max(nextMax, i + nums[i]);
            }
            curMax = nextMax;
        }
        return -1;
    }
};

