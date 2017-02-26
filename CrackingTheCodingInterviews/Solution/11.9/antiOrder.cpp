/*! Author: qwchen
 *! Date  : 2017-02-26
 *! 查找与排序：11.9 数组中的逆序对
 *! 题目描述：
 *    有一组数，对于其中任意两个数组，若前面一个大于后面一个数字，则这两个数字组成一个逆序对。
 *    请设计一个高效的算法，计算给定数组中的逆序对个数。
 *    给定一个int数组A和它的大小n，请返回A中的逆序对个数。保证n小于等于5000。
 */

/*
 * 思路：
 *   此题如果使用暴力解法，对于每一个数，遍历其前面所有数，计数所有小于等于它的数的个数，程序非常简单，但是时间复杂度为O(n^2)
 *   借鉴归并排序的过程，每一次merge过程中都会都前后两个已经排序的子数组进行比较，这是如果发现右边的数组的A[j]<左边的A[i]，
 *   那么A[j]也会小于A[i:mid]，此时计数num+=mid-i+1
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 */
class AntiOrder {
public:
    int count(vector<int> A, int n) {
        vector<int> B(n);
        int num = 0;
        sort(A, B, 0, n-1, num);
        return num;
    }
    
private:
    void sort(vector<int> &A, vector<int> &B, int low, int high, int &num) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        sort(A, B, low, mid, num);
        sort(A, B, mid+1, high, num);
        merge(A, B, low, mid, high, num);
    }
    
    void merge(vector<int> &A, vector<int> &B, int low, int mid, int high, int &num) {
        int i = low, j = mid+1, k = low;
        while (i <= mid && j <= high) {
            if (A[i] <= A[j]) {
                B[k++] = A[i++];
            }
            else {
                num += mid - i + 1;
                B[k++] = A[j++];
            }
        }
        while (i <= mid) B[k++] = A[i++];
        while (j <= high) B[k++] = A[j++];
        for (int i = low; i <= high; i++) {
            A[i] = B[i];
        }
    }
};

