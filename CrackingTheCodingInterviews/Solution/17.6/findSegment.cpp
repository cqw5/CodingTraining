/*! Author: qwchen
 *! Date  : 2017-03-11
 *! 排序和查找：17.6 最小调整有序
 *! 题目描述：
 *    有一个整数数组，请编写一个函数，找出索引m和n，只要将m和n之间的元素排好序，整个数组就是有序的。
 *    注意：n-m应该越小越好，也就是说，找出符合条件的最短序列。
 *    给定一个int数组A和数组的大小n，请返回一个二元组，代表所求序列的起点和终点。
 *    (原序列位置从0开始标号,若原序列有序，返回[0,0])。保证A中元素均为正整数。
 */

/*
 * 思路：
 *   如果要找的是两个索引，这表明数组中间有一段是待排序的，其中数组开头和末尾部分都是排好序的
 *   如：1,2,4,7,10,11,7,12,6,7,16,18,19
 *     左边：1,2,4,7,10,11
 *     中间：7,12
 *     右边：6,7,16,18,19
 *   即对于数组A[0:n-1]，将其分为A[0:i],A[i+1:j-1],A[j:n-1]，其中A[0:i]和A[j:n-1]都是非递减有序的
 *   我们要做的就是从A[i:j]中找到min和max元素，将其放到合适的位置，则其合适的位置就是要找的m和n
 *   具体就是：
 *   1. 找到i和j
 *   2. 从中间A[i:j]中找出最小元素midMin和最大元素midMax。主要是A[i:j]而不是A[i+1:j-1]，
 *      因为有序的A[0:i]的A[i]可能大于后面的所有元素，A[j:n-1]的A[j]可能小于前面的所有元素
 *   3. 在A[0:i]之间找到适合放入midMin的位置m，在A[j:n-1]之间找到适合放入midMax的位置n
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Rearrange {
public:
    vector<int> findSegment(vector<int> A, int n) {
        vector<int> res(2, 0);
        int i = 0, j = n - 1;
        while (i < n-1 && A[i] <= A[i+1]) {
            i++;
        }
        if (i == n-1) {
            return res;
        }
        while (j > 0 && A[j] >= A[j-1]) {
            j--;
        }
        int midMin = i+1;
        int midMax = j-1;
        for (int k = midMin; k <= j; k++) {
            if (A[k] < A[midMin]) {
                midMin = k;
            }
        }
        for (int k = midMax; k >= i; k--) {
            if (A[k] > A[midMax]) {
                midMax = k;
            }
        }
        while (i >= 0 && A[i] > A[midMin]) {
            i--;
        }
        while (j < n && A[j] < A[midMax]) {
            j++;
      }
        res[0] = i+1;
        res[1] = j-1;
        return res;
    }
};

