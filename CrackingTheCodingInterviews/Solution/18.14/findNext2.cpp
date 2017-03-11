/*! Author: qwchen
 *! Date  : 2017-03-11
 *! 栈：18.14.2 下一个较大元素II
 *! 题目描述：
 *    现在有一个数组，请找出数组中每个元素的“后面比它大的最小的元素”，若不存在则为-1。
 *    给定一个int数组A及数组的大小n，请返回每个元素所求的值组成的数组。保证A中元素为正整数，且n小于等于1000。
 *  测试样例：[11,13,10,5,12,21,3],7
 *  返回：[12,21,12,12,21,-1,-1]
 */

/*
 * 思路：
 *   用一棵二叉查找树，可以快速的查找大于当前元素的最小元素。二叉查找树插入和查找的时间复杂度都为O(logn)
 *   从后往前遍历数组，对于数组的每一元素：
 *     - 如果二叉查找树中存在第一个大于当前元素的元素，将该元素作为当前元素的下一个元素；
 *       否则，当前元素的下一个元素为-1
 *     - 将当前元素插入到二叉查找树
 * 时间复杂度：O(nlogn)。数组只遍历一遍，对于每一个元素都要查找和插入二叉查找树。
 * 空间复杂度：O(n)。结果数组大小和二叉查找树的大小。
 */
class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        vector<int> res(n, -1);
        set<int> binarySearchTree;
        binarySearchTree.insert(A[n-1]);
        for (int i = n-2; i >= 0; i--) {
            auto it = binarySearchTree.upper_bound(A[i]); // upper_bound可以从二叉查找树中找到第一个大于当前元素的元素
            if (it != binarySearchTree.end()) {
                res[i] = *it;
            }
            binarySearchTree.insert(A[i]);
        }
        return res;
    }
};

