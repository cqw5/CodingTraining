/*! Author: qwchen
 *! Date  : 2017-02-24
 *! 查找与排序：11.5 找出字符串
 *! 题目描述：
 *    有一个排过序的字符串数组，但是其中有插入了一些空字符串，请设计一个算法，找出给定字符串的位置。
 *    算法的查找部分的复杂度应该为log级别。
 *    给定一个string数组str,同时给定数组大小n和需要查找的string x，请返回该串的位置(位置从零开始)。
 */

/*
 * 思路（推荐）
 *   此题是二分查找的变形，多了一些空字符串。
 *   还是应用二分查找的方法，但是当str[mid]==""时，我们要寻找mid左右最近的一个非空的字符串，让mid指向那个字符串
 * 时间复杂度：O(logn)
 * 空复复杂度：O(1)
 */
class Finder {
public:
    int findString(vector<string> str, int n, string x) {
        if (n <= 0) return -1;
        return find(str, x, 0 , n-1);
    }

private:
    int find(vector<string> str, string x, int first, int last) {
        int mid;
        while (first <= last) {
            mid = (first + last) / 2;
            // 若mid为空字符串，寻找离它最近的非空字符串
            if (str[mid] == "") {
                int low  = mid - 1;
                int high = mid + 1;
                while (true) {
                    if (low < first && high > last) {
                        return -1;
                    }
                    else if (low >= first && str[low] != "") {  // 寻找左边
                        mid = low;
                        break;
                    }
                    else if (high <= last && str[high] != "") { // 寻找右边
                        mid = high;
                        break;
                    }
                    low--;
                    high++;
                }
            }
            if (x < str[mid])      last = mid - 1;
            else if (x > str[mid]) first = mid + 1;
            else                   return mid;
        }
        return -1;
    }
};


/*
 * 思路：
 *   此题是二分查找的变形，多了一些空字符串。
 *   但是当str[mid] == ""时，我们无法判断目标是在mid的左边还是右边
 *   因此当遇到str[mid] == ""时，我们用tempMid来存放当前mid的位置，然后从mid位置开始向左寻找第一个!=""位置
 *       如果左移到low之前就找到!=""的位置，那么后续就根据这个位置的值来判断目标是在mid的左边还是右边
 *       如果找到low的位置了，左边不在有了，那么就判断low是否为目标；若是，则返回。
 *   如果str[mid]>x，说明目标值在mid的左边，让high=mid-1，并左移到第一个!=""的位置
 *   如果str[mid]<x，说明目标值在mid的右边，让low=mid+1，并右移到第一个!=""的位置
 ****左移、右移的时候，非常注意数组下标越界问题
 * 时间复杂度：O(logn)
 * 空间复杂度：O(1)
 */
class Finder {
public:
    int findString(vector<string> str, int n, string x) {
        int low = 0, high = n - 1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            int tempMid = mid;
            while (str[mid] == "" && mid > low) {
                mid--;
            }
            if (mid == low && str[mid] == x) {
                return mid;
            }
            if (str[mid] == "") {
                low = tempMid + 1;
                continue;
            }
            if (x > str[mid]) {
                low = tempMid + 1;
                while (low <= high && str[low] == "") {
                    low++;
                }
            }
            else if (x < str[mid]) {
                high = mid - 1;
                while (low <= high && str[high] == "") {
                    high--;
                }
            }
            else return mid;
        }
        return -1;
    }
};

