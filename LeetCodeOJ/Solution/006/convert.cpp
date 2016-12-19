/*! Source: https://leetcode.com/problems/zigzag-conversion/
 *! Author: qwchen
 *! Date  : 2016-12-19
 * 字符串菱形打印
 */

/*n=numRows
  Δ=2n-2    1                           2n-1                         4n-3
  Δ=        2                     2n-2  2n                    4n-4   4n-2
  Δ=        3               2n-3        2n+1              4n-5       .
  Δ=        .           .               .               .            .
  Δ=        .       n+2                 .           3n               .
  Δ=        n-1 n+1                     3n-3    3n-1                 5n-5
  Δ=2n-2    n                           3n-2                         5n-4
*/

/*
 * 思路：
 *   创建numRows个vector来保存字符，遍历数组，交替自上而下填充菱形的垂直部分，再自下而上填充菱形的倾斜部分。
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if (len == 0 || numRows <= 1) {
            return s;
        } 
        vector<vector<char>> mat(numRows);
        int i = 0;
        while (i < len){
            // 自上而下填充菱形的垂直部分
            for (int j = 0; j < numRows && i < len; i++, j++) {
                mat[j].push_back(s[i]);
            }
            // 自下而上填充菱形的倾斜部分
            for (int j = numRows - 2; j > 0 && i < len; i++, j--) {
                mat[j].push_back(s[i]);
            }
        }
        int k = 0;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                s[k++] = mat[i][j];
            }
        }
        return s;
    }
};

