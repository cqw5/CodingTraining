/*! Author: qwchen
 *! Date  : 2016-11-25
 *  41. 和为S的两个数字
 *  Solution2为该文件最佳Solution
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
 * 思路：
 *   使用一个hash表存储所有的元素，然后对于数组中的每一个元素i，通过查找hash表判断j是否在数组中
 *   但是该方法没有利用数组是递增的，已经排好序这个特性
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Solution1 {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        int len = array.size();
        if (len == 0 || array[0] * 2 >= sum || array[len-1] * 2 <= sum) {
            return result;
        }
        unordered_set<int> dict;
        for (int i = 0; i < len; i++) {
            dict.insert(array[i]);
        }
        for (int i = 0; i < len; i++) {
            int first = array[i];
            int second = sum - first;
            if (first != second && dict.find(second) != dict.end()) {
                result.push_back(first);
                result.push_back(second);
                break;
            }
        }
        return result;
    }
};

/*
 * 思路：
 *   重复利用数组已经是排好序的特点，左右夹逼来寻找两个数
 * 时间复杂度：O(n)
 * 时间复杂度：O(1)
 */
class Solution2 {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        int len = array.size();
        if (len == 0 || array[0] * 2 >= sum || array[len-1] * 2 <= sum) {
            return result;
        }
        int i = 0,
            j = len - 1;
        while (i != j) {
            if (array[i] + array[j] < sum) {
                i++;
            } 
            else if (array[i] + array[j] > sum) {
                j--;
            }
            else {
                result.push_back(array[i]);
                result.push_back(array[j]);
                break;
            }
        }
        return result;
    }
};


void testSolution(){
    vector<int> array = {2,3,4,5,6,7,8,10,12,15};
    int sum = 15;
    vector<int> result;
    Solution1 sol1;
    result = sol1.FindNumbersWithSum(array, sum);
    cout << result[0] << " " << result[1] << endl;
    Solution1 sol2;
    result = sol2.FindNumbersWithSum(array, sum);
    cout << result[0] << " " << result[1] << endl;
}

int main(){
    testSolution();
    return 0;
}