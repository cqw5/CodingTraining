/*! Author: qwchen
 *! Date  : 2017-02-24
 *! 查找与排序：11.3 搜索旋转数组
 *! 题目描述：
 *    有一个排过序的数组，包含n个整数，但是这个数组向左进行了一定长度的移位，
 *    例如，原数组为[1,2,3,4,5,6]，向左移位5个位置即变成了[6,1,2,3,4,5],现在对于移位后的数组，需要查找某个元素的位置。
 *    请设计一个复杂度为log级别的算法完成这个任务。
 *    给定一个int数组A，为移位后的数组，同时给定数组大小n和需要查找的元素的值x，请返回x的位置(位置从零开始)。保证数组中元素互异。
 */

/*
 * 思路：
 *   找到数组原来的起点，拆成两部分，就变成了两个有序的数组，再从两个有序的数组中查找元素x就是一个简单的二分查找问题。
 *   现在题目就转化成从寻找旋转数组的第一个元素的问题。
 * 时间复杂度：O(logn)
 * 空间复杂度：O(1)
 */
class Finder {
public:
    int findElement(vector<int> A, int n, int x) {
        int nextFirst = findNextFirst(A, n);
        int pos1 = binarySearch(A, 0, nextFirst - 1, x);
        if (pos1 != -1) return pos1;
        int pos2 = binarySearch(A, nextFirst, n - 1, x);
        if (pos2 != -1) return pos2;
        return -1;
    }

private:
    int findNextFirst(vector<int> &A, int n) {
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (A[mid] > A[mid + 1]) return mid + 1;
            if (A[mid] < A[low])     high = mid;
            if (A[mid] > A[high])    low = mid + 1;
        }
        return low;
    }
    
    int binarySearch(vector<int> &A, int low, int high, int x) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (x > A[mid]) low = mid + 1;
            else if (x < A[mid]) high = mid - 1;
            else return mid;
        }
        return -1;
    }
};

