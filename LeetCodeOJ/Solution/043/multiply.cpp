/*! Source: https://leetcode.cn/problems/multiply-strings/
 *! Author: qwchen
 *! Date  : 2022-09-04
 *  大数乘法
 */


/* 最优解法：
 * 思路：https://leetcode.cn/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/
 *   x位的数字与y位的数字的乘积结果最多有x+y位。
 *  10^x位于10^y位相乘的结果放在10^(x+y)位中，如个位与个位相乘的结果放在个位，十位与十位相乘的结果放在百位
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(m*n)
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string res = "";
        int m = num1.size(), n = num2.size();
        vector<int> ans(m+n, 0);
        for (int i = m-1; i >= 0; i--) {
            int n1 = num1.at(i) - '0';
            for (int j = n-1; j >= 0; j--) {
                int n2 = num2.at(j) - '0';
                ans[i+j+1] += n1 * n2;
            }
        }
        for (int i = m+n-1; i >= 0; i--) {
            ans[i-1] += ans[i] / 10;
            ans[i] = ans[i] % 10;
        }
        int index = ans[0] == 0 ? 1: 0;
        while (index < m+n) {
            res.push_back(ans[index++] + '0');
        }
        return res;
    }
};

/*
 * 思路：https://leetcode.cn/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/
 * 时间复杂度：O(m*n + n*n)
 * 空间复杂度：O(m*n)
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string res = "";
        for (int i = num2.size()-1; i >= 0; i--) {
            string temp = "";
            int add = 0;
            for (int j = num2.size()-1; j > i; j--) {
                temp.push_back(0);
            }
            int n2 = num2.at(i) - '0';
            for (int j = num1.size()-1; j >= 0; j--) {
                int n1 = num1.at(j) - '0';
                int product = n1 * n2 + add;
                temp.push_back(product % 10);
                add = product / 10;
            }
            if (add > 0) {
                temp.push_back(add);
            }
            reverse(temp.begin(), temp.end());
            for (auto &c: temp) {
                c = c + '0';
            }
            res = addString(res, temp);
        }
        return res;
    }

    string addString(string &num1, string &num2) {
        string res = "";
        int i = num1.size()-1;
        int j = num2.size()-1;
        int add = 0;
        while (i >=0 || j >= 0 || add > 0) {
            int n1 = i >= 0 ? num1.at(i) - '0': 0;
            int n2 = j >= 0 ? num2.at(j) - '0': 0;
            int sum = n1 + n2 + add;
            res.push_back(sum % 10);
            add = sum / 10;
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        for (auto &c: res){
            c = c + '0';
        }
        return res;
    }
};

