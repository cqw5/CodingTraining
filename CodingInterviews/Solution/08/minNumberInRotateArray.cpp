/*! Author: qwchen
 *! Date  : 2016-11-10
 * 8：旋转数组的最小数字
 * 思想：对原本有序或者部分有序的数组进行查找时，不需要从头到尾遍历，使用二分查找的方法可以实现在logn的时间复杂度下完成查找
 *       在旋转数组中，一个数组被分为两个递增序列，第一个序列中每个元素都大于等于第二个序列中的每个元素，第二个递增序列的首元素就是要找的最小数字。
 *       用low指向数组的首元素，high指向数组的尾元素，mid = (low + high) / 2
 *       如果a[low] <= a[mid]，说明mid在第一个序列中，也就是a[low: mid]之间不会有最小元素，因此让low跳到mid处。low始终指向第一个序列。
 *       如果a[high] >= a[mid]，说明mid在第二个序列中，也就是a(mid: high]之间不会有最小元素，因此让high跳到mid处。high始终指向第二个序列。
 *       最终low将指向第一个序列的最后一个元素，high将指向第二个序列的第一个元素，即两个元素相邻时，此时第二个指针指向的刚好是最小的元素。
 *       以上分析是在数组中没有重复元素的前提下：如果出现a[low] == a[mid] == a[high]，这是就不知道应该改变low还是改变high了；
 *       对于这种情况，只能遍历搜索从low指针到high指针之间的最小元素了
 * 时间复杂度：O(logn)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int>& rotateArray) {
        // 数组为空
        if (rotateArray.size() == 0){
            throw new range_error("array must be not null");
        }
        // 数组长度为1
        if (rotateArray.size() == 1){
            return rotateArray[0];
        }
        int low = 0;
        int high = rotateArray.size() - 1;
        int mid = 0;
        while(low < high){
            mid = (low + high) / 2;
            // 刚好找到
            if (rotateArray[mid] > rotateArray[mid+1]) {
                return rotateArray[mid+1];
            }
            // 这种情况只能从头到尾遍历了
            if (rotateArray[low] == rotateArray[mid] && rotateArray[high] == rotateArray[mid]){
                return minNumber(rotateArray, low, high);        
            }
            if (rotateArray[mid] <= rotateArray[high]) {
                high = mid
            }
            // 到这里rotateArray[mid]肯定不会等于rotateArray[low]，不然就是rotateArray[low] == rotateArray[mid] == rotateArray[high]了
            if (rotateArray[mid] > rotateArray[low]) { 
                low = mid + 1;
            }
        }
        return rotateArray[low];
    }

private:
    int minNumber(vector<int>& rotateArray, int low, int high){
        for (int i = low; i < high; i++) {
            if (rotateArray[i] > rotateArray[i+1]) {
                return rotateArray[i+1];                
            }
        }
        return rotateArray[low];
    }
};

void testSolution(){
    vector<vector<int>> array = {
        {3, 4, 5, 1, 2}, // min 1
        {1, 1, 1, 0, 1}  // min 0
    };
    Solution sol;
    for (auto a: array){
        cout << sol.minNumberInRotateArray(a) << endl;
    }
}

int main(){
    testSolution();
    return 0;
}

