/*! Author: qwchen
 *! Date  : 2016-11-23
 *  38. 数字在排序数组中出现的次数
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 二分查找，找到k的位置，然后分别向前向后查找与k相等的值的个数。
 * 时间复杂度：O(logn)
 */
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.size() == 0) {
            return 0;
        }
        int low = 0;
        int high = data.size() - 1;
        int mid = 0;
        while(low <= high) {
            mid = (low + high) / 2;
            if (data[mid] < k) {
                low = mid + 1;
            }
            else if (data[mid] > k) {
                high = mid - 1;
            }
            else {
                break;
            }
        }
        int count = 0;
        if (data[mid] == k) {
            for (int i = mid - 1; data[i] == k; i--) {
                count++;
            }
            for (int j = mid; data[j] == k; j++) {
                count++;
            }
        }
        return count;
    }
};


void testSolution() {
    vector<int> a = {1,2,3,4,5,5,5,5,5,5,5,5,5,6,7,8,9};
    Solution sol;
    cout << sol.GetNumberOfK(a, 5) << endl;
}

int main() {
    testSolution();
    return 0;
}