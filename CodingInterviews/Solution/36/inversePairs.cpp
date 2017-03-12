/*! Author: qwchen
 *! Date  : 2016-11-22
 *  36. 数组中的逆序对
 *  输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。即输出P%1000000007。测试样本太大，int类型会溢出。 
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 思路：
 *   借鉴归并排序的思想，归并左右两个从小到大排序的数组，对左边数组的每一个元素，计算加上右边数组中值小于其的元素的个数。
 *   在归并时，用指针i指向左边数组的最后一个元素，用指针j指向右边数组的最后一个元素
 *   如果a[i] > a[j]，说明a[i]与右边数组每一个元素都可以构成逆序对，则逆序对的个数加上右边元素的个数；同时把a[i]从后往前归并到b数组中,让i--
 *   如果a[i] < a[j]，说明a[i]不能与a[j]构成逆序对，将a[j]从后往前归并到b数组中，让j--
 * 因为整个过程就是归并排序的过程，则：
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    int InversePairs(vector<int> data) {
        vector<int> b(data.size());
        long long count = 0;
        sort(data, b, 0, data.size()-1, count);
        return count % 1000000007;
    }

private:
    void sort(vector<int>& a, vector<int>& b, int low, int high, long long& count) {
        if (low >= high) {
            return;
        }
        int mid = (low + high) / 2;
        sort(a, b, low, mid, count);
        sort(a, b, mid+1, high, count);
        merge(a, b, low, mid, high, count);
    }
    void merge(vector<int> &a, vector<int> &b, int low, int mid, int high, long long &count) {
        int i = low, j = mid+1, k = low;
        while (i <= mid && j <= high) {
            if (a[i] <= a[j]) {
                b[k++] = a[i++];
            }
            else {
                count += mid - i + 1; // 最关键的一行，如果A[i]大于A[j]，那所有大于A[i]的也大于A[j]
                b[k++] = a[j++];
            }
        }
        while (i <= mid)  b[k++] = a[i++];
        while (j <= high) b[k++] = a[j++];
        for (int i = low; i <= high; i++) {
            a[i] = b[i];
        }
    }
    /*
    void merge(vector<int>& a, vector<int>& b, int low, int mid, int high, long long& count) {
        int i = mid,
            j = high,
            k = high;
        while (i >= low && j >= mid+1) {
            if (a[i] > a[j]) {
                count += j - mid;
                b[k--] = a[i--];
            }
            else if (a[i] < a[j]) {
                b[k--] = a[j--];
            }
        }
        while (i >= low) {
            b[k--] = a[i--];
        }
        while (j >= mid+1) {
            b[k--] = a[j--];
        }
        for (int i = low; i <= high; i++) {
            a[i] = b[i];
        }
    } 
    */
};


void testSolution() {
    vector<int> arr = {7, 5, 6, 4};
    Solution sol;
    cout << sol.InversePairs(arr) << endl;
}

int main() {
    testSolution();
    return 0;
}