/*! Author: qwchen
 *! Date  : 2016-11-27
 *  45. 孩子们的游戏(圆圈中最后剩下的数)
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 思路：
 *   对不断对数据进行遍历，每次删除被选中的元素，直到数组长度为1时，剩下的元就是最后留下来的元素
 * 时间复杂度：O(nm)，每一轮，查找第m个元素的时间复杂度为O(1),删除元素的时间复杂度为O(m)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n < 1 || m < 1) {
            return -1;
        }
        vector<int> numbers;
        for (int i = 0; i < n; i++) {
            numbers.push_back(i);
        }
        int current = 0;
        while(numbers.size() > 1) {
            current = (current + m - 1) % numbers.size();  // 对数组长度取模取模
            numbers.erase(numbers.begin() + current);
        }
        return numbers[0];
    }
};

void testSolution() {
    int n = 5, m = 3;
    Solution sol;
    cout << sol.lastRemaining(n, m) << endl;
}

int main() {
    testSolution();
    return 0;
}