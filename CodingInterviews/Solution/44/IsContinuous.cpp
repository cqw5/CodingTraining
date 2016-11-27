/*! Author: qwchen
 *! Date  : 2016-11-27
 *  44. 扑克牌顺子
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 思路：
 *   长度为5的数组时顺子的话，需要满足两个条件：最大值 - 最小值 < 5; 不能有重复元素
 *   先对数组进行排序，这样的话，0会被排在最前面，这样两个条件就很容易判断了
 * 时间复杂度：该题数组长度是固定为5，时间复杂度是O(nlogn)还是O(n)都没有什么差别
 */
class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        if (numbers.size() != 5) {
            return false;
        }
        sort(numbers.begin(), numbers.end());
        int i = 0, j = numbers.size()-1;
        while(numbers[i] == 0) {
            i++;
        }
        if (numbers[j] - numbers[i] >= 5) {
            return false;
        }
        while(i < j) {
           if (numbers[i] == numbers[i+1]) {
               return false;
           }
           i++; 
        }
        return true;
    }
};

void testSolution() {
    Solution sol;
    vector<int> numbers1 = {1,3,2,5,4};
    vector<int> numbers2 = {1,0,2,0,4};
    cout << sol.IsContinuous(numbers1) << endl;
    cout << sol.IsContinuous(numbers2) << endl;
}

int main() {
    testSolution();
    return 0;
}