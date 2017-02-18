/*! Author: qwchen
 *! Date  : 2017-02-18
 *! 递归和动态规划: 9.3 魔术索引II
 *  题目描述
 *    在数组A[0..n-1]中，有所谓的魔术索引，满足条件A[i]=i。
 *    给定一个不下降序列，元素值可能相同，编写一个方法，判断在数组A中是否存在魔术索引。请思考一种复杂度优于o(n)的方法。
 *    给定一个int数组A和int n代表数组大小，请返回一个bool，代表是否存在魔术索引。
 */

/*
 * 思路：
 *   这是一个有序数组，要达到优于O(n)的时间复杂度，可以采用二分查找（画图有助于理解）
 *   相比前一题，这里的元素有重复
 *   先比较的mid的value和index是否相同，若相同，直接返回true，否则：
 *   搜索左半部分：从low 到 min(mid_value, mid-1)
 *   搜索右半部分：从max(mid+1, mid_value) 到 high
 *   若左或右存在魔法索引，返回true；否则返回false
 * 时间复杂度：O(logn)
 * 空间复杂度：O(1)
 */
class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
		if (A.size() == 0 || n <= 0) return false;
        return findMagicIndex(A, 0, n - 1);
    }
 
private:
    bool findMagicIndex(vector<int> &A, int low, int high) {
        if (low > high) return false;
        int mid = (low + high) / 2;
        if (A[mid] == mid) return true;
        if (findMagicIndex(A, low, min(A[mid], mid - 1)))  return true;
        if (findMagicIndex(A, max(A[mid], mid + 1), high)) return true;
        return false;
    }
};


