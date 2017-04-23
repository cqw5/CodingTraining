/*! Source: https://leetcode.com/problems/ugly-number-ii
 *! Author: qwchen
 *! Date  : 2017-04-23
 *  丑数II
 */

/*
 * 时间复杂度: O(n). 6 ms. beats 48.49% of cpp submissions.
 * 空间复杂度: O(n)
 */

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 1) return 1;
        vector<int> ugly = {1};
        int index2 = 0, index3 = 0, index5 = 0;
        while (--n != 0) {
            while (ugly[index2] * 2 <= ugly.back()) index2++;
            while (ugly[index3] * 3 <= ugly.back()) index3++;
            while (ugly[index5] * 5 <= ugly.back()) index5++;
            ugly.push_back(min(min(ugly[index2] * 2, ugly[index3] * 3), ugly[index5] * 5));
        }
        return ugly.back();
    }
};


