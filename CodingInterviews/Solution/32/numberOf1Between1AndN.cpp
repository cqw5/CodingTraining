/*! Author: qwchen
 *! Date  : 2016-11-21
 *  32. 整数中1出现的次数（从1到n整数中1出现的次数）
 * 此题有一个非常巧妙的解法，见https://leetcode.com/discuss/44281/4-lines-o-log-n-c-java-python，时间复杂度为logn
 */

#include <iostream>

using namespace std;

/*
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int numberOf1Between1AndN(int n) {
        int count = 0;
    	for (int i = 1; i <= n; i++) {
            int num = i;
            while (num != 0) {
                if (num % 10 == 1) {
                    count++;
                }
                num /= 10;
            }
        }
        return count;
    }
};


void testSolution() {
	Solution sol;
	cout << sol.numberOf1Between1AndN(12) << endl;
	cout << sol.numberOf1Between1AndN(21345) << endl;
}

int main() {
	testSolution();
	return 0;
}