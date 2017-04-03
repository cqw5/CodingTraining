/*! Source: https://leetcode.com/problems/jump-game
 *! Author: qwchen
 *! Date  : 2017-04-03
 *  跳跃游戏
 */

/*
 * 思路：
 *   从头开始往后走：
 *     i表示当前位置
 *     maxIndex表示能走到的最远位置
 *     last表示最后的位置
 *   如果maxIndex >= last（即能走到last位置），返回true
 *   如果i > maxIndex，说明i没法往后走了，也没有到达last，返回false
 * 时间复杂度：O(n): 12ms. beats 62.89% of cpp submissions.
 * 空间复杂度：O(1):
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int last = nums.size() - 1;
        int maxIndex = 0;
        for (; maxIndex < last && i <= maxIndex; i++) {  // i一步一步往后走
            maxIndex = max(i + nums[i], maxIndex);       // 更新所能到达的最远位置
        }
        return maxIndex >= last;
    }
};


/*
 * 思路：
 *   用一个数据结构set来表示当前步所能走到的位置（下标）（用set是为了去重）
 *   从起点开始，确定从当前步所能走到的位置；
 *     如果所能走到的位置包含了终点，返回true
 *     如果走到的位置还未能包含终点，继续从新的位置往下走
 *         为了避免重复，当前走到的位置的下标要大于上一步所能走到的最大下标
 *   需要有一个标记上一步所能走到的最大下标
 *   需要两个set，一个存放当前能走到的位置（下标）set，一个存放下一步能走到的位置（下标）newSet；
 *       并用newSet来更新set，当newSet为空时，退出，返回false  
 * 时间复杂度：O(n)：22ms. beats 7.36% of cpp submissions.
 * 空间复杂度：O(n)
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;  // 没有元素
        if (nums.size() == 1) return true;   // 只有一个元素，那起始点就是终点
        int last = nums.size() - 1;
        unordered_set<int> set;
        set.insert(0);
        int lastMaxStep = 0;
        while (!set.empty()) {
            unordered_set<int> newSet; // newSet中的最小元素必须大于set中的最大元素
            int newLastMaxStep = 0;
            for (int index: set) {
                for (int i = nums[index]; i > 0; i--) { // 从后往前，结合后面的break可以提前停止
                    int newIndex = index + i;
                    if (newIndex == last) return true; 
                    if (newIndex <= lastMaxStep) break; // 确保当前走到的位置的下标要大于上一步所能走到的最大下标
                    if (newIndex < last && nums[newIndex] != 0) { // 如果没有越界，并且下一步的位置对应的值不为0
                        newSet.insert(newIndex);
                        if (newIndex > newLastMaxStep) {
                            newLastMaxStep = newIndex;
                        }
                    }
                }
            }
            set = newSet;
            lastMaxStep = newLastMaxStep;
        }
        return false;
    }
};

