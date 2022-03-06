/*! Author: qwchen
 *! Date  : 2016-11-23
 *  38. 数字在排序数组中出现的次数
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 先用二分查找找出数组中第一个等于target的数，之后再遍历找所有等于target的数。
 * 时间复杂度：O(logn)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int count = 0;
        if(nums.size() <= 0) return count;
        int low = 0, high = nums.size()-1, mid = 0;
        while (low < high) {
            mid = (low + high) / 2;
            if (target > nums[mid]) low = mid+1;
            // 下面1行可以表示为：
            // else if (target < nums[mid]) high = mid - 1;
            // else                    high = mid;
            else                    high = mid; 
        }
        for(int i=low; i < nums.size(); i++) {
            if(nums[i] == target) count++;
            else                  break;
        }
        return count;
    }
};


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