/*! Source: https://leetcode.com/problems/restore-ip-addresses
 *! Author: qwchen
 *! Date  : 2017-04-10
 *  字符串转化为IP地址
 */

/* 
 * 思路：
 *   注意到字符串的长度在 4 <= size <= 12时，才可能转化为IP地址
 *   将字符串分为几个段，每个段的长度 1 <= size <= 3
 *   每一个段转化为整数后，值必须 <= 255
 *   最后还需要注意，加上3个"."转化为IP地址后，len(IP) = len(str) + 3
 * 时间复杂度：3ms. beats 16.10% of cpp submissions
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 4 || s.size() > 12) return res;
        for (int a = 1; a <= 3; a++) {
            for (int b = 1; b <= 3; b++) {
                for (int c = 1; c <= 3; c++) {
                    for (int d = 1; d <= 3; d++) {
                        if (a + b + c + d == s.size()) {
                            int A = stoi(s.substr(0, a));
                            int B = stoi(s.substr(a, b));
                            int C = stoi(s.substr(a+b, c));
                            int D = stoi(s.substr(a+b+c, d));
                            if (A < 256 && B < 256 && C < 256 && D < 256) {
                                string ip = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
                                if (ip.size() == s.size() + 3) {
                                    res.push_back(ip);
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

