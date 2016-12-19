/*! Source: https://leetcode.com/problems/string-to-integer-atoi/
 *! Author: qwchen
 *! Date  : 2016-12-19
 *  将字符串转化为整数：
 *    '1' -> 1
 *    '   001' -> 1
 *    '  +001' -> 1
 *    ' -1'    -> -1
 *    '111.11' -> 111
 *    '112%s123' -> 112
 *    '1111111111111111111' -> INT_MAX
 *    '-111111111111111111' -> INT_MIN
 *   即，先去除前面的空字符，剩下的如果第一个是‘-’则表示负数，否则为正数，
 *       上溢出时返回INT_MAX，下溢出时返回INT_MIN，遇到非法字符退出返回当前已经转化的值
 */

class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        int i = 0;
        int flag = 1;
        int result = 0;
        // 去除前面空格
        while (i < len && str[i] == ' ') { 
            i++;
        }
        if (i == len) { 
            return 0;
        }
        if (str[i] == '+' || str[i] == '-') {
            flag = 1 - 2 * (str[i] == '-');
            i++;
        }
        while (i < len && str[i] >= '0' && str[i] <= '9') {
            int tail = str[i] - '0';
            // 溢出的情况
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && tail > INT_MAX % 10)) {
                if (flag == 1) return INT_MAX;
                else           return INT_MIN;
            }
            result = result * 10 + tail;
            i++;
        }
        return flag * result;
    }
};


