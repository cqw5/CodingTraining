/*! Author: qwchen
 *! Date  : 2016-12-03
 *  64. 数据流中的中位数
 *  题目描述
 *    如何得到一个数据流中的中位数？
 *    如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 *    如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 *  可以在内存中保存所有的流元素
 */

/*
 * 思路：
 *   如果用一个数组来保存流元素
 *       那么插入元素时只需往数组尾部插入，时间复杂度为O(1)
 *       但是寻找中位数时，时间复杂度为O(n)
 *   考虑平衡二叉搜索树的结构，其左右子树的高度差不超过1，如果我们修改为左右子树的元素量差不超过1
 *       那么当左右子树元素个数相等时，中位数为根节点，
 *       当左子树元素多时，中位数根节点和左子树的最大值的平均，
 *       当右子树元素多时，中位数根节点和右子树的最小值的平均，
 *       这个过程的时间复杂度为O(logn)，平衡二叉搜索树插入结点的时间复杂度为O(logn)
 *   借鉴平衡二叉搜索树的结构，我们使用一个大顶堆和一个小顶堆分布模拟平衡二叉树的左右子树，大顶堆的最大值小于等于小顶堆的最小值
 *       新来一个元素时，若其小于等于大顶堆的最大值，将其放到大顶堆，否则放到小顶堆，并保证大顶堆的元素个数比小顶堆多一个或者相等，
 *       这样新来一个元素，只需要将其放到堆中，时间复杂度为O(logn)
 *       当大顶堆和小顶堆元素个数相等时，中位数为大顶堆最大值和小顶堆最小值的平均；否则，就是大顶堆的元素比小顶堆多一个，中位数为大顶堆的最大值。
 *       因此从查找中位数的时间复杂度只为O(1)
 *       下面是这种方法的实现
 */
class Solution {
public:
    void Insert(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }
        if (maxHeap.size() == minHeap.size() + 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (maxHeap.size() + 1 == minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double GetMedian() { 
        if (maxHeap.empty() && minHeap.empty()) {
            return 0.0;
        }
        if (maxHeap.size() == minHeap.size()) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        else {
            return 1.0 * maxHeap.top();
        }
    }

private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

