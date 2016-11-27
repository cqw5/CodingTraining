/*! Author: qwchen
 *! Date  : 2016-11-27
 *  51. 数组中重复的数字
 *  题目描述
 *      在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
 *      请找出数组中任意一个重复的数字。 
 *      例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。
 */

#include <iostream>
#include <unordered_set>
#include <climits>

using namespace std;

/*
 * 思路：使用hash表来解决
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 * 另外如果先排序再遍历，时间复杂度为：O(nlogn)，空间复杂度为O(1)
 * 下面是使用hash表的实现
 */
class Solution1 {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (length <= 1) {
            return false;
        }
        unordered_set<int> set;
        for (int i = 0; i < length; i++) {
            if (set.find(numbers[i]) != set.end()) {
                *duplication = numbers[i];
                return true;
            }
            else {
                set.insert(numbers[i]);
            }
        }
        return false;
    }
};

/*
 * 思路：
 *     考虑到，数字都在0 ~ n-1的范围内，如果不存在重复元素，那么排序后的结果有 i = numbers[i]
 *     从第一个元素开始，调整数组，将numbers[i]放到适合的位置(numbers[numbers[i]])，如果出现numbers[i] == numbers[numbers[i]]，则出现重复元素
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution2 {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (length <= 1) {
            return false;
        }
        for (int i = 0; i < length; i++) {
            if (numbers[i] <0 || numbers[i] >= length) {
                return false;
            }
        }
        for (int i = 0; i < length; i++) {
            while(i != numbers[i]) {
                if (numbers[i] == numbers[numbers[i]]) {
                    *duplication = numbers[i];
                    return true;
                }
                else {
                    swap(numbers[i], numbers[numbers[i]]);
                }
            }
        }
        return false;
    }
};

void testSolution() {
    int a1[7] = {2,3,1,0,2,5,3};
    int a2[7] = {2,3,1,0,2,5,3};
    Solution1 sol1;
    Solution2 sol2;
    int duplicate_elem = INT_MAX;
    int *sol1_elem = &duplicate_elem;
    int *sol2_elem = &duplicate_elem;
    if (sol1.duplicate(a1, 7, sol1_elem)) {
        cout << *sol1_elem << endl;
    }
    else {
        cout << "a1 don't exist duplicate" << endl;
    }
    if (sol1.duplicate(a2, 7, sol2_elem)) {
        cout << *sol2_elem << endl;
    }
    else {
        cout << "a1 don't exist duplicate" << endl;
    }
}

int main() {
    testSolution();
    return 0;
}