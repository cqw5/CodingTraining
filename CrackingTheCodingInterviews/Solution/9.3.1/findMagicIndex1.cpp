/*! Author: qwchen
 *! Date  : 2017-02-18
 *! 递归和动态规划: 9.3 魔术索引I
 *  题目描述
 *    在数组A[0..n-1]中，有所谓的魔术索引，满足条件A[i]=i。
 *    给定一个升序数组，元素值各不相同，编写一个方法，判断在数组A中是否存在魔术索引。请思考一种复杂度优于o(n)的方法。
 *    给定一个int数组A和int n代表数组大小，请返回一个bool，代表是否存在魔术索引。
 */

/*
 * 思路：
 *   这是一个有序数组，要达到优于O(n)的时间复杂度，可以采用二分查找（画图有助于理解）
 *   如果mid的值小于mid的index，那么mid的左边肯定不存在魔术索引，魔术索引只可能存在于右边
 *   如果mid的值大于mid的index，那么mid的左边肯定不存在魔术索引，魔术索引只可能存在于左边
 * 时间复杂度：O(logn)
 * 空间复杂度：O(1)
 */
class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
		if (A.size() == 0 || n <= 0) return false;
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] < mid)      low = mid + 1;
            else if (A[mid] > mid) high = mid - 1;
            else                   return true;
        }
        return false;
    }
};

