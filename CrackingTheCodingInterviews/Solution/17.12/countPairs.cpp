/*! Author: qwchen
 *! Date  : 2017-03-10
 *! 编程基础: 17.12 整数对查找
 *  题目描述
 *    请设计一个高效算法，找出数组中两数之和为指定值的所有整数对。
 *    给定一个int数组A和数组大小n以及需查找的和sum，请返回和为sum的整数对的个数。保证数组大小小于等于3000。
 */

/*
 * 思路：
 *   如果没有重复元素，本题就是像leeCode上简单的2Sum题目，可以直接用hash来解决。
 *   但在有重复元素的情况下，本题先对数组进行排序，然后使用夹逼法，同时注意考虑重复元素的处理。
 *     i指向第一个元素，j指向最后一个元素，curSum表示A[i] + A[j]
 *     (1) curSum == sum
 *        a. 如果A[i] == A[j]，说明A[i]到A[j]之间的元素都相等了，则可能组合是A[i]到A[j]之间两两任意组合：n(n-1)/2
 *           之后就退出，不用找了
 *        b. 否则，数出A[i]及其之后多少个等于A[i](假设m个)，和A[j]及其之后多少等于A[j](假设n个)，则：m*n，
 *           之后，让i指向A[i]后第一个不等于A[i]的元素，让j指向A[j]前第一个不等于A[j]的元素
 *     (2) curSum > sum, 说明curSum太大，让大的A[j]往前走一步
 *     (3) curSum < sum, 说明curSum太小，让小的A[i]往后走一步
 *     如果i>=j了，就不需要再查找了
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(1)
 */
class FindPair {
public:
    int countPairs(vector<int> A, int n, int sum) {
        int count = 0;
        sort(A.begin(), A.end());
        int i = 0;
        int j = A.size() - 1;
        int curSum = 0;
        while (i < j) {
            curSum = A[i] + A[j];
            if (curSum < sum) {
                i++;
            }
            else if (curSum > sum) {
                j--;
            }
            else {
                if (A[i] == A[j]) {
                    int n = j - i + 1;
                    count += n * (n - 1) / 2;
                    break;
                }
                int low = i;
                int high = j;
                while (A[i] == A[i + 1]) i++;
                while (A[j] == A[j - 1]) j--;
                i++;
                j--;
                count += (i - low) * (high - j);
            }
        }
        return count;
    }
};

