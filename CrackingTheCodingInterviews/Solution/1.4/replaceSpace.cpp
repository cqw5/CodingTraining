/*! Author: qwchen
 *! Date  : 2016-12-31
 *! 字符串与数组: 1.4
 *！题目描述
 *    请编写一个方法，将字符串中的空格全部替换为“%20”。
 *    假定该字符串有足够的空间存放新增的字符，并且知道字符串的真实长度(小于等于1000)，同时保证字符串由大小写的英文字母组成。
 *！测试样例：
 *    “Mr John Smith”,13
 *    返回："Mr%20John%20Smith"
 *    “Hello  World”,12
 *    返回：”Hello%20%20World”
 */

#include <iostream>

using namespace std;

/*
 * 思路：
 *   1. 遍历字符串，统计空格的个数
 *   2. 从后向前，将字符从原位置复制到新位置。如果为空格，则替换为%20，否则复制该字符
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    void replaceSpace(char str[], int length) {
        if (str == NULL || length <= 0) return;
        int k = 0;  // k表示空格的个数
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') k++;
        }
        int i = length;     // i 指向原始字符串的最后一个元素'\0'
        int j = i + 2 * k;  // j 指向新字符串的最后一个元素'\0'
        while (k > 0) {
            if (str[i] == ' ') {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
                k--;
            }
            else {
                str[j--] = str[i];
            }
            i--;
        }
    }
};

void testSolution() {
    char str[] = "Mr John Smith";
    cout << str << endl;
    Solution sol;
    sol.replaceSpace(str, 13);
    cout << str << endl;
}

int main () {
    testSolution();
    return 0;
}

